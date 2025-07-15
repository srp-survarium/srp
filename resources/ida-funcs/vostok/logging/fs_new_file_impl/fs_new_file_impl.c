void __userpurge vostok::logging::fs_new_file_impl::fs_new_file_impl(
        vostok::logging::fs_new_file_impl *this@<edi>,
        const vostok::fs_new::synchronous_device_interface *device_proxy@<eax>,
        const vostok::fs_new::native_path_string *path,
        vostok::fs_new::file_mode::mode_enum mode,
        vostok::fs_new::file_access::access_enum access)
{
  void **m_file_storage; // [esp+4h] [ebp-1Ch] BYREF
  vostok::fs_new::open_file_params v6; // [esp+8h] [ebp-18h] BYREF

  this->m_file = 0;
  v6.assert_on_fail = assert_on_fail_false;
  m_file_storage = (void **)this->m_file_storage;
  this->m_device = device_proxy;
  v6.mode = mode;
  v6.access = access;
  this->__vftable = (vostok::logging::fs_new_file_impl_vtbl *)&vostok::logging::fs_new_file_impl::`vftable';
  v6.notify_watcher = notify_watcher_true;
  v6.use_buffering = use_buffering_true;
  v6.file_type_allocated_by_user = 1;
  if ( vostok::fs_new::device_file_system_no_watcher_proxy::open(&device_proxy->m_device, path, &m_file_storage, &v6) )
    this->m_file = m_file_storage;
}
