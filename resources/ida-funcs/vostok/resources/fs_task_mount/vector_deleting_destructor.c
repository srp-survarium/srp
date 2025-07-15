vostok::resources::fs_task_mount *__thiscall vostok::resources::fs_task_mount::`vector deleting destructor'(
        vostok::resources::fs_task_mount *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec(&this->m_mount_ptr);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->m_mount_callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&this->m_callback);
  this->__vftable = (vostok::resources::fs_task_mount_vtbl *)&vostok::resources::fs_task::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
