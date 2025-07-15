void __thiscall vostok::tasks::thread_pool::~thread_pool(
        vostok::tasks::thread_pool *this,
        volatile int *core_thread_count_buffer)
{
  int v3; // ecx
  vostok::buffer_vector<long volatile > **v4; // ebx
  unsigned int v5; // edi
  vostok::buffer_vector<vostok::tasks::thread_tls> *v6; // ecx
  vostok::buffer_vector<vostok::tasks::thread_tls> *v7; // ecx
  vostok::threading *v8; // [esp+0h] [ebp-18h]
  vostok::tasks::thread_tls *user_thread_tls_buffer; // [esp+10h] [ebp-8h]
  vostok::tasks::thread_tls *task_thread_tls_buffer; // [esp+14h] [ebp-4h]
  volatile int *core_thread_count_buffera; // [esp+1Ch] [ebp+4h]
  char *core_thread_count_bufferb; // [esp+1Ch] [ebp+4h]

  _InterlockedExchange(core_thread_count_buffer + 36, 1);
  v3 = *((_DWORD *)core_thread_count_buffer + 30) - *((_DWORD *)core_thread_count_buffer + 29);
  v4 = (vostok::buffer_vector<long volatile > **)(core_thread_count_buffer + 29);
  v5 = 0;
  if ( v3 / 360 )
  {
    core_thread_count_buffera = 0;
    do
    {
      if ( !s_logical_core_count )
        vostok::threading::initialize_core_count(v8);
      vostok::tasks::thread_pool::try_activate_task_thread(
        (vostok::tasks::thread_pool *)core_thread_count_buffer,
        (vostok::tasks::thread_tls *)((char *)*v4 + (_DWORD)core_thread_count_buffera),
        v5 % s_logical_core_count);
      core_thread_count_buffera += 90;
      ++v5;
      v3 = (*((_DWORD *)core_thread_count_buffer + 30) - *((_DWORD *)core_thread_count_buffer + 29)) / 360;
    }
    while ( v5 < v3 );
  }
  vostok::threading::event::wait((vostok::threading::event *)v3, (unsigned int)(core_thread_count_buffer + 24));
  core_thread_count_bufferb = (char *)*((_DWORD *)core_thread_count_buffer + 33);
  user_thread_tls_buffer = (vostok::tasks::thread_tls *)*((_DWORD *)core_thread_count_buffer + 31);
  task_thread_tls_buffer = (vostok::tasks::thread_tls *)*v4;
  vostok::buffer_vector<long volatile>::resize(*v4, (_DWORD *)core_thread_count_buffer + 33);
  vostok::buffer_vector<vostok::tasks::thread_tls>::resize(v6, (int *)core_thread_count_buffer + 31, 0);
  vostok::buffer_vector<vostok::tasks::thread_tls>::resize(v7, (int *)core_thread_count_buffer + 29, 0);
  if ( core_thread_count_bufferb )
    pt3free(core_thread_count_bufferb);
  if ( user_thread_tls_buffer )
    pt3free(user_thread_tls_buffer->m_cache_line_pad_$34);
  if ( task_thread_tls_buffer )
    pt3free(task_thread_tls_buffer->m_cache_line_pad_$34);
  *((_DWORD *)core_thread_count_buffer + 34) = *((_DWORD *)core_thread_count_buffer + 33);
  vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
    *((vostok::tasks::thread_tls **)core_thread_count_buffer + 31),
    (vostok::tasks::thread_tls **)core_thread_count_buffer + 32);
  *((_DWORD *)core_thread_count_buffer + 32) = *((_DWORD *)core_thread_count_buffer + 31);
  vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
    (vostok::tasks::thread_tls *)*v4,
    (vostok::tasks::thread_tls **)core_thread_count_buffer + 30);
  *((_DWORD *)core_thread_count_buffer + 30) = *v4;
  CloseHandle(*((HANDLE *)core_thread_count_buffer + 24));
  CloseHandle(*((HANDLE *)core_thread_count_buffer + 14));
  CloseHandle(*((HANDLE *)core_thread_count_buffer + 12));
  CloseHandle(*((HANDLE *)core_thread_count_buffer + 10));
  CloseHandle(*((HANDLE *)core_thread_count_buffer + 8));
  DeleteCriticalSection((LPCRITICAL_SECTION)(core_thread_count_buffer + 2));
}
