char __thiscall vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::contains_object(
        vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::vfs_mount *object)
{
  BOOL v2; // ecx
  vostok::vfs::vfs_mount *next_mount_history; // [esp+4h] [ebp-20h]
  vostok::vfs::vfs_mount *m_first; // [esp+8h] [ebp-1Ch]
  vostok::vfs::vfs_mount *i; // [esp+14h] [ebp-10h]
  char v8; // [esp+1Bh] [ebp-9h]
  vostok::threading::simple_lock::mutex_raii raii; // [esp+1Ch] [ebp-8h] BYREF

  v2 = this->m_first == 0;
  if ( v2 )
    return 0;
  vostok::threading::simple_lock::mutex_raii::mutex_raii(&raii, &this->m_policy, (vostok::threading::simple_lock *)v2);
  if ( this->m_first )
    m_first = this->m_first;
  else
    m_first = 0;
  for ( i = m_first; i; i = next_mount_history )
  {
    if ( i == object )
    {
      v8 = 1;
      goto LABEL_16;
    }
    if ( i->next_mount_history )
      next_mount_history = i->next_mount_history;
    else
      next_mount_history = 0;
  }
  v8 = 0;
LABEL_16:
  vostok::threading::simple_lock::mutex_raii::clear(&raii);
  return v8;
}
