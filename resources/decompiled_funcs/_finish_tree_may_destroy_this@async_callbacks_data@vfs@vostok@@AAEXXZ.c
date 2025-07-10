void __thiscall vostok::vfs::async_callbacks_data::finish_tree_may_destroy_this(
        vostok::vfs::async_callbacks_data *this)
{
  vostok::vfs::vfs_locked_iterator v2; // [esp+264h] [ebp-2Ch] BYREF
  vostok::vfs::vfs_locked_iterator out_iterator; // [esp+278h] [ebp-18h] BYREF

  if ( this->result == result_error )
  {
    if ( this->nodes_to_expand.m_first != 0 )
    {
      vostok::vfs::upgrade_branch(this->env.node, lock_type_write, lock_type_read);
      vostok::vfs::async_callbacks_data::continue_find_tree(this);
      return;
    }
    vostok::vfs::vfs_iterator::vfs_iterator(&out_iterator);
    out_iterator.mount_operation_id = 0;
    vostok::vfs::make_iterator(&out_iterator, &this->env);
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&this->env.callback,
      (const char *)&out_iterator,
      (const vostok::network_core::udp_match_packet *)1);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&out_iterator);
  }
  else
  {
    vostok::vfs::free_nodes_to_expand(&this->nodes_to_expand);
    vostok::vfs::unlock_and_decref_recursively(
      this->env.node,
      lock_type_write,
      (vostok::vfs::find_enum)this->env.find_flags.m_flags,
      &this->env.file_system->hashset,
      this->env.mount_operation_id);
    vostok::vfs::vfs_iterator::vfs_iterator(&v2);
    v2.mount_operation_id = 0;
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&this->env.callback,
      (const char *)&v2,
      (const vostok::network_core::udp_match_packet *)this->result);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v2);
  }
  vostok::vfs::async_callbacks_data::delete_this(this);
}
