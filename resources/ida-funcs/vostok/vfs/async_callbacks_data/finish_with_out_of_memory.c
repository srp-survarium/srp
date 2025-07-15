void __thiscall vostok::vfs::async_callbacks_data::finish_with_out_of_memory(vostok::vfs::async_callbacks_data *this)
{
  survarium::game_camera *v1; // ecx
  vostok::vfs::vfs_locked_iterator v3; // [esp+134h] [ebp-14h] BYREF

  vostok::vfs::unlock_and_decref_branch(this->env.node, lock_type_read, this->env.mount_operation_id);
  vostok::vfs::vfs_iterator::vfs_iterator(&v3);
  v3.mount_operation_id = 0;
  boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
    (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&this->env.callback,
    (const char *)&v3,
    (const vostok::network_core::udp_match_packet *)3);
  vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v3);
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::vfs::async_callbacks_data::delete_this(this);
}
