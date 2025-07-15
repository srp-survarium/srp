void __thiscall vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_exact_node>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        const vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_node<1> **first_to_unmount,
        vostok::vfs::base_node<1> **last_to_unmount,
        vostok::vfs::base_node<1> **next_to_last)
{
  const char *v7; // eax
  vostok::vfs::base_node<1> *node; // [esp+8h] [ebp-44h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+Ch] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_iterator it_end; // [esp+2Ch] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+3Ch] [ebp-10h] BYREF

  v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path);
  vostok::vfs::vfs_hashset::equal_range(this->m_hashset, &begin_end, v7, hash, lock_type_write);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  *first_to_unmount = 0;
  *last_to_unmount = 0;
  *next_to_last = 0;
  while ( 1 )
  {
    if ( (it.node != 0) == (it_end.node != 0) )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return;
    }
    node = it.node;
    if ( it.node == predicate->helper_node )
      break;
    *next_to_last = it.node;
    if ( (node->m_flags & 1) != 1 || *first_to_unmount )
    {
      if ( (node->m_flags & 1) != 1 )
        *first_to_unmount = 0;
    }
    else
    {
      *first_to_unmount = node;
    }
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  if ( !*first_to_unmount )
    *first_to_unmount = it.node;
  *last_to_unmount = node;
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
}


void __thiscall vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_part_of_mount>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        const vostok::vfs::is_part_of_mount *predicate,
        vostok::vfs::base_node<1> **first_to_unmount,
        vostok::vfs::base_node<1> **last_to_unmount,
        vostok::vfs::base_node<1> **next_to_last)
{
  const char *v7; // eax
  vostok::vfs::mount_root_node_base<1> *v8; // [esp+0h] [ebp-54h]
  vostok::vfs::base_node<1> *node; // [esp+10h] [ebp-44h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> begin_end; // [esp+14h] [ebp-40h] BYREF
  vostok::vfs::overlapped_node_iterator it_end; // [esp+34h] [ebp-20h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+44h] [ebp-10h] BYREF

  v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path);
  vostok::vfs::vfs_hashset::equal_range(this->m_hashset, &begin_end, v7, hash, lock_type_write);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &begin_end.first);
  vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &begin_end.second);
  *first_to_unmount = 0;
  *last_to_unmount = 0;
  *next_to_last = 0;
  while ( 1 )
  {
    if ( (it.node != 0) == (it_end.node != 0) )
    {
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return;
    }
    node = it.node;
    v8 = (it.node->m_flags & 8) == 8
       ? vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(it.node)
       : it.node->m_mount_root.pointer;
    if ( v8 == predicate->mount_root )
      break;
    *next_to_last = node;
    if ( (node->m_flags & 1) != 1 || *first_to_unmount )
    {
      if ( (node->m_flags & 1) != 1 )
        *first_to_unmount = 0;
    }
    else
    {
      *first_to_unmount = node;
    }
    vostok::vfs::overlapped_node_iterator::operator++(&it);
  }
  if ( !*first_to_unmount )
    *first_to_unmount = node;
  *last_to_unmount = node;
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
  vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
}
