void __thiscall vostok::vfs::transfer_children::transfer_children(
        vostok::vfs::transfer_children *this,
        vostok::vfs::vfs_hashset *hashset,
        const vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *dest_start,
        vostok::vfs::base_node<1> *source_folder)
{
  survarium::game_camera *v6; // ecx
  const char *v7; // eax
  vostok::vfs::base_folder_node<1> *m_source_folder; // edx
  signed int v9; // [esp-8h] [ebp-15Ch]
  int max_storage_high; // [esp+Ch] [ebp-148h]
  char *src; // [esp+24h] [ebp-130h] BYREF
  vostok::fs_new::path_string_impl v13; // [esp+28h] [ebp-12Ch] BYREF
  char v14; // [esp+13Fh] [ebp-15h]
  vostok::vfs::base_node<1> *it_next; // [esp+140h] [ebp-14h]
  unsigned int child_hash; // [esp+144h] [ebp-10h]
  vostok::fs_new::virtual_path_string *child_path; // [esp+148h] [ebp-Ch]
  vostok::vfs::base_node<1> *it_child; // [esp+14Ch] [ebp-8h]
  unsigned int path_length; // [esp+150h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_hashset = hashset;
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(&this->m_new_source_nodes);
  this->m_dest_start = dest_start;
  this->m_hash = hash;
  vostok::fs_new::virtual_path_string::virtual_path_string(&this->m_path, path);
  v14 = 0;
  survarium::weapon_user_dead_state::finalize(v6);
  this->m_source_folder = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(source_folder);
  path_length = vostok::fs_new::path_string_impl::length(&this->m_path);
  for ( it_child = vostok::vfs::base_node<1>::get_first_child(source_folder); it_child; it_child = it_next )
  {
    it_next = it_child->m_next.pointer;
    src = it_child->m_name;
    vostok::fs_new::path_string_impl::path_string_impl(&v13, 47, (const char **)&src);
    v9 = vostok::fs_new::path_string_impl::length(&v13);
    v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13);
    child_hash = vostok::fs_new::path_crc32(v7, v9, hash);
    child_path = &this->m_path;
    vostok::fs_new::path_string_impl::appendf(&this->m_path, "%c%s", 47, it_child->m_name);
    vostok::vfs::transfer_children::transfer_child(
      this,
      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)child_path,
      child_hash,
      it_child);
    vostok::fs_new::path_string_impl::set_length(&this->m_path, path_length);
  }
  max_storage_high = HIDWORD(this->m_new_source_nodes.m_first.max_storage);
  m_source_folder = this->m_source_folder;
  m_source_folder->m_first_child.pointer = this->m_new_source_nodes.m_first.pointer;
  HIDWORD(m_source_folder->m_first_child.max_storage) = max_storage_high;
}
