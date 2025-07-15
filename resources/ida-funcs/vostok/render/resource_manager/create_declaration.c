vostok::render::res_declaration *__userpurge vostok::render::resource_manager::create_declaration@<eax>(
        unsigned int count@<eax>,
        vostok::render::resource_manager *this,
        stlp_std::forward_iterator_tag *dcl)
{
  vostok::render::resource_manager *v3; // eax
  vostok::render::res_declaration *v4; // ecx
  unsigned int sl_created; // esi
  vostok::render::res_declaration *v7; // eax
  vostok::render::res_declaration *v8; // esi
  stlp_std::forward_iterator_tag *v9; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *> > *M_node; // eax
  vostok::render::res_declaration *new_decl; // [esp+10h] [ebp-30h] BYREF
  stlp_std::forward_iterator_tag *__formal; // [esp+14h] [ebp-2Ch]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_declaration *,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *> >,bool> result; // [esp+18h] [ebp-28h] BYREF
  vostok::render::res_declaration descriptor; // [esp+20h] [ebp-20h] BYREF

  memset(&descriptor, 0, 28);
  __formal = &dcl[28 * count];
  stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_range_initialize<D3D11_INPUT_ELEMENT_DESC const *>(
    (stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *)__formal,
    &descriptor.dcl_code._M_impl,
    dcl,
    (const D3D11_INPUT_ELEMENT_DESC *)__formal);
  new_decl = &descriptor;
  descriptor.m_is_registered = 0;
  result.first._M_node = &this->m_declarations._M_t._M_header._M_data;
  v3 = (vostok::render::resource_manager *)stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *>>::_M_find<vostok::render::res_declaration const *>(
                                             (const vostok::render::res_declaration **)&new_decl,
                                             &this->m_declarations._M_t);
  if ( v3 == (vostok::render::resource_manager *)&this->m_declarations )
  {
    vostok::render::res_declaration::~res_declaration(v4);
    v7 = (vostok::render::res_declaration *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x20u);
    v8 = v7;
    if ( v7 )
    {
      v9 = __formal;
      v7->m_reference_count = 0;
      v7->vs_to_layout._M_impl._M_start = 0;
      v7->vs_to_layout._M_impl._M_finish = 0;
      v7->vs_to_layout._M_impl._M_end_of_storage._M_data = 0;
      v7->dcl_code._M_impl._M_start = 0;
      v7->dcl_code._M_impl._M_finish = 0;
      v7->dcl_code._M_impl._M_end_of_storage._M_data = 0;
      stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_range_initialize<D3D11_INPUT_ELEMENT_DESC const *>(
        (stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *)v9,
        &v7->dcl_code._M_impl,
        dcl,
        (const D3D11_INPUT_ELEMENT_DESC *)v9);
      v8->m_is_registered = 0;
    }
    else
    {
      v8 = 0;
    }
    M_node = (stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *> > *)result.first._M_node;
    new_decl = v8;
    v8->m_is_registered = 1;
    stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *>>::insert_unique(
      (stlp_std::priv::_Rb_tree<vostok::render::res_declaration *,vostok::render::resource_manager::compare_predicate<vostok::render::res_declaration>,vostok::render::res_declaration *,stlp_std::priv::_Identity<vostok::render::res_declaration *>,stlp_std::priv::_SetTraitsT<vostok::render::res_declaration *>,vostok::render::std_allocator<vostok::render::res_declaration *> > *)&result,
      M_node,
      &result,
      (const vostok::render::res_declaration **)&new_decl);
    return v8;
  }
  else
  {
    sl_created = v3->sl_created;
    vostok::render::res_declaration::~res_declaration(v4);
    return (vostok::render::res_declaration *)sl_created;
  }
}
