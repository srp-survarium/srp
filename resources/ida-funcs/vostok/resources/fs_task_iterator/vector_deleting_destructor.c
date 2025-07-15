vostok::resources::fs_task_iterator *__thiscall vostok::resources::fs_task_iterator::`vector deleting destructor'(
        vostok::resources::fs_task_iterator *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  vostok::vfs::vfs_locked_iterator::clear((vostok::vfs::vfs_locked_iterator *)this, (int)&this->m_iterator);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->m_callback);
  this->__vftable = (vostok::resources::fs_task_iterator_vtbl *)&vostok::resources::fs_task::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
