void *__thiscall vostok::memory::process_allocator::call_realloc(
        vostok::memory::process_allocator *this,
        void *pointer,
        void *new_size,
        const char *const description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  void **p_pointer; // edi

  if ( new_size )
  {
    if ( pointer )
    {
      this->usable_size_impl(this, pointer);
      if ( pointer )
      {
        if ( this->m_use_memory_monitor )
        {
          p_pointer = &pointer;
          goto LABEL_9;
        }
      }
    }
  }
  else
  {
    new_size = pointer;
    if ( pointer && this->m_use_memory_monitor )
    {
      p_pointer = &new_size;
LABEL_9:
      vostok::memory::monitor::on_free(p_pointer, (vostok::command_line::key *)this);
    }
  }
  return 0;
}
