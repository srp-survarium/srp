void __thiscall vostok::resources::fs_task_mount::call_user_callback(vostok::resources::fs_task_mount *this)
{
  boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *p_m_callback; // ebx
  boost::function1<void,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> > *v2; // ecx
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> v3; // [esp-4h] [ebp-10h] BYREF

  p_m_callback = &this->m_callback;
  if ( (this->m_callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    v3.m_object = (vostok::resources::fs_task_unmount *)this;
    vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>(
      &v3,
      &this->m_mount_ptr);
    boost::function1<void,vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>>::operator()(
      v2,
      (vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)p_m_callback,
      v3);
  }
}
