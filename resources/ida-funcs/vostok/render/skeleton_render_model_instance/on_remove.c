void __thiscall vostok::render::skeleton_render_model_instance::on_remove(
        vostok::render::skeleton_render_model_instance *this)
{
  vostok::render::update_bones_subscriber *m_first; // eax
  vostok::render::update_bones_subscriber *next; // esi
  boost::function<void __cdecl(vostok::render::skeleton_render_model_instance const &)> *p_model_removed_callback; // eax
  int v5; // ecx

  m_first = this->m_update_bones_subscribers.m_first;
  if ( m_first )
  {
    do
    {
      next = m_first->next;
      p_model_removed_callback = &m_first->model_removed_callback;
      v5 = -(p_model_removed_callback->vtable != 0);
      if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v5) != 0 )
        boost::function1<void,vostok::collision::object const &>::operator()(
          (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v5,
          p_model_removed_callback,
          (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)this);
      m_first = next;
    }
    while ( next );
  }
}
