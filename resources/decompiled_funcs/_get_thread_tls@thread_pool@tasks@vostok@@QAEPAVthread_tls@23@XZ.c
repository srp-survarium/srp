vostok::tasks::thread_tls *__usercall vostok::tasks::thread_pool::get_thread_tls@<eax>(
        vostok::tasks::thread_pool *this@<ecx>,
        int a2@<eax>)
{
  return (vostok::tasks::thread_tls *)TlsGetValue(*(_DWORD *)(a2 + 108));
}
