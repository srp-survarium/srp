void __thiscall vostok::tasks::thread_tls::thread_proc(vostok::tasks::thread_tls *this)
{
  vostok::tasks::thread_tls *v2; // ecx
  vostok::tasks::thread_pool *v3; // ecx

  WaitForSingleObject(*(HANDLE *)this->event_start_thread_work.m_event, 0xFFFFFFFF);
  vostok::tasks::thread_tls::thread_proc_impl(v2, this);
  vostok::tasks::thread_pool::on_task_thread_exited(v3, (int)this->pool);
}
