void __thiscall vostok::vfs::async_link_helper::on_link_received(
        vostok::vfs::async_link_helper *this,
        const vostok::vfs::vfs_locked_iterator *iterator,
        const vostok::network_core::udp_match_packet *result)
{
  boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
    (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)this,
    (const char *)iterator,
    result);
  vostok::vfs::unlock_and_decref_branch(this->original_node, lock_type_read, this->original_mount_operation_id);
  vostok::vfs::async_link_helper::delete_this(this);
}
