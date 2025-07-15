void __thiscall vostok::vfs::mounter::~mounter(vostok::vfs::mounter *this)
{
  vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *p_pending_mounts; // edi
  vostok::threading::mutex *v3; // ecx
  vostok::vfs::mount_referer *m_first; // esi
  vostok::vfs::mount_referer *next; // ebp
  vostok::threading::mutex *v6; // ecx

  p_pending_mounts = &this->m_file_system->pending_mounts;
  this->__vftable = (vostok::vfs::mounter_vtbl *)&vostok::vfs::mounter::`vftable';
  vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
    p_pending_mounts,
    this,
    (vostok::threading::mutex *)this);
  if ( this->m_referers.m_first )
  {
    vostok::threading::mutex::lock(v3, (_RTL_CRITICAL_SECTION *)&this->m_referers.vostok::threading::mutex);
    m_first = this->m_referers.m_first;
    this->m_referers.m_first = 0;
    this->m_referers.m_last = 0;
    this->m_referers.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->m_referers.vostok::threading::mutex);
    if ( m_first )
    {
      do
      {
        next = m_first->next;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
          &this->m_mount_ptr,
          &m_first->result);
        vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
          m_first->ready_list,
          m_first,
          v6);
        m_first = next;
      }
      while ( next );
    }
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
    (int *)&this->m_args.callback);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&this->m_mount_ptr);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_referers.vostok::threading::mutex);
}
