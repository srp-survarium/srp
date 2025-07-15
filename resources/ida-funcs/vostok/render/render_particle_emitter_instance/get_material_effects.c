vostok::render::material_effects *__usercall vostok::render::render_particle_emitter_instance::get_material_effects@<eax>(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::enum_vertex_input_type vertex_input_type; // eax
  vostok::render::material_effects_instance *v3; // edx

  vertex_input_type = vostok::render::render_particle_emitter_instance::get_vertex_input_type(this, a2);
  if ( v3 )
    return vostok::render::material_effects_instance::get_material_effects(v3, vertex_input_type);
  else
    return *(vostok::render::material_effects **)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[4 * vostok::render::vertex_input_type_to_index(vertex_input_type) + 4];
}
