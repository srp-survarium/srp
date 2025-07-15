void __usercall vostok::render::texture_streaming_async_worker::ensure_completion(
        vostok::render::texture_streaming_async_worker *this@<ecx>,
        int a2@<eax>)
{
  _BYTE *v2; // esi

  v2 = (_BYTE *)(a2 + 196);
  if ( *(_BYTE *)(a2 + 196) )
    vostok::tasks::thread_pool::wait_for_task_list((vostok::tasks::task *)a2, s_thread_pool.m_variable);
  *v2 = 0;
}
