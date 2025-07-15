char __usercall vostok::render::res_effect::apply_pass@<al>(vostok::render::res_effect *this@<ecx>, int a2@<eax>)
{
  vostok::render::res_pass *v2; // ecx
  vostok::render::res_pass *v3; // eax
  vostok::render::res_pass *v4; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::res_pass *v6; // edi
  vostok::render::effect_manager *v7; // ecx
  bool v8; // zf

  v2 = *(vostok::render::res_pass **)(a2 + 22048);
  v3 = *(vostok::render::res_pass **)(*(_DWORD *)(a2 + 22052) + 4 * (_DWORD)v2);
  v4 = 0;
  if ( v3 )
  {
    v4 = v3;
    ++v3->m_reference_count;
  }
  m_reference_count = (_DWORD *)v4->m_vs.m_object->m_reference_count;
  v6 = 0;
  if ( m_reference_count )
  {
    v6 = (vostok::render::res_pass *)v4->m_vs.m_object->m_reference_count;
    ++*m_reference_count;
  }
  vostok::render::res_pass::apply(v2, v6);
  if ( v6 )
  {
    v8 = v6->m_reference_count-- == 1;
    if ( v8 )
      vostok::render::effect_manager::delete_pass(
        v7,
        (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
        v6);
  }
  v8 = v4->m_reference_count-- == 1;
  if ( v8 )
    vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v4);
  return 1;
}
