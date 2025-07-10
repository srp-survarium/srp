char __usercall vostok::render::res_effect::apply_pass@<al>(vostok::render::res_effect *this@<ecx>, int a2@<eax>)
{
  vostok::render::res_shader_technique *v2; // eax
  vostok::render::res_shader_technique *v3; // esi
  bool v4; // zf
  vostok::render::res_pass *m_object; // eax
  const vostok::render::res_pass *v7; // edi
  vostok::render::res_xs<vostok::render::gs_data> *v8; // ecx
  vostok::render::res_xs<vostok::render::ps_data> *v9; // ecx

  v2 = *(vostok::render::res_shader_technique **)(*(_DWORD *)(a2 + 280) + 4 * *(_DWORD *)(a2 + 276));
  v3 = 0;
  if ( v2 )
  {
    v3 = v2;
    ++v2->m_reference_count;
  }
  if ( v3->m_passes._M_impl._M_finish - v3->m_passes._M_impl._M_start )
  {
    m_object = v3->m_passes._M_impl._M_start->m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v3->m_passes._M_impl._M_start->m_object;
      ++m_object->m_reference_count;
    }
    vostok::render::res_xs<vostok::render::vs_data>::apply(v7->m_vs.m_object);
    vostok::render::res_xs<vostok::render::gs_data>::apply(v8);
    vostok::render::res_xs<vostok::render::ps_data>::apply(v9);
    vostok::render::res_state::apply(v7->m_state.m_object);
    v4 = v7->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::effect_manager::delete_pass(
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
        v7);
    v4 = v3->m_reference_count-- == 1;
    if ( v4 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v3);
    return 1;
  }
  else
  {
    if ( v3 )
    {
      v4 = v3->m_reference_count-- == 1;
      if ( v4 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v3);
    }
    return 0;
  }
}
