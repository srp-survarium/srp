void __thiscall vostok::resources::fs_task_mount::call_user_callback(vostok::resources::fs_task_mount *this)
{
  boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *p_m_callback; // eax
  vostok::resources::fs_task_unmount *m_object; // ecx
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> v3; // [esp-4h] [ebp-4h]

  p_m_callback = &this->m_callback;
  if ( (this->m_callback.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
  {
    v3.m_object = 0;
    m_object = this->m_mount_ptr.m_object;
    if ( m_object )
    {
      v3.m_object = m_object;
      m_object = (vostok::resources::fs_task_unmount *)((char *)m_object + 28);
      _InterlockedExchangeAdd((volatile signed __int32 *)m_object, 1u);
    }
    boost::function1<void,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>>::operator()(
      (boost::function1<void,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> > *)m_object,
      p_m_callback,
      v3);
  }
}
