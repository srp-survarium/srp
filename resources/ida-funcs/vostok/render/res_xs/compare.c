int __thiscall vostok::render::res_xs<vostok::render::gs_data>::compare(
        vostok::render::res_xs<vostok::render::vs_data> *this,
        const vostok::render::res_xs<vostok::render::vs_data> *binder,
        const vostok::render::xs_descriptor<vostok::render::vs_data> *bindera)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // eax
  int result; // eax
  vostok::render::res_sampler_list *v5; // ecx

  m_object = binder->m_hardware_shader.m_object;
  if ( bindera->m_hardware_shader.m_object > m_object )
    return -1;
  result = bindera->m_hardware_shader.m_object < m_object;
  if ( !result )
  {
    result = vostok::render::shader_constant_table::compare(
               binder->m_constants.m_object,
               &bindera->m_shader_data.constants);
    if ( !result )
    {
      result = vostok::render::res_texture_list::compare(binder->m_textures.m_object, &bindera->m_shader_data.textures);
      if ( !result )
        return vostok::render::res_sampler_list::compare(
                 v5,
                 (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)binder->m_samplers.m_object);
    }
  }
  return result;
}
