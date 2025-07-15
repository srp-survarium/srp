bool __thiscall vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>::operator()(
        vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data> *this,
        const vostok::render::res_xs<vostok::render::vs_data> *const left,
        const vostok::render::res_xs<vostok::render::vs_data> *const right)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // ecx
  vostok::render::res_xs_hw<vostok::render::vs_data> *v4; // eax
  int v5; // eax

  m_object = right->m_hardware_shader.m_object;
  v4 = left->m_hardware_shader.m_object;
  if ( m_object <= v4 )
  {
    v5 = m_object < v4;
    if ( !v5 )
    {
      v5 = vostok::render::shader_constant_table::compare(left->m_constants.m_object, right->m_constants.m_object);
      if ( !v5 )
      {
        v5 = vostok::render::res_texture_list::compare(
               (vostok::render::res_buffer_list *)left->m_textures.m_object,
               (const vostok::render::res_buffer_list *)right->m_textures.m_object);
        if ( !v5 )
        {
          v5 = vostok::render::res_texture_list::compare(left->m_buffers.m_object, right->m_buffers.m_object);
          if ( !v5 )
            v5 = vostok::render::res_sampler_list::compare(left->m_samplers.m_object, right->m_samplers.m_object);
        }
      }
    }
  }
  else
  {
    v5 = -1;
  }
  return v5 < 0;
}
