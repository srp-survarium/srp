void __thiscall vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::push_back(
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::vfs_mount *object,
        bool *out_pushed_first)
{
  survarium::game_camera *v3; // ecx
  vostok::threading::simple_lock::mutex_raii raii; // [esp+18h] [ebp-8h] BYREF

  vostok::threading::simple_lock::mutex_raii::mutex_raii(&raii, &this->m_policy, (vostok::threading::simple_lock *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  object->next_mount_history = 0;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
  {
    object->prev_mount_history = this->m_last;
    this->m_last->next_mount_history = object;
  }
  else
  {
    object->prev_mount_history = 0;
    this->m_first = object;
  }
  this->m_last = object;
  vostok::threading::simple_lock::mutex_raii::clear(&raii);
}
