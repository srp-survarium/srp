vostok::render::material_effects *__usercall vostok::render::render_surface::get_material_effects@<eax>(
        vostok::render::render_surface *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::material_effects_instance *v2; // ecx

  v2 = *(vostok::render::material_effects_instance **)(a2 + 104);
  if ( !v2 || s_use_one_material_value )
    return *(vostok::render::material_effects **)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[4 * vostok::render::vertex_input_type_to_index(*(_DWORD *)(a2 + 148)) + 4];
  else
    return vostok::render::material_effects_instance::get_material_effects(
             v2,
             *(vostok::render::enum_vertex_input_type *)(a2 + 148));
}
