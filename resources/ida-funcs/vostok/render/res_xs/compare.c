int __thiscall vostok::render::res_xs<vostok::render::gs_data>::compare(
        vostok::render::res_xs<vostok::render::vs_data> *this,
        const vostok::render::xs_descriptor<vostok::render::vs_data> *binder,
        int a3)
{
  unsigned int v3; // eax
  int result; // eax

  v3 = *(_DWORD *)&binder->m_shader_data.instruction_count;
  if ( *(_DWORD *)a3 > v3 )
    return -1;
  result = *(_DWORD *)a3 < v3;
  if ( !result )
  {
    result = vostok::render::shader_constant_table::compare(
               (vostok::render::shader_constant_table *)binder->m_shader_data.hardware_shader,
               (const vostok::render::shader_constant_table *)(a3 + 12));
    if ( !result )
    {
      result = vostok::render::res_buffer_list::compare(
                 (vostok::render::res_buffer_list *)binder->m_shader_data.constants.m_reference_count,
                 (const vostok::fixed_vector<vostok::render::buffer_slot,128> *)(a3 + 2296));
      if ( !result )
      {
        result = vostok::render::res_buffer_list::compare(
                   (vostok::render::res_buffer_list *)binder->m_shader_data.constants.m_table.m_end,
                   (const vostok::fixed_vector<vostok::render::buffer_slot,128> *)(a3 + 13060));
        if ( !result )
          return vostok::render::res_sampler_list::compare(
                   (vostok::render::res_sampler_list *)binder->m_shader_data.constants.m_table.m_begin,
                   (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)(a3 + 940));
      }
    }
  }
  return result;
}
