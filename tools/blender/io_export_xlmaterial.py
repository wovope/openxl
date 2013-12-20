# -*- coding: utf-8 -*-

# xl: blender xl material exporter
# Copyright (C) 2012, 2013 Juan Manuel Borges Caño

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

# cp io_export_xlmaterial.py ~/.config/blender/$version/scripts/startup

import bpy, datetime, mathutils, math

def export_xlmaterial(context, filepath, use_some_setting):

	scene = bpy.context.scene
	world = scene.world
	material = bpy.context.active_object.active_material

	stream = open(filepath, 'w')

	# Metadata

	stream.write('type material\n')
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

	# Properties

	stream.write('properties 1\n')
	stream.write('name default\n')
	stream.write('image %s\n' % material.active_texture.name)
	stream.write('alpha %s\n' % material.alpha)
	ambient = material.ambient * world.ambient_color
	stream.write('ambient %s %s %s\n' % (ambient[0], ambient[1], ambient[2]))
	stream.write('diffuse %s %s %s\n' % (material.diffuse_color[0], material.diffuse_color[1], material.diffuse_color[2]))
	stream.write('specular %s %s %s\n' % (material.specular_color[0], material.specular_color[1], material.specular_color[2]))
	stream.write('emission %s %s %s\n' % (material.emit, material.emit, material.emit))
	stream.write('shininess 0.0\n')

	stream.close()

	return {'FINISHED'}

from bpy_extras.io_utils import ExportHelper
from bpy.props import StringProperty

class ExportXLMaterial(bpy.types.Operator, ExportHelper):
	'''Export to XL Material format.'''

	bl_idname = "export.xlmaterial"
	bl_label = "Export XL Material"
	filename_ext = ".xld"
	filter_glob = StringProperty(default = "*.xld", options = {'HIDDEN'})

	@classmethod
	def poll(cls, context):
		return context.active_object != None

	def execute(self, context):
		return export_xlmaterial(context, self.filepath, None)

def menu_func_export(self, context):
	self.layout.operator(ExportXLMaterial.bl_idname, text = "XL Material format (.xld)")

def register():
	bpy.utils.register_class(ExportXLMaterial)
	bpy.types.INFO_MT_file_export.append(menu_func_export)

def unregister():
	bpy.utils.unregister_class(ExportXLMaterial)
	bpy.types.INFO_MT_file_export.remove(menu_func_export)

if __name__ == "__main__":
	register()
	bpy.ops.export.material('INVOKE_DEFAULT')
