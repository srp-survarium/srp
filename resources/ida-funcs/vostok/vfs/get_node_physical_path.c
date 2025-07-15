vostok::fs_new::native_path_string *__cdecl vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(
        vostok::fs_new::native_path_string *result,
        vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::vfs::mount_root_node_base<1> *pointer; // ecx
  vostok::vfs::base_node<1> *v6; // eax
  vostok::render::skeleton_model_instance *v7; // esi
  unsigned int v8; // eax
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  vostok::vfs::mount_root_node_base<1> *v11; // [esp+4h] [ebp-6E0h]
  char s[4]; // [esp+26Ch] [ebp-478h] BYREF
  vostok::vfs::universal_file_node<1> *uni_node; // [esp+270h] [ebp-474h]
  vostok::fs_new::virtual_path_string mount_root_path; // [esp+274h] [ebp-470h] BYREF
  vostok::fs_new::native_path_string out_path; // [esp+38Ch] [ebp-358h] BYREF
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+4A8h] [ebp-23Ch]
  vostok::fs_new::virtual_path_string node_path; // [esp+4ACh] [ebp-238h] BYREF
  vostok::vfs::base_node<1> *base; // [esp+5C8h] [ebp-11Ch]
  vostok::fs_new::native_path_string relative_to_mount_root_path; // [esp+5CCh] [ebp-118h] BYREF

  s[3] = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  base = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::base_node,1>(node);
  s[2] = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( (base->m_flags & 8) == 8 )
  {
    v11 = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(base);
  }
  else
  {
    pointer = base->m_mount_root.pointer;
    v11 = base->m_mount_root.pointer;
  }
  mount_root = v11;
  s[1] = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
  if ( (base->m_flags & 4) == 4 )
  {
    vostok::fs_new::path_string_impl::path_string_impl(
      result,
      92,
      (const vostok::platform_pointer_selector<char,1>::helper *)&mount_root->physical_path);
    return result;
  }
  else if ( (base->m_flags & 0x2000) == 0x2000 )
  {
    uni_node = vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(base);
    vostok::fs_new::native_path_string::native_path_string(result, &uni_node->physical_path);
    return result;
  }
  else
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&node_path);
    vostok::vfs::base_node<1>::get_full_path(base, (vostok::fs_new::native_path_string *)&node_path);
    vostok::fs_new::virtual_path_string::virtual_path_string(&mount_root_path);
    v6 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(mount_root);
    vostok::vfs::base_node<1>::get_full_path(v6, (vostok::fs_new::native_path_string *)&mount_root_path);
    v7 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&node_path);
    v8 = vostok::fs_new::path_string_impl::length(&mount_root_path);
    vostok::fs_new::native_path_string::convert((const char *)v7 + v8, &relative_to_mount_root_path);
    vostok::fs_new::path_string_impl::path_string_impl(
      &out_path,
      92,
      (const vostok::platform_pointer_selector<char,1>::helper *)&mount_root->physical_path);
    if ( vostok::fs_new::path_string_impl::length(&relative_to_mount_root_path) )
    {
      survarium::weapon_user_dead_state::finalize(v9);
      survarium::weapon_user_dead_state::finalize(v10);
      if ( *relative_to_mount_root_path.m_string.m_begin != 92 )
      {
        s[0] = 92;
        vostok::fs_new::path_string_impl::operator+=<char>(&out_path, s);
      }
    }
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
      &out_path,
      &relative_to_mount_root_path.m_string);
    vostok::fs_new::native_path_string::native_path_string(result, &out_path);
    return result;
  }
}


vostok::fs_new::native_path_string *__cdecl vostok::vfs::get_node_physical_path<vostok::vfs::physical_file_node,1>(
        vostok::fs_new::native_path_string *result,
        vostok::vfs::physical_file_node<1> *node)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::vfs::mount_root_node_base<1> *pointer; // ecx
  vostok::vfs::base_node<1> *v6; // eax
  vostok::render::skeleton_model_instance *v7; // esi
  unsigned int v8; // eax
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  vostok::vfs::mount_root_node_base<1> *v11; // [esp+4h] [ebp-6E0h]
  char s[4]; // [esp+26Ch] [ebp-478h] BYREF
  vostok::vfs::universal_file_node<1> *uni_node; // [esp+270h] [ebp-474h]
  vostok::fs_new::virtual_path_string mount_root_path; // [esp+274h] [ebp-470h] BYREF
  vostok::fs_new::native_path_string out_path; // [esp+38Ch] [ebp-358h] BYREF
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+4A8h] [ebp-23Ch]
  vostok::fs_new::virtual_path_string node_path; // [esp+4ACh] [ebp-238h] BYREF
  vostok::vfs::base_node<1> *base; // [esp+5C8h] [ebp-11Ch]
  vostok::fs_new::native_path_string relative_to_mount_root_path; // [esp+5CCh] [ebp-118h] BYREF

  s[3] = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  base = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>((vostok::vfs::hard_link_node<1> *)node);
  s[2] = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( (base->m_flags & 8) == 8 )
  {
    v11 = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(base);
  }
  else
  {
    pointer = base->m_mount_root.pointer;
    v11 = base->m_mount_root.pointer;
  }
  mount_root = v11;
  s[1] = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
  if ( (base->m_flags & 4) == 4 )
  {
    vostok::fs_new::path_string_impl::path_string_impl(
      result,
      92,
      (const vostok::platform_pointer_selector<char,1>::helper *)&mount_root->physical_path);
    return result;
  }
  else if ( (base->m_flags & 0x2000) == 0x2000 )
  {
    uni_node = vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(base);
    vostok::fs_new::native_path_string::native_path_string(result, &uni_node->physical_path);
    return result;
  }
  else
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(&node_path);
    vostok::vfs::base_node<1>::get_full_path(base, (vostok::fs_new::native_path_string *)&node_path);
    vostok::fs_new::virtual_path_string::virtual_path_string(&mount_root_path);
    v6 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(mount_root);
    vostok::vfs::base_node<1>::get_full_path(v6, (vostok::fs_new::native_path_string *)&mount_root_path);
    v7 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&node_path);
    v8 = vostok::fs_new::path_string_impl::length(&mount_root_path);
    vostok::fs_new::native_path_string::convert((const char *)v7 + v8, &relative_to_mount_root_path);
    vostok::fs_new::path_string_impl::path_string_impl(
      &out_path,
      92,
      (const vostok::platform_pointer_selector<char,1>::helper *)&mount_root->physical_path);
    if ( vostok::fs_new::path_string_impl::length(&relative_to_mount_root_path) )
    {
      survarium::weapon_user_dead_state::finalize(v9);
      survarium::weapon_user_dead_state::finalize(v10);
      if ( *relative_to_mount_root_path.m_string.m_begin != 92 )
      {
        s[0] = 92;
        vostok::fs_new::path_string_impl::operator+=<char>(&out_path, s);
      }
    }
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
      &out_path,
      &relative_to_mount_root_path.m_string);
    vostok::fs_new::native_path_string::native_path_string(result, &out_path);
    return result;
  }
}
