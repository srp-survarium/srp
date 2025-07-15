void __thiscall vostok::memory::process_allocator::call_free(
        vostok::memory::process_allocator *this,
        void *pointer,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  if ( pointer )
  {
    if ( this->m_use_memory_monitor )
      vostok::memory::monitor::on_free(&pointer, (vostok::command_line::key *)this);
  }
}
