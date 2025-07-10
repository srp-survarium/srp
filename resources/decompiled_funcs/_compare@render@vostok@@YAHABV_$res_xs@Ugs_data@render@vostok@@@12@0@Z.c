int __cdecl vostok::render::compare(
        const vostok::render::res_xs<vostok::render::vs_data> *left,
        const vostok::render::res_xs<vostok::render::vs_data> *right)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // ecx
  vostok::render::res_xs_hw<vostok::render::vs_data> *v3; // eax
  int result; // eax

  m_object = right->m_hardware_shader.m_object;
  v3 = left->m_hardware_shader.m_object;
  if ( m_object > v3 )
    return -1;
  result = m_object < v3;
  if ( !result )
  {
    result = vostok::render::shader_constant_table::compare(left->m_constants.m_object, right->m_constants.m_object);
    if ( !result )
    {
      result = vostok::render::res_texture_list::compare(left->m_textures.m_object, right->m_textures.m_object);
      if ( !result )
        return vostok::render::res_sampler_list::compare(left->m_samplers.m_object, right->m_samplers.m_object);
    }
  }
  return result;
}
