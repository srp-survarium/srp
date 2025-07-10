void __thiscall vostok::threading::on_thread_spawn(vostok::tasks::thread_pool *this)
{
  if ( s_thread_pool.m_initialized )
    vostok::tasks::thread_pool::register_current_thread_as_core_user(this, (DWORD *)s_thread_pool.m_variable);
}
