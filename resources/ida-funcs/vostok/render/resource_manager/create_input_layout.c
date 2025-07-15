stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::render::resource_manager::create_input_layout(
        vostok::render::resource_manager *this,
        stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_input_layout *,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *> >,bool> *decl,
        const vostok::render::res_declaration *signature,
        const vostok::render::res_signature *signaturea)
{
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_input_layout *,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *> >,bool> *v4; // edi
  vostok::render::res_input_layout *v5; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_node; // edi
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  stlp_std::set<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::std_allocator<vostok::render::res_input_layout *> > *v11; // ecx
  char *v12; // esi
  const vostok::render::res_signature *v13; // eax
  const vostok::render::res_signature *v14; // esi
  const char *v15; // [esp+0h] [ebp-2Ch]
  const char *v16; // [esp+4h] [ebp-28h]
  unsigned int v17; // [esp+8h] [ebp-24h]
  vostok::render::res_input_layout v18; // [esp+Ch] [ebp-20h] BYREF
  char v19[4]; // [esp+20h] [ebp-Ch] BYREF
  vostok::render::res_input_layout *__x; // [esp+24h] [ebp-8h] BYREF

  vostok::render::res_input_layout::res_input_layout(&v18, signature, signaturea);
  __x = &v18;
  v4 = (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_input_layout *,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *> >,bool> *)((char *)decl + (_DWORD)&loc_93914 + 4);
  stlp_std::set<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::std_allocator<vostok::render::res_input_layout *>>::find<vostok::render::res_input_layout *>(
    &__x,
    (stlp_std::set<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::std_allocator<vostok::render::res_input_layout *> > *)((char *)decl + (_DWORD)&loc_93914 + 4),
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_input_layout *,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *> > *)&decl);
  if ( decl == v4 )
  {
    vostok::render::res_input_layout::~res_input_layout(
      v5,
      (vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)&v18);
    v8 = vostok::render::g_allocator;
    v9 = type_info::raw_name(&vostok::render::res_input_layout `RTTI Type Descriptor');
    v12 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x14u, v9, v15, v16, v17);
    if ( v12 )
    {
      vostok::render::res_input_layout::res_input_layout((vostok::render::res_input_layout *)v12, signature, signaturea);
      signaturea = v13;
    }
    else
    {
      signaturea = 0;
    }
    v14 = signaturea;
    LOBYTE(signaturea[1].m_signature) = 1;
    stlp_std::set<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::std_allocator<vostok::render::res_input_layout *>>::insert(
      v11,
      (int)v19,
      v4,
      (vostok::render::res_input_layout **)&signaturea);
    return (stlp_std::priv::_Rb_tree_node_base *)v14;
  }
  else
  {
    M_node = decl[2].first._M_node;
    vostok::render::res_input_layout::~res_input_layout(
      v5,
      (vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)&v18);
    return M_node;
  }
}
