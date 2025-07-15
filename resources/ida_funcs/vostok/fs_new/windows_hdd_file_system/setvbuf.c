void __thiscall vostok::fs_new::windows_hdd_file_system::setvbuf(
        vostok::fs_new::windows_hdd_file_system *this,
        void *handle,
        char *buffer,
        int mode,
        unsigned __int64 size)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  char v7; // [esp+18h] [ebp-4Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v8; // [esp+1Ch] [ebp-48h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+3Ch] [ebp-28h] BYREF
  int os_handle; // [esp+5Ch] [ebp-8h]
  _iobuf *fp; // [esp+60h] [ebp-4h]

  v7 = 0;
  os_handle = _open_osfhandle(handle, 0);
  if ( os_handle == -1 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(
           vostok::core::g_log_filter_tree,
           (const char *)&stru_955E40.m_next_in_global_list,
           error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
      v7 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\windows_hdd_file_system.cpp",
        0x8Au,
        "void __thiscall vostok::fs_new::windows_hdd_file_system::setvbuf(void *,char *,int,unsigned __int64)",
        (const char *)&stru_955E40.m_next_in_global_list,
        error,
        (const char *)&stru_955E40.m_bones_count);
    }
    if ( (v7 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
        (int *)&log_callback);
  }
  else
  {
    fp = _fdopen(os_handle, "r+b");
    if ( fp )
    {
      setvbuf(fp, buffer, mode, size);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(
             vostok::core::g_log_filter_tree,
             (const char *)&stru_955E40.m_next_in_global_list,
             error) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
        v7 = 2;
        vostok::logging::append(
          &v8,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\windows_hdd_file_system.cpp",
          0x91u,
          "void __thiscall vostok::fs_new::windows_hdd_file_system::setvbuf(void *,char *,int,unsigned __int64)",
          (const char *)&stru_955E40.m_next_in_global_list,
          error,
          "_fdopen: failed");
      }
      if ( (v7 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v6,
          (int *)&v8);
    }
  }
}
