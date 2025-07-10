vostok::render::untyped_buffer *__userpurge vostok::render::resource_manager::create_buffer@<eax>(
        unsigned int size@<eax>,
        bool a2@<dil>,
        vostok::render::resource_manager *this,
        const void *data,
        vostok::render::enum_buffer_type type,
        vostok::render::untyped_buffer *dynamic,
        bool staging)
{
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v8; // ecx
  vostok::render::untyped_buffer *v9; // esi
  vostok::render::untyped_buffer *v10; // eax
  vostok::render::untyped_buffer *v11; // esi
  void **M_finish; // eax

  v9 = (vostok::render::untyped_buffer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x10u);
  if ( v9 )
  {
    vostok::render::untyped_buffer::untyped_buffer(v9, type, (bool)dynamic, size, data, staging);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  this->m_num_bytes_of_buffers_video_memory += size;
  M_finish = this->m_buffers._M_impl._M_finish;
  dynamic = v11;
  if ( M_finish == this->m_buffers._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      v8,
      (int)&this->m_buffers,
      M_finish,
      (void *const *)&dynamic,
      (const stlp_std::__true_type *)1,
      1,
      a2);
  }
  else
  {
    *M_finish = v11;
    ++this->m_buffers._M_impl._M_finish;
  }
  return v11;
}
