void __thiscall vostok::vfs::unmounter::recursive_unmount_folder<vostok::vfs::is_exact_node>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_folder_node<1> *parent_to_unmount)
{
  const char *v5; // eax
  vostok::vfs::base_node<1> *pointer; // ecx
  unsigned int v7; // [esp-8h] [ebp-2D8h]
  vostok::vfs::base_folder_node<1> *v8; // [esp+0h] [ebp-2D0h]
  char *s; // [esp+190h] [ebp-140h] BYREF
  char *src; // [esp+194h] [ebp-13Ch] BYREF
  vostok::fs_new::path_string_impl v12; // [esp+198h] [ebp-138h] BYREF
  vostok::vfs::base_node<1> *overlap_of_child_to_unmount; // [esp+2ACh] [ebp-24h] BYREF
  vostok::vfs::base_node<1> *next_child; // [esp+2B0h] [ebp-20h]
  vostok::vfs::base_node<1> *child_to_unmount; // [esp+2B4h] [ebp-1Ch] BYREF
  unsigned int child_hash; // [esp+2B8h] [ebp-18h]
  vostok::fs_new::virtual_path_string *child_path; // [esp+2BCh] [ebp-14h]
  vostok::vfs::base_node<1> *child; // [esp+2C0h] [ebp-10h]
  vostok::vfs::base_node<1> *overlapped_by_unmount; // [esp+2C4h] [ebp-Ch]
  unsigned int saved_path_length; // [esp+2C8h] [ebp-8h]
  vostok::vfs::base_folder_node<1> *overlapped_by_unmount_folder; // [esp+2CCh] [ebp-4h]

  saved_path_length = vostok::fs_new::path_string_impl::length(path);
  overlapped_by_unmount = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(parent_to_unmount)->m_next_overlapped.pointer;
  if ( !overlapped_by_unmount || (overlapped_by_unmount->m_flags & 0x300) != 0 )
    v8 = 0;
  else
    v8 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(overlapped_by_unmount);
  overlapped_by_unmount_folder = v8;
  for ( child = parent_to_unmount->m_first_child.pointer; child; child = next_child )
  {
    next_child = child->m_next.pointer;
    src = child->m_name;
    vostok::fs_new::path_string_impl::path_string_impl(&v12, 47, (const char **)&src);
    v7 = vostok::fs_new::path_string_impl::length(&v12);
    v5 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12);
    child_hash = vostok::fs_new::path_crc32(v5, v7, hash);
    child_path = path;
    s = child->m_name;
    vostok::fs_new::path_string_impl::append_path<char const *>(path, &s);
    child_to_unmount = 0;
    pointer = (vostok::vfs::base_node<1> *)(child == predicate->helper_node);
    if ( child == predicate->helper_node )
    {
      overlap_of_child_to_unmount = 0;
      vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_exact_node const>(
        this,
        child_path,
        child_hash,
        predicate,
        &child_to_unmount,
        &overlap_of_child_to_unmount);
      if ( overlap_of_child_to_unmount )
      {
        pointer = child_to_unmount->m_next_overlapped.pointer;
        overlap_of_child_to_unmount->m_next_overlapped.pointer = pointer;
      }
    }
    if ( !child_to_unmount && overlapped_by_unmount_folder )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
      vostok::vfs::base_folder_node<1>::prepend_child(overlapped_by_unmount_folder, child);
    }
    if ( child_to_unmount )
    {
      if ( this->m_args->submount_type == submount_type_hot_unmount )
        vostok::vfs::unmounter::hot_unmount_node(this, child_to_unmount, child_hash);
      else
        vostok::vfs::free_node(
          this->m_file_system,
          child_to_unmount,
          &this->m_args->root_write_lock,
          child_hash,
          this->m_args->allocator);
    }
    vostok::fs_new::path_string_impl::set_length(path, saved_path_length);
  }
  parent_to_unmount->m_first_child.max_storage = 0;
}
