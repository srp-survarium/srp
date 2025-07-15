void __userpurge vostok::render::resource_manager::create_buffer(
        unsigned int size@<edi>,
        vostok::render::resource_manager *this,
        void *stride,
        vostok::render::enum_buffer_type data,
        BOOL type,
        bool dynamic,
        char staging)
{
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  vostok::render::untyped_buffer *v11; // ecx
  const char *v12; // [esp+0h] [ebp-8h]
  const char *v13; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v7 = vostok::render::g_allocator;
  v8 = type_info::raw_name(&vostok::render::untyped_buffer `RTTI Type Descriptor');
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x20u, v8, v12, v13, savedregs);
  if ( v10 )
    vostok::render::untyped_buffer::untyped_buffer(
      v11,
      (const unsigned int)v10,
      size,
      (unsigned int)stride,
      data,
      type,
      dynamic,
      staging);
  this->m_num_bytes_of_buffers_video_memory += size;
}
