int __fastcall vostok::render::compare(const vostok::render::res_pass *right, const vostok::render::res_pass *left)
{
  vostok::render::res_state *m_object; // eax
  vostok::render::res_state *v3; // esi
  int result; // eax
  vostok::render::res_xs<vostok::render::ps_data> *v5; // eax
  vostok::render::res_xs<vostok::render::ps_data> *v6; // esi
  vostok::render::res_xs<vostok::render::vs_data> *v7; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v8; // esi
  vostok::render::res_xs<vostok::render::gs_data> *v9; // eax
  vostok::render::res_xs<vostok::render::gs_data> *v10; // esi
  vostok::render::res_input_layout *v11; // edx
  vostok::render::res_input_layout *v12; // ecx

  m_object = left->m_state.m_object;
  v3 = right->m_state.m_object;
  if ( v3 > m_object )
    return -1;
  result = v3 < m_object;
  if ( !result )
  {
    v5 = left->m_ps.m_object;
    v6 = right->m_ps.m_object;
    if ( v6 > v5 )
      return -1;
    result = v6 < v5;
    if ( result )
      return result;
    v7 = left->m_vs.m_object;
    v8 = right->m_vs.m_object;
    if ( v8 > v7 )
      return -1;
    result = v8 < v7;
    if ( result )
      return result;
    v9 = left->m_gs.m_object;
    v10 = right->m_gs.m_object;
    if ( v10 > v9 )
      return -1;
    result = v10 < v9;
    if ( result )
      return result;
    v11 = left->m_input_layout.m_object;
    v12 = right->m_input_layout.m_object;
    if ( v12 > v11 )
      return -1;
    result = v12 < v11;
    if ( v12 >= v11 )
      return 0;
  }
  return result;
}
