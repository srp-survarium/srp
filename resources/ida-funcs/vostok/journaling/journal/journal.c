void __userpurge vostok::journaling::journal::journal(
        vostok::journaling::journal_usage_enum journal_usage@<eax>,
        const vostok::fs_new::device_file_system_no_watcher_proxy *device@<ecx>,
        int this,
        char *file_name)
{
  vostok::journaling::journal *v4; // ebx
  void **v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  vostok::journaling::journal *v8; // ecx
  unsigned int v9; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v10; // ecx
  char *v11; // [esp-Ch] [ebp-44h]
  char *v12; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-3Ch]
  vostok::journaling::data_chunk_type_enum v14; // [esp+0h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-28h] BYREF
  __int64 v16; // [esp+30h] [ebp-8h] BYREF

  v4 = (vostok::journaling::journal *)this;
  this = 0;
  v12 = file_name;
  v4->m_usage = journal_usage;
  v4->m_device = (vostok::fs_new::device_file_system_no_watcher_proxy)device->m_device_file_system;
  v5 = vostok::journaling::open_file((char *)((journal_usage == record_journal) + 1), &v4->m_device, v12);
  v11 = file_name;
  v4->m_file = v5;
  v4->m_reader.m_file = v5;
  v4->m_reader.m_device = &v4->m_device;
  v4->m_writer.m_file = v4->m_file;
  v4->m_writer.m_device = &v4->m_device;
  v4->m_next_chunk_data_type = invalid_type;
  vostok::strings::copy<260>((char (*)[260])v4->m_file_name, v11);
  if ( v4->m_usage == replay_journal )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802D94,
                                 (const char *)4),
          v6 = v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &log_callback);
      this = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\journaling_journal.cpp",
        0x2Du,
        "__thiscall vostok::journaling::journal::journal(const enum vostok::journaling::journal_usage_enum,const char *,c"
        "onst class vostok::fs_new::device_file_system_no_watcher_proxy &)",
        (char *)&stru_802D94,
        info,
        "Replay journal [%s]",
        file_name);
    }
    if ( (this & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&log_callback);
    v4->m_device.m_device_file_system->get_file_size(
      v4->m_device.m_device_file_system,
      (unsigned __int64 *)&v16,
      v4->m_file);
    if ( !v16 && !debug_macro_helper_ignore_always_26 )
    {
      HIBYTE(this) = 0;
      vostok::debug::on_error(
        (bool *)&this + 3,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\journaling_journal.cpp",
        "vostok::journaling::journal::journal",
        (const char *)0x33,
        "file %s is empty",
        file_name);
      if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
        __debugbreak();
    }
    vostok::journaling::journal::try_start_reading(v8, (int)v4, &this, (vostok::journaling::reader_ptr *)7, v14);
    if ( this )
      v9 = vostok::journaling::reader::r<unsigned int>((vostok::journaling::reader *)this);
    else
      v9 = 0;
    if ( v9 != 2 && !debug_macro_helper_ignore_always_27 )
    {
      HIBYTE(this) = 0;
      vostok::debug::on_error(
        (bool *)&this + 3,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\journaling_journal.cpp",
        "vostok::journaling::journal::journal",
        (const char *)0x39,
        "file %s: unsupported version[%d]. needed[%d]",
        file_name,
        v9,
        2);
      if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
        __debugbreak();
    }
  }
  else if ( v4->m_usage == record_journal )
  {
    vostok::journaling::journal::start_writing(
      (vostok::journaling::journal *)v6,
      (int)v4,
      &this,
      (vostok::journaling::writer_ptr *)7,
      v14);
    file_name = (char *)2;
    vostok::fs_new::device_file_system_no_watcher_proxy::write(
      v10,
      *(_DWORD **)(this + 4),
      *(void ***)this,
      &file_name,
      4u);
  }
}
