void __thiscall vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::erase(
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::vfs_mount *object)
{
  BOOL v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::vfs::vfs_mount *next; // [esp+Ch] [ebp-10h]
  vostok::vfs::vfs_mount *prev; // [esp+10h] [ebp-Ch]
  vostok::threading::simple_lock::mutex_raii raii; // [esp+14h] [ebp-8h] BYREF

  v2 = this->m_first == 0;
  if ( !v2 )
  {
    vostok::threading::simple_lock::mutex_raii::mutex_raii(&raii, &this->m_policy, (vostok::threading::simple_lock *)v2);
    prev = object->prev_mount_history;
    next = object->next_mount_history;
    object->prev_mount_history = 0;
    object->next_mount_history = 0;
    if ( prev )
    {
      v3 = (survarium::game_camera *)next;
      prev->next_mount_history = next;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)object);
      v3 = (survarium::game_camera *)next;
      this->m_first = next;
    }
    if ( next )
    {
      next->prev_mount_history = prev;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v3);
      this->m_last = prev;
    }
    object->prev_mount_history = 0;
    object->next_mount_history = 0;
    vostok::threading::simple_lock::mutex_raii::clear(&raii);
  }
}
