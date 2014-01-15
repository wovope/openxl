# -*- coding: utf-8 -*-

# xl: blender xl model exporter
# Copyright (C) 2012 - 2014 Juan Manuel Borges Caño

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# cp io_export_xlmodel.py ~/.config/blender/$version/scripts/startup

# Objects naming: freely as *the* model, as "Tag.Name" for tag "Name".
# The model and the tags have to share the same armature.

import bpy, datetime, mathutils, math, os

def export_xlmodel(context, filepath, use_some_setting):

	scene = bpy.context.scene
	world = scene.world
	model = bpy.context.active_object
	tags = []
	for object in bpy.context.selected_objects:
		if object.name[0:4] == "Tag.":
			tags.append(object)
	armature = model.find_armature()
	bonemap = {}
	for bone in range(len(armature.data.bones)):
		bonemap[armature.data.bones[bone].name] = bone

	stream = open(filepath, 'w')

	# Metadata

	stream.write('type model\n')
	stream.write('name \n')
	stream.write('version \n')
	stream.write('author \n')
	stream.write('date %s\n' % datetime.date.today())
	stream.write('copyright \n')
	stream.write('license \n')
	stream.write('url \n')
	stream.write('email \n')
	stream.write('tool blender - a 3D modelling and rendering package\n')
	stream.write('comment Plain export not reviewed\n')
	stream.write('xl 0.0.136\n')

	# Object

	stream.write('object %s\n' % os.path.basename(filepath))

	# Bones
	
	start = 0
	stream.write('bones %s\n' % len(armature.data.bones))
	for bone in armature.data.bones:
		parents = bone.parent_recursive
		stream.write('name %s\n' % bone.name)
		stream.write('parents %s %s\n' % (start, len(parents)))
		start += len(parents)

	# Parents

	stream.write('parents %s\n' % start)
	for bone in armature.data.bones:
		parents = bone.parent_recursive
		for parent in parents:
			stream.write('bone %s\n' % bonemap[parent.name])

	# Vertices

	weights = 0
	stream.write('vertices %s\n' % len(model.data.vertices))
	for vertex in model.data.vertices:
		co = model.matrix_world * vertex.co
		no = model.matrix_world * vertex.normal
		stream.write('weights %s %s\n' % (weights, len(vertex.groups)))
		weights += len(vertex.groups)

	# Tags (A tag has *one* vertex)

	stream.write('tags %s\n' % len(tags))
	for tag in tags:
		stream.write('name %s\n' % tag.name[4:])
		vertex = tag.data.vertices[0]
		stream.write('weights %s %s\n' % (weights, len(vertex.groups)))
		weights += len(vertex.groups)

	# Weights

	stream.write('weights %s\n' % weights)
	if weights:
		for vertex in model.data.vertices:
			for group in vertex.groups:
				stream.write('weight %s %s\n' % (bonemap[model.vertex_groups[group.group].name], group.weight))
		for tag in tags:
			vertex = tag.data.vertices[0]
			for group in vertex.groups:
				stream.write('weight %s %s\n' % (bonemap[tag.vertex_groups[group.group].name], group.weight))

	# Frames

	frames = 0
	actionbkp = armature.animation_data.action
	framebkp = scene.frame_current
	for nla_track in armature.animation_data.nla_tracks:
		for strip in nla_track.strips:
			frames += int(strip.action_frame_end - strip.action_frame_start) + 1
	stream.write('frames %s\n' % frames)

	prevmatrix = mathutils.Matrix(armature.matrix_world)
	#prevmatrix = mathutils.Matrix()
	for nla_track in armature.animation_data.nla_tracks:
		for strip in nla_track.strips:
			armature.animation_data.action = strip.action
			for frame in range(int(strip.action_frame_start), int(strip.action_frame_end) + 1):
				scene.frame_set(frame)
				for bone in armature.pose.bones:
					matrix = bone.matrix * armature.data.bones[bone.name].matrix_local.inverted() * armature.matrix_world
					stream.write('matrix %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n' % (matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0], matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1], matrix[0][2], matrix[1][2], matrix[2][2],  matrix[3][2],  matrix[0][3],  matrix[1][3],  matrix[2][3],  matrix[3][3]))  
				matrix = armature.matrix_world * prevmatrix.inverted()
				stream.write('matrix %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n' % (matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0], matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1], matrix[0][2], matrix[1][2], matrix[2][2],  matrix[3][2],  matrix[0][3],  matrix[1][3],  matrix[2][3],  matrix[3][3]))  
				prevmatrix = mathutils.Matrix(armature.matrix_world)
				stream.write('time %f\n' % (1.0 / scene.render.fps))
	armature.animation_data.action = actionbkp
	scene.frame_set(framebkp)

	# Actions

	actions = 0
	for nla_track in armature.animation_data.nla_tracks:
		actions += len(nla_track.strips)

	stream.write('actions %s\n' % actions)
	frame = 0
	for nla_track in armature.animation_data.nla_tracks:
		for strip in nla_track.strips:
			stream.write('name %s\n' % strip.action.name)
			frames = int(strip.action_frame_end - strip.action_frame_start) + 1
			stream.write('frames %s %s\n' % (frame, frames))
			frame += frames

	stream.close()

	return {'FINISHED'}

from bpy_extras.io_utils import ExportHelper
from bpy.props import StringProperty

class ExportXLModel(bpy.types.Operator, ExportHelper):
	'''Export to XL Model format.'''

	bl_idname = "export.model"
	bl_label = "Export XL Model"
	filename_ext = ".xld"
	filter_glob = StringProperty(default = "*.xld", options = {'HIDDEN'})

	@classmethod
	def poll(cls, context):
		return context.active_object != None

	def execute(self, context):
		return export_xlmodel(context, self.filepath, None)

def menu_func_export(self, context):
	self.layout.operator(ExportXLModel.bl_idname, text = "XL Model format (.xld)")

def register():
	bpy.utils.register_class(ExportXLModel)
	bpy.types.INFO_MT_file_export.append(menu_func_export)

def unregister():
	bpy.utils.unregister_class(ExportXLModel)
	bpy.types.INFO_MT_file_export.remove(menu_func_export)

if __name__ == "__main__":
	register()
	bpy.ops.export.model('INVOKE_DEFAULT')
