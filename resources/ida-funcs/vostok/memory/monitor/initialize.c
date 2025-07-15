char __usercall vostok::memory::monitor::initialize@<al>(vostok::command_line::key *a1@<ecx>, char *a2@<esi>)
{
  char result; // al
  const vostok::fs_new::native_path_string *current_directory; // eax
  vostok::strings::detail::tuples *v4; // ecx
  vostok::strings::detail::tuples *v5; // ecx
  vostok::threading::mutex_tasks_unaware *v6; // ecx
  vostok::fs_new::synchronous_device_interface *m_variable; // edi
  vostok::fs_new::use_buffering_bool v8; // [esp+0h] [ebp-498h]
  char string[264]; // [esp+8h] [ebp-490h] BYREF
  char v10[268]; // [esp+110h] [ebp-388h] BYREF
  vostok::fs_new::native_path_string v11; // [esp+21Ch] [ebp-27Ch] BYREF
  char _Dst[264]; // [esp+330h] [ebp-168h] BYREF
  vostok::strings::detail::tuples v13; // [esp+438h] [ebp-60h] BYREF
  tm ptm; // [esp+46Ch] [ebp-2Ch] BYREF
  __int64 timeptr; // [esp+490h] [ebp-8h] BYREF

  result = vostok::memory::monitor::enabled(a1);
  if ( result )
  {
    current_directory = vostok::fs_new::get_current_directory(a2);
    strcpy_s(_Dst, 0x104u, current_directory->m_string.m_begin);
    strcat_s(_Dst, 0x104u, "\\memory_monitor\\");
    _mkdir(_Dst);
    _time64(&timeptr);
    _localtime64_s(&ptm, &timeptr);
    strftime(string, 0x104u, "%Y.%m.%d.%H.%M.%S", &ptm);
    vostok::strings::detail::tuples::tuples(v4, &v13, _Dst, string, (char *)s_output_extension);
    vostok::strings::detail::tuples::concat(v5, (int)&v13, v10);
    vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v6, (_RTL_CRITICAL_SECTION *)&s_mutex);
    _InterlockedExchange(&s_mutex.m_initialized, 1);
    m_variable = s_core_synchronous_device.m_variable;
    vostok::fixed_string<260>::fixed_string<260>(
      (vostok::fixed_string<260> *)&s_mutex.m_initialized,
      &v11.m_string,
      v10);
    v11.m_separator = 92;
    vostok::fs_new::device_file_system_no_watcher_proxy::open(
      &m_variable->m_device,
      create_always,
      &s_file,
      &v11,
      write,
      assert_on_fail_true,
      notify_watcher_true,
      v8);
    result = ((int (__thiscall *)(vostok::fs_new::device_file_system_interface *, void **, char *, _DWORD, int, _DWORD))m_variable->m_device.m_device_file_system->setvbuf)(
               m_variable->m_device.m_device_file_system,
               s_file,
               s_buffer,
               0,
               0x80000,
               0);
    s_initialized_2 = 1;
  }
  return result;
}
