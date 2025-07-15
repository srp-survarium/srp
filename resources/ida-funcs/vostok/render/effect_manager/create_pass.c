vostok::render::res_xs<vostok::render::ps_data> *__userpurge vostok::render::effect_manager::create_pass@<eax>(
        vostok::render::effect_manager *this@<ecx>,
        int a2@<eax>,
        const vostok::render::res_pass *pass)
{
  const vostok::render::res_pass *v3; // ebx
  int v4; // esi
  vostok::render::res_pass *v5; // edi
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // ecx
  const vostok::render::res_pass *v11; // eax
  const vostok::render::res_pass *v12; // ebx
  stlp_std::priv::_Rb_tree_node_base v13; // [esp-4h] [ebp-20h]
  const char *v14; // [esp+0h] [ebp-1Ch]
  const char *v15; // [esp+4h] [ebp-18h]
  unsigned int v16; // [esp+8h] [ebp-14h]
  _BYTE v17[12]; // [esp+10h] [ebp-Ch] BYREF

  v3 = pass;
  v4 = *(_DWORD *)(a2 + 18200);
  v5 = (vostok::render::res_pass *)(a2 + 18196);
  pass = (const vostok::render::res_pass *)(a2 + 18196);
  if ( v4 )
  {
    do
    {
      if ( vostok::render::compare(v3, *(const vostok::render::res_pass **)(v4 + 16)) < 0 )
      {
        v4 = *(_DWORD *)(v4 + 12);
      }
      else
      {
        pass = (const vostok::render::res_pass *)v4;
        v4 = *(_DWORD *)(v4 + 8);
      }
    }
    while ( v4 );
    if ( pass != v5 && vostok::render::compare((const vostok::render::res_pass *)pass->m_ps.m_object, v3) < 0 )
      pass = v5;
  }
  if ( pass != v5 )
    return pass->m_ps.m_object;
  v7 = vostok::render::g_allocator;
  v8 = type_info::raw_name(&vostok::render::res_pass `RTTI Type Descriptor');
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x1Cu, v8, v14, v15, v16);
  if ( v10 )
  {
    vostok::render::res_pass::res_pass(&v3->m_state, (vostok::render::res_pass *)v10, &v3->m_vs, &v3->m_gs, &v3->m_ps);
    pass = v11;
  }
  else
  {
    pass = 0;
  }
  v12 = pass;
  *(_DWORD *)&v13._M_color = &pass;
  pass->m_registered = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *> > *)v10,
    (int)v17,
    (stlp_std::priv::_Rb_tree<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass>,vostok::render::res_pass *,stlp_std::priv::_Identity<vostok::render::res_pass *>,stlp_std::priv::_SetTraitsT<vostok::render::res_pass *>,vostok::render::std_allocator<vostok::render::res_pass *> > *)v5,
    v13);
  return (vostok::render::res_xs<vostok::render::ps_data> *)v12;
}
