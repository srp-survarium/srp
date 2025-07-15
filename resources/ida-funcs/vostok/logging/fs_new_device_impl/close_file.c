void __thiscall vostok::logging::fs_new_device_impl::close_file(
        vostok::logging::fs_new_device_impl *this,
        vostok::logging::base_fs_file *file)
{
  vostok::logging::base_fs_file_vtbl *v3; // ecx

  v3 = file[68].__vftable;
  file->__vftable = (vostok::logging::base_fs_file_vtbl *)&vostok::logging::fs_new_file_impl::`vftable';
  if ( v3 )
    (*(void (__thiscall **)(unsigned __int64 (__thiscall *)(vostok::logging::base_fs_file *), vostok::logging::base_fs_file_vtbl *))(*(_DWORD *)file[1].tell + 8))(
      file[1].tell,
      v3);
  file->__vftable = (vostok::logging::base_fs_file_vtbl *)&vostok::logging::base_fs_file::`vftable';
  this->m_allocator->deallocate(this->m_allocator, file);
}
