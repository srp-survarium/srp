void __thiscall vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::push_back(
        vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::mounter *object,
        bool *out_pushed_first)
{
  survarium::game_camera *v3; // ecx
  vostok::vfs::mounter_base *v4; // [esp+4h] [ebp-28h]
  vostok::vfs::mounter_base *v5; // [esp+8h] [ebp-24h]
  vostok::vfs::mounter_base *v6; // [esp+Ch] [ebp-20h]
  vostok::vfs::mounter_base *v7; // [esp+10h] [ebp-1Ch]
  vostok::vfs::mounter *m_last; // [esp+18h] [ebp-14h]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+24h] [ebp-8h] BYREF

  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->m_policy,
    (int)&raii);
  survarium::weapon_user_dead_state::finalize(v3);
  if ( object )
    v7 = &object->vostok::vfs::mounter_base;
  else
    v7 = 0;
  v7->next = 0;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
  {
    if ( object )
      v5 = &object->vostok::vfs::mounter_base;
    else
      v5 = 0;
    v5->prev = this->m_last;
    m_last = this->m_last;
    if ( m_last )
      v4 = &m_last->vostok::vfs::mounter_base;
    else
      v4 = 0;
    v4->next = object;
    this->m_last = object;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
      (int)&raii);
  }
  else
  {
    if ( object )
      v6 = &object->vostok::vfs::mounter_base;
    else
      v6 = 0;
    v6->prev = 0;
    this->m_first = object;
    this->m_last = object;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
      (int)&raii);
  }
}


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
