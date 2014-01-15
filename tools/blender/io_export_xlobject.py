# -*- coding: utf-8 -*-

# xl: blender xl object exporter
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

# cp io_export_xlobject.py ~/.config/blender/$version/scripts/startup

# Objects naming: freely as *the* object, as "Tag.Name" for tag "Name".

import bpy, datetime, mathutils, math

def export_xlobject(context, filepath, use_some_setting):

	scene = bpy.context.scene
	world = scene.world
	object = bpy.context.active_object
	tags = []
	for object in bpy.context.selected_objects:
		if object.name[0:4] == "Tag.":
			tags.append(object)

	stream = open(filepath, 'w')

	# Metadata

	stream.write('type object\n')
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

	# Vertices

	stream.write('vertices %s\n' % len(object.data.vertices))
	for vertex in object.data.vertices:
		co = object.matrix_world * vertex.co
		no = object.matrix_world * vertex.normal
		stream.write('coord %s %s %s\n' % (co.x, co.y, co.z))
		stream.write('normal %s %s %s\n' % (no.x, no.y, no.z))

	# Materials

	faces = []
	for material in object.data.materials:
		faces.append(0)
	for material in object.data.materials:
		for face, uvface in enumerate(object.data.uv_textures.active.data):
			if object.data.materials[object.data.polygons[face].material_index] == material:
				faces[object.data.polygons[face].material_index] += 1
	start = 0
	i = 0
	stream.write('materials %s\n' % len(object.data.materials))
	for material in object.data.materials:
		stream.write('name %s\n' % material.name)
		stream.write('type material\n')
		stream.write('material %s.xld\n' % material.name)
		stream.write('faces %s %s\n' % (start, faces[i]))
		start += faces[i]
		i += 1

	# Faces

	stream.write('faces %s\n' % len(object.data.polygons))
	for material in object.data.materials:
		for face in range(len(object.data.polygons)):
			if object.data.materials[object.data.polygons[face].material_index] == material:
				stream.write('vertices')
				for vertex in object.data.polygons[face].vertices:
					stream.write(' %s' % vertex)
				stream.write('\n')
				stream.write('normal')
				for normal in object.data.polygons[face].normal:
					stream.write(' %s' % normal)
				stream.write('\n')
				stream.write('texcoords')
				for index in object.data.polygons[face].loop_indices:
					stream.write(' %s %s' % (object.data.uv_layers.active.data[index].uv[0], object.data.uv_layers.active.data[index].uv[1]))
				stream.write('\n')

	# Tags (A tag has *one* vertex)

	stream.write('tags %s\n' % len(tags))
	for tag in tags:
		stream.write('name %s\n' % tag.name[4:])
		vertex = tag.data.vertices[0]
		co = tag.matrix_world * vertex.co
		matrix = mathutils.Matrix() * 0.0
		for group in vertex.groups:
			matrix = matrix + (armature.data.bones[tag.vertex_groups[group.group].name].matrix_local * group.weight)
		matrix = mathutils.Matrix.Rotation(math.radians(180), 4, 'Y') * matrix * armature.matrix_world
		#stream.write('matrix %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n' % (matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3], matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3], matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3], co[0], co[1], co[2], matrix[3][3]))  
		stream.write('matrix %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n' % (matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0], matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1], matrix[0][2], matrix[1][2], matrix[2][2],  matrix[3][2],  matrix[0][3],  matrix[1][3],  matrix[2][3],  matrix[3][3]))  

	# Bound

	stream.write('bound\n')
	co = object.matrix_world * ((mathutils.Vector(object.bound_box[0]) + mathutils.Vector(object.bound_box[1]) + mathutils.Vector(object.bound_box[2]) + mathutils.Vector(object.bound_box[3]) + mathutils.Vector(object.bound_box[4]) + mathutils.Vector(object.bound_box[5]) + mathutils.Vector(object.bound_box[6]) + mathutils.Vector(object.bound_box[7])) / 8.0)
	stream.write('sphere %f %f %f %f\n' % (co[0], co[1], co[2], max(object.dimensions) / 2.0))
	stream.write('dimensions %f %f %f\n' % (object.dimensions[0], object.dimensions[1], object.dimensions[2]))

	stream.close()

	return {'FINISHED'}

from bpy_extras.io_utils import ExportHelper
from bpy.props import StringProperty

class ExportXLObject(bpy.types.Operator, ExportHelper):
	'''Export to XL Object format.'''

	bl_idname = "export.object"
	bl_label = "Export XL Object"
	filename_ext = ".xld"
	filter_glob = StringProperty(default = "*.xld", options = {'HIDDEN'})

	@classmethod
	def poll(cls, context):
		return context.active_object != None

	def execute(self, context):
		return export_xlobject(context, self.filepath, None)

def menu_func_export(self, context):
	self.layout.operator(ExportXLObject.bl_idname, text = "XL Object format (.xld)")

def register():
	bpy.utils.register_class(ExportXLObject)
	bpy.types.INFO_MT_file_export.append(menu_func_export)

def unregister():
	bpy.utils.unregister_class(ExportXLObject)
	bpy.types.INFO_MT_file_export.remove(menu_func_export)

if __name__ == "__main__":
	register()
	bpy.ops.export.object('INVOKE_DEFAULT')
