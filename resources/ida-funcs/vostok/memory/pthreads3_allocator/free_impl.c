void __userpurge vostok::memory::pthreads3_allocator::free_impl(
        vostok::memory::pthreads3_allocator *this@<ecx>,
        int a2@<eax>,
        char *pointer,
        const char *const a4,
        const char *const a5,
        const unsigned int a6)
{
  if ( *(_BYTE *)(a2 + 16) )
    vostok::memory::monitor::on_free((void **)&pointer, (vostok::command_line::key *)this);
  pt3free((int)this, pointer);
}
