void __thiscall vostok::memory::inplace_constructor::operator()(vostok::memory::inplace_constructor *this)
{
  vostok::threading::mutex_tasks_unaware *v1; // ecx
  vostok::threading::mutex_tasks_unaware *v2; // ecx

  vostok::memory::doug_lea_allocator::doug_lea_allocator(
    (vostok::memory::doug_lea_allocator *)s_crt_allocator_buffer,
    thread_id_const_false,
    1,
    0,
    0);
  *(_DWORD *)s_crt_allocator_buffer = &vostok::memory::doug_lea_mt_allocator::`vftable';
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v1, (_RTL_CRITICAL_SECTION *)&s_crt_allocator_buffer[56]);
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v2, (_RTL_CRITICAL_SECTION *)&s_crt_allocator_buffer[80]);
  s_crt_allocator_buffer[104] = 0;
  (*(void (__thiscall **)(char *, unsigned __int8 *, void *, _DWORD, const char *))(*(_DWORD *)s_crt_allocator_buffer + 4))(
    s_crt_allocator_buffer,
    vostok::memory::s_CRT_arena,
    &loc_100000,
    0,
    "CRT allocator");
}
