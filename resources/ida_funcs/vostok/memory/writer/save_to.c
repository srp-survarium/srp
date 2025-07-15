char __usercall vostok::memory::writer::save_to@<al>(vostok::memory::writer *this@<ecx>, int a2@<edi>)
{
  char *m_buffer; // eax
  vostok::fs_new::synchronous_device_interface *m_variable; // esi
  bool v4; // zf
  vostok::animation::mixing::animation_interval *v6; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v7; // eax
  vostok::vfs::base_node<1> *v8; // [esp-10h] [ebp-130h]
  const void *v9; // [esp-Ch] [ebp-12Ch]
  unsigned __int64 v10; // [esp-8h] [ebp-128h]
  vostok::fs_new::file_type_pointer f; // [esp+4h] [ebp-11Ch] BYREF
  vostok::fs_new::path_string_impl v12; // [esp+Ch] [ebp-114h] BYREF

  m_buffer = v12.m_string.m_buffer;
  v12.m_string.m_max_end = &v12.m_separator;
  m_variable = s_core_synchronous_device.m_variable;
  v12.m_string.m_begin = v12.m_string.m_buffer;
  v12.m_string.m_end = v12.m_string.m_buffer;
  v12.m_string.m_buffer[0] = 0;
  v12.m_separator = 92;
  if ( v12.m_string.m_buffer != (char *)this )
  {
    v12.m_string.m_end = v12.m_string.m_buffer;
    v12.m_string.m_buffer[0] = 0;
    if ( this )
    {
      if ( LOBYTE(this->__vftable) )
      {
        do
        {
          if ( m_buffer >= v12.m_string.m_max_end )
            break;
          *m_buffer = (char)this->__vftable;
          m_buffer = v12.m_string.m_end + 1;
          this = (vostok::memory::writer *)((char *)this + 1);
          v4 = LOBYTE(this->__vftable) == 0;
          ++v12.m_string.m_end;
        }
        while ( !v4 );
      }
      *m_buffer = 0;
      m_buffer = v12.m_string.m_end;
    }
  }
  vostok::fs_new::path_string_impl::convert(&v12, v12.m_string.m_begin, m_buffer);
  vostok::fs_new::file_type_pointer::file_type_pointer(
    &f,
    (vostok::fs_new::open_file_cache *)&v12,
    m_variable,
    create_always,
    write,
    assert_on_fail_true,
    notify_watcher_false,
    use_buffering_true);
  if ( vostok::vfs::vfs_iterator::operator bool((vostok::vfs::vfs_iterator *)&f) )
  {
    v10 = *(unsigned int *)(a2 + 40);
    v9 = *(const void **)(a2 + 28);
    v8 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&f);
    v6 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(m_variable);
    v7 = (vostok::fs_new::device_file_system_no_watcher_proxy *)vostok::animation::mixing::animation_interval::animation(v6);
    vostok::fs_new::device_file_system_no_watcher_proxy::write(v7, (void **)&v8->m_mount_root.pointer, v9, v10);
    vostok::fs_new::file_type_pointer::~file_type_pointer(&f);
    return 1;
  }
  else
  {
    vostok::fs_new::file_type_pointer::~file_type_pointer(&f);
    return 0;
  }
}
