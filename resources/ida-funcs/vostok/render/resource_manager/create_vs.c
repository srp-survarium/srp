const vostok::render::xs_descriptor<vostok::render::vs_data> *__thiscall vostok::render::resource_manager::create_vs(
        vostok::render::resource_manager *this,
        const vostok::render::xs_descriptor<vostok::render::vs_data> *binder,
        vostok::render::xs_descriptor<vostok::render::vs_data> *bindera)
{
  vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data> *v3; // ebx
  char *v4; // esi
  const vostok::render::xs_descriptor<vostok::render::vs_data> **v5; // edi
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v11; // ecx
  int v12; // eax
  int v13; // edi
  vostok::render::res_xs<vostok::render::vs_data> *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // ebx
  vostok::memory::doug_lea_allocator *v16; // ecx
  stlp_std::priv::_Rb_tree_node_base v17; // [esp-4h] [ebp-1Ch]
  const char *v18; // [esp+0h] [ebp-18h]
  const char *v19; // [esp+0h] [ebp-18h]
  const char *v20; // [esp+4h] [ebp-14h]
  const char *v21; // [esp+4h] [ebp-14h]
  unsigned int v22; // [esp+8h] [ebp-10h]
  unsigned int v23; // [esp+8h] [ebp-10h]
  int v24; // [esp+10h] [ebp-8h] BYREF
  char v25; // [esp+14h] [ebp-4h]

  v3 = (vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data> *)&loc_88150
     + (_DWORD)binder;
  v4 = *(char **)((char *)&loc_88150 + (_DWORD)binder + 4);
  v5 = (const vostok::render::xs_descriptor<vostok::render::vs_data> **)((char *)&loc_88150 + (_DWORD)binder);
  if ( v4 )
  {
    do
    {
      if ( vostok::render::res_xs<vostok::render::gs_data>::compare(
             (vostok::render::res_xs<vostok::render::vs_data> *)this,
             *((const vostok::render::xs_descriptor<vostok::render::vs_data> **)v4 + 4),
             (int)bindera) < 0 )
      {
        v4 = (char *)*((_DWORD *)v4 + 3);
      }
      else
      {
        v5 = (const vostok::render::xs_descriptor<vostok::render::vs_data> **)v4;
        v4 = (char *)*((_DWORD *)v4 + 2);
      }
    }
    while ( v4 );
    if ( v5 == (const vostok::render::xs_descriptor<vostok::render::vs_data> **)v3 )
      goto LABEL_11;
    if ( vostok::render::res_xs<vostok::render::gs_data>::compare(
           (vostok::render::res_xs<vostok::render::vs_data> *)this,
           v5[4],
           (int)bindera) > 0 )
      v5 = (const vostok::render::xs_descriptor<vostok::render::vs_data> **)((char *)&loc_88150 + (_DWORD)binder);
  }
  if ( v5 != (const vostok::render::xs_descriptor<vostok::render::vs_data> **)v3 )
    return v5[4];
LABEL_11:
  v7 = vostok::render::g_allocator;
  v8 = type_info::raw_name(&vostok::render::res_xs<vostok::render::vs_data> `RTTI Type Descriptor');
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x1Cu, v8, v18, v20, v22);
  if ( v10 )
  {
    vostok::render::res_xs<vostok::render::vs_data>::res_xs<vostok::render::vs_data>(v11, (int)v10, bindera);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  *(_DWORD *)&v17._M_color = &bindera;
  bindera = (vostok::render::xs_descriptor<vostok::render::vs_data> *)v13;
  *(_BYTE *)(v13 + 24) = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *>>::insert_unique(
    (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)v11,
    (int)&v24,
    v3,
    v17);
  if ( !v25 )
  {
    v15 = vostok::render::g_allocator;
    vostok::render::res_xs<vostok::render::vs_data>::`scalar deleting destructor'(v14, v13);
    vostok::memory::doug_lea_allocator::free_impl(v16, (int)v15, (char *)v13, v19, v21, v23);
    return *(const vostok::render::xs_descriptor<vostok::render::vs_data> **)(v24 + 16);
  }
  return (const vostok::render::xs_descriptor<vostok::render::vs_data> *)v13;
}
