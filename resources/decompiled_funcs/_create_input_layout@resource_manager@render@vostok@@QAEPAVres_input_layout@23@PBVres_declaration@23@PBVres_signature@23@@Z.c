D3D11_INPUT_ELEMENT_DESC *__thiscall vostok::render::resource_manager::create_input_layout(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *decl,
        const vostok::render::res_declaration *signature,
        vostok::render::res_input_layout *new_layout)
{
  vostok::render::res_input_layout *v4; // ebx
  const vostok::render::res_declaration *v5; // eax
  vostok::render::res_input_layout *v6; // ecx
  D3D11_INPUT_ELEMENT_DESC *M_start; // edi
  vostok::render::res_input_layout *v9; // esi
  vostok::render::res_input_layout *v10; // eax
  vostok::render::res_input_layout *v11; // esi
  vostok::render::res_input_layout *__val; // [esp+14h] [ebp-1Ch] BYREF
  vostok::render::res_input_layout descriptor; // [esp+1Ch] [ebp-14h] BYREF

  v4 = new_layout;
  vostok::render::res_input_layout::res_input_layout(
    &descriptor,
    signature,
    (const vostok::render::res_signature *)new_layout);
  new_layout = &descriptor;
  v5 = (const vostok::render::res_declaration *)stlp_std::priv::_Rb_tree<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::res_input_layout *,stlp_std::priv::_Identity<vostok::render::res_input_layout *>,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *>,vostok::render::std_allocator<vostok::render::res_input_layout *>>::_M_find<vostok::render::res_input_layout const *>(
                                                  (stlp_std::priv::_Rb_tree<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::res_input_layout *,stlp_std::priv::_Identity<vostok::render::res_input_layout *>,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *>,vostok::render::std_allocator<vostok::render::res_input_layout *> > *)&new_layout,
                                                  (vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout> *)&decl->m_input_layouts,
                                                  (vostok::render::res_input_layout *const *)&decl->m_input_layouts);
  if ( v5 == (const vostok::render::res_declaration *)&decl->m_input_layouts )
  {
    vostok::render::res_input_layout::~res_input_layout(v6);
    v9 = (vostok::render::res_input_layout *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               0x14u);
    if ( v9 )
    {
      vostok::render::res_input_layout::res_input_layout(v9, signature, (const vostok::render::res_signature *)v4);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    new_layout = v11;
    v11->m_is_registered = 1;
    stlp_std::priv::_Rb_tree<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::res_input_layout *,stlp_std::priv::_Identity<vostok::render::res_input_layout *>,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *>,vostok::render::std_allocator<vostok::render::res_input_layout *>>::insert_unique(
      (stlp_std::priv::_Rb_tree<vostok::render::res_input_layout *,vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>,vostok::render::res_input_layout *,stlp_std::priv::_Identity<vostok::render::res_input_layout *>,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *>,vostok::render::std_allocator<vostok::render::res_input_layout *> > *)&new_layout,
      &decl->m_input_layouts._M_t,
      &__val,
      &new_layout);
    return (D3D11_INPUT_ELEMENT_DESC *)v11;
  }
  else
  {
    M_start = v5->dcl_code._M_impl._M_start;
    vostok::render::res_input_layout::~res_input_layout(v6);
    return M_start;
  }
}
