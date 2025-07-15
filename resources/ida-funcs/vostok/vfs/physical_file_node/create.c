vostok::vfs::physical_file_node<1> *__cdecl vostok::vfs::physical_file_node<1>::create(
        vostok::memory::base_allocator *allocator,
        vostok::vfs::mount_root_node_base<1> *mount_root,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *name,
        volatile int file_size)
{
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::memory::base_allocator *v6; // eax
  vostok::vfs::base_node<1> *v8; // eax
  const char *v9; // esi
  unsigned int v10; // eax
  _DWORD *v11; // [esp+18h] [ebp-30h]
  _DWORD v12[3]; // [esp+20h] [ebp-28h] BYREF
  _DWORD *v13; // [esp+2Ch] [ebp-1Ch]
  char v14; // [esp+33h] [ebp-15h]
  vostok::vfs::base_node<1> *base; // [esp+34h] [ebp-14h]
  vostok::platform_pointer_selector<vostok::vfs::mount_root_node_base<1>,1>::helper_pod mount_root_pointer; // [esp+38h] [ebp-10h]
  unsigned int node_size; // [esp+40h] [ebp-8h]
  vostok::vfs::physical_file_node<1> *new_node; // [esp+44h] [ebp-4h]

  v14 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  node_size = vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)name) + 65;
  survarium::weapon_user_dead_state::finalize(v5);
  new_node = (vostok::vfs::physical_file_node<1> *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                     v6,
                                                     node_size);
  if ( !new_node )
    return 0;
  v13 = operator new(0x40u, new_node);
  if ( v13 )
  {
    v11 = v13;
    *v13 = 0;
    v12[1] = v12;
    v12[0] = 0;
    v11[1] = 0;
    vostok::vfs::base_node<1>::base_node<1>((vostok::vfs::base_node<1> *)(v11 + 2), 0);
  }
  new_node->m_size = file_size;
  base = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>((vostok::vfs::hard_link_node<1> *)new_node);
  base->m_flags = 2;
  mount_root_pointer = (vostok::platform_pointer_selector<vostok::vfs::mount_root_node_base<1>,1>::helper_pod)(unsigned int)mount_root;
  v8 = base;
  base->m_mount_root.pointer = mount_root;
  HIDWORD(v8->m_mount_helper_parent.max_storage) = 0;
  v9 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(name);
  v10 = vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)name);
  vostok::strings::copy(base->m_name, v10 + 1, v9);
  mount_root->mount_size += vostok::vfs::base_node<1>::sizeof_with_name(base);
  return new_node;
}
