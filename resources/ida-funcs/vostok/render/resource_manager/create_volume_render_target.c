stlp_std::priv::_Rb_tree_node_base *__userpurge vostok::render::resource_manager::create_volume_render_target@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        char *name,
        unsigned int w,
        unsigned int h,
        unsigned int d,
        DXGI_FORMAT fmt,
        vostok::render::enum_rt_usage usage,
        D3D11_USAGE memory_usage)
{
  char *v8; // esi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v9; // ecx
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  vostok::render::render_target *v16; // ecx
  int v17; // eax
  int v18; // edi
  volatile signed __int32 *v19; // eax
  char *v20; // eax
  vostok::fixed_string<260> *v21; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *v22; // ecx
  vostok::render::render_target *v23; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v24; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > v25[12]; // [esp-4h] [ebp-258h] BYREF
  vostok::buffer_string v26[22]; // [esp+12Ch] [ebp-128h] BYREF
  char v27; // [esp+23Ch] [ebp-18h]
  int v28; // [esp+240h] [ebp-14h]
  char v29; // [esp+244h] [ebp-10h] BYREF
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> *result; // [esp+248h] [ebp-Ch]
  const char *v31; // [esp+24Ch] [ebp-8h] BYREF

  v31 = "$user$color_grading";
  vostok::render::resource_manager::create_unique_user_name(
    (vostok::fs_new::virtual_path_string *)this,
    &v25[0]._M_key_compare);
  v8 = name + 557196;
  result = (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >,bool> *)(name + 557196);
  v10 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
          v9,
          (const char *const *)name + 139299,
          &v31);
  if ( v10 != (stlp_std::priv::_Rb_tree_node_base *)v8 )
    return v10[18]._M_parent;
  v12 = vostok::render::g_allocator;
  v13 = type_info::raw_name(&vostok::render::render_target `RTTI Type Descriptor');
  v15 = vostok::memory::doug_lea_allocator::malloc_impl(
          v14,
          (int)v12,
          0x48u,
          v13,
          (const char *const)&v25[0]._M_header._M_data._M_parent->_M_color,
          (const char *const)&v25[0]._M_header._M_data._M_left->_M_color,
          (const unsigned int)v25[0]._M_header._M_data._M_right);
  if ( v15 )
  {
    vostok::render::render_target::render_target(v16, (int)v15);
    v18 = v17;
  }
  else
  {
    v18 = 0;
  }
  vostok::render::render_target::set_name(
    v16,
    (vostok::shared_string *)v18,
    (vostok::shared_string)"$user$color_grading");
  name = 0;
  *(_BYTE *)(v18 + 64) = 1;
  v19 = *(volatile signed __int32 **)(v18 + 4);
  if ( v19 )
  {
    name = *(char **)(v18 + 4);
    _InterlockedExchangeAdd(v19, 1u);
  }
  v20 = (char *)vostok::shared_string::c_str((vostok::shared_string *)&name);
  vostok::fixed_string<260>::fixed_string<260>(v21, v26, v20);
  *(_DWORD *)&v25[0]._M_header._M_data._M_color = v26;
  v27 = 47;
  v28 = v18;
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::render_target *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *>>>::insert_unique(
    v22,
    (stlp_std::priv::_Rb_tree_node_base *)result,
    (const stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> *)&v29,
    v25[0]);
  if ( name )
  {
    v24 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name;
    v23 = (vostok::render::render_target *)_InterlockedExchangeAdd((volatile signed __int32 *)name, 0xFFFFFFFF);
    if ( !v23 )
      vostok::strings::shared::detail::intrusive_base::destroy(0, v24);
  }
  vostok::render::render_target::create_3d(
    v23,
    (const char *)v18,
    "$user$color_grading",
    (unsigned int)v25[0]._M_header._M_data._M_parent,
    (unsigned int)v25[0]._M_header._M_data._M_left,
    (DXGI_FORMAT)v25[0]._M_header._M_data._M_right,
    (vostok::render::enum_rt_usage)v25[0]._M_node_count,
    *(D3D11_USAGE *)&v25[0]._M_key_compare.stlp_std::binary_function<char *,char *,bool>);
  return (stlp_std::priv::_Rb_tree_node_base *)v18;
}
