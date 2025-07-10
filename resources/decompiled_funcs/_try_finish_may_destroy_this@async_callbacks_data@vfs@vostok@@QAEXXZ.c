void __thiscall vostok::vfs::async_callbacks_data::try_finish_may_destroy_this(vostok::vfs::async_callbacks_data *this)
{
  if ( this->all_queries_done && this->callbacks_called_count == this->callbacks_count )
  {
    this->env.node = vostok::vfs::vfs_hashset::find_no_lock(
                       &this->env.file_system->hashset,
                       this->env.partial_path,
                       check_locks_true);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    if ( this->type )
      vostok::vfs::async_callbacks_data::finish_tree_may_destroy_this(this);
    else
      vostok::vfs::async_callbacks_data::finish_branch_destroy_this(this);
  }
}
