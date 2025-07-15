vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::physical_folder_node<1>::create(
        vostok::memory::base_allocator *allocator,
        vostok::vfs::mount_root_node_base<1> *mount_root,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *name)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::memory::base_allocator *v5; // eax
  vostok::vfs::base_node<1> *v7; // eax
  const char *v8; // esi
  unsigned int v9; // eax
  _DWORD v10[3]; // [esp+10h] [ebp-4Ch] BYREF
  int v11; // [esp+1Ch] [ebp-40h]
  vostok::vfs::physical_folder_node<1> *v12; // [esp+40h] [ebp-1Ch]
  char v13; // [esp+47h] [ebp-15h]
  vostok::vfs::base_node<1> *base; // [esp+48h] [ebp-14h]
  vostok::platform_pointer_selector<vostok::vfs::mount_root_node_base<1>,1>::helper_pod mount_root_pointer; // [esp+4Ch] [ebp-10h]
  unsigned int node_size; // [esp+54h] [ebp-8h]
  vostok::vfs::physical_folder_node<1> *new_node; // [esp+58h] [ebp-4h]

  v13 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  node_size = vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)name) + 89;
  survarium::weapon_user_dead_state::finalize(v4);
  new_node = (vostok::vfs::physical_folder_node<1> *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                       v5,
                                                       node_size);
  v12 = (vostok::vfs::physical_folder_node<1> *)operator new(0x58u, new_node);
  if ( v12 )
    vostok::vfs::physical_folder_node<1>::physical_folder_node<1>(v12);
  if ( !new_node )
    return 0;
  v7 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_folder_node,1>(new_node);
  base = v7;
  mount_root_pointer = (vostok::platform_pointer_selector<vostok::vfs::mount_root_node_base<1>,1>::helper_pod)(unsigned int)mount_root;
  v10[2] = mount_root;
  v11 = 0;
  v7->m_mount_root.pointer = mount_root;
  HIDWORD(v7->m_mount_helper_parent.max_storage) = v11;
  v10[1] = v10;
  v10[0] = 3;
  base->m_flags = 3;
  v8 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(name);
  v9 = vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)name);
  vostok::strings::copy(base->m_name, v9 + 1, v8);
  mount_root->mount_size += vostok::vfs::base_node<1>::sizeof_with_name(base);
  return new_node;
}
