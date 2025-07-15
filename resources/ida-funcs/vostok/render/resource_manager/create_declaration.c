vostok::render::res_declaration *__thiscall vostok::render::resource_manager::create_declaration(
        vostok::render::resource_manager *this,
        const D3D11_INPUT_ELEMENT_DESC *dcl,
        const D3D11_INPUT_ELEMENT_DESC *count,
        unsigned int counta)
{
  vostok::buffer_vector<vostok::render::signature_layout_pair> *v4; // ecx
  int v5; // esi
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *> > *v11; // ecx
  vostok::render::res_declaration *v12; // eax
  vostok::render::res_declaration *v13; // edi
  stlp_std::priv::_Rb_tree_node_base v14; // [esp-4h] [ebp-123Ch]
  const char *v15; // [esp+0h] [ebp-1238h]
  const char *v16; // [esp+4h] [ebp-1234h]
  unsigned int v17; // [esp+8h] [ebp-1230h]
  vostok::render::res_declaration *__x; // [esp+Ch] [ebp-122Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<vostok::render::res_declaration *,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *> > v19[2]; // [esp+10h] [ebp-1228h] BYREF
  vostok::render::res_declaration v20; // [esp+18h] [ebp-1220h] BYREF

  vostok::render::res_declaration::res_declaration(count, counta, &v20);
  __x = &v20;
  stlp_std::set<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::std_allocator<vostok::render::res_declaration *>>::find<vostok::render::res_declaration *>(
    &__x,
    (stlp_std::set<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::std_allocator<vostok::render::res_declaration *> > *)((char *)&loc_938E8 + (_DWORD)dcl),
    v19);
  if ( v19[0]._M_node == (stlp_std::priv::_Rb_tree_node_base *)((char *)&loc_938E8 + (_DWORD)dcl) )
  {
    v20.dcl_code.m_end = v20.dcl_code.m_begin;
    vostok::buffer_vector<vostok::render::signature_layout_pair>::~buffer_vector<vostok::render::signature_layout_pair>(
      v4,
      (int *)&v20.vs_to_layout);
    v7 = vostok::render::g_allocator;
    v8 = type_info::raw_name(&vostok::render::res_declaration `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x1220u, v8, v15, v16, v17);
    if ( v10 )
    {
      vostok::render::res_declaration::res_declaration(count, counta, (vostok::render::res_declaration *)v10);
      __x = v12;
    }
    else
    {
      __x = 0;
    }
    v13 = __x;
    *(_DWORD *)&v14._M_color = &__x;
    __x->m_is_registered = 1;
    stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *>>::insert_unique(
      v11,
      (int)v19,
      (stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *> > *)((char *)&loc_938E8 + (_DWORD)dcl),
      v14);
    return v13;
  }
  else
  {
    v5 = *(_DWORD *)&v19[0]._M_node[1]._M_color;
    v20.dcl_code.m_end = v20.dcl_code.m_begin;
    vostok::buffer_vector<vostok::render::signature_layout_pair>::~buffer_vector<vostok::render::signature_layout_pair>(
      v4,
      (int *)&v20.vs_to_layout);
    return (vostok::render::res_declaration *)v5;
  }
}
