vostok::render::res_geometry *__thiscall vostok::render::resource_manager::create_geometry(
        vostok::render::resource_manager *this,
        vostok::render::res_declaration *dcl,
        vostok::render::res_declaration *vertex_stride,
        vostok::render::untyped_buffer *vb,
        vostok::render::untyped_buffer *ib,
        vostok::render::untyped_buffer *a6)
{
  _BYTE *v6; // esi
  stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *> > *v7; // edi
  const vostok::render::res_geometry *const *v8; // ebx
  vostok::render::res_geometry *v9; // ebx
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // eax
  stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *> > *v15; // ecx
  vostok::render::res_geometry *v16; // eax
  stlp_std::priv::_Rb_tree_node_base v17; // [esp-4h] [ebp-34h]
  vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry> *v18; // [esp+0h] [ebp-30h]
  const char *v19; // [esp+4h] [ebp-2Ch]
  unsigned int v20; // [esp+8h] [ebp-28h]
  vostok::render::res_geometry *__val; // [esp+Ch] [ebp-24h] BYREF
  _BYTE v22[8]; // [esp+10h] [ebp-20h] BYREF
  vostok::render::res_geometry right; // [esp+18h] [ebp-18h] BYREF

  vostok::render::res_geometry::res_geometry(ib, a6, vertex_stride, &right, (unsigned int)vb);
  v6 = *(_BYTE **)((char *)&dcl->m_reference_count + (_DWORD)&loc_94636 + 2);
  v7 = (stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *> > *)((char *)dcl + (_DWORD)&loc_94631 + 3);
  v8 = (const vostok::render::res_geometry *const *)((char *)dcl + (_DWORD)&loc_94631 + 3);
  if ( v6 )
  {
    do
    {
      if ( vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>::operator()(
             *((const vostok::render::res_geometry *const *)v6 + 4),
             &right,
             v18) )
      {
        v6 = (_BYTE *)*((_DWORD *)v6 + 3);
      }
      else
      {
        v8 = (const vostok::render::res_geometry *const *)v6;
        v6 = (_BYTE *)*((_DWORD *)v6 + 2);
      }
    }
    while ( v6 );
    if ( v8 == (const vostok::render::res_geometry *const *)v7 )
      goto LABEL_12;
    if ( vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>::operator()(
           &right,
           v8[4],
           v18) )
    {
      v8 = (const vostok::render::res_geometry *const *)((char *)dcl + (_DWORD)&loc_94631 + 3);
    }
  }
  if ( v8 != (const vostok::render::res_geometry *const *)v7 )
  {
    v9 = (vostok::render::res_geometry *)*((_DWORD *)v8 + 4);
    goto LABEL_11;
  }
LABEL_12:
  v11 = vostok::render::g_allocator;
  v12 = type_info::raw_name(&vostok::render::res_geometry `RTTI Type Descriptor');
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v11, 0x18u, v12, (const char *const)v18, v19, v20);
  if ( v14 )
  {
    vostok::render::res_geometry::res_geometry(
      ib,
      a6,
      vertex_stride,
      (vostok::render::res_geometry *)v14,
      (unsigned int)vb);
    v9 = v16;
  }
  else
  {
    v9 = 0;
  }
  *(_DWORD *)&v17._M_color = &__val;
  v6 = v22;
  __val = v9;
  v9->m_is_registered = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *>>::insert_unique(
    v15,
    (int)v22,
    v7,
    v17);
LABEL_11:
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&right.m_dcl);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &right.m_ib,
    (vostok::render::hw_buffer_pool *)v6);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &right.m_vb,
    (vostok::render::hw_buffer_pool *)v6);
  return v9;
}


vostok::render::res_geometry *__thiscall vostok::render::resource_manager::create_geometry(
        vostok::render::resource_manager *this,
        vostok::render::res_declaration *decl,
        const D3D11_INPUT_ELEMENT_DESC *decl_size,
        unsigned int vertex_stride,
        vostok::render::untyped_buffer *vb,
        vostok::render::untyped_buffer *ib,
        vostok::render::untyped_buffer *a7)
{
  vostok::render::res_declaration *declaration; // eax
  vostok::render::resource_manager *v8; // ecx
  vostok::render::res_geometry *geometry; // esi
  unsigned int vertex_stridea; // [esp+4h] [ebp-4h] BYREF

  declaration = vostok::render::resource_manager::create_declaration(
                  this,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  decl_size,
                  vertex_stride);
  vertex_stridea = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    vertex_stridea = (unsigned int)declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v8,
               decl,
               (vostok::render::res_declaration *)vertex_stridea,
               vb,
               ib,
               a7);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&vertex_stridea);
  return geometry;
}
