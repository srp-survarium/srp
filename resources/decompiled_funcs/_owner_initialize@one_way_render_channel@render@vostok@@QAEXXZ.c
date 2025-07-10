void __thiscall vostok::render::one_way_render_channel::owner_initialize(vostok::render::one_way_render_channel *this)
{
  vostok::render::base_command *v2; // eax
  vostok::render::base_command *v3; // ebp
  vostok::render::base_command *v4; // eax
  vostok::render::base_command *v5; // edi

  v2 = (vostok::render::base_command *)this->m_channel.m_owner_allocator->call_malloc(
                                         this->m_channel.m_owner_allocator,
                                         84);
  if ( v2 )
  {
    v2->is_deferred_command = 0;
    v2->use_depth = 1;
    v2->remove_frame_id = 0;
    v2->__vftable = (vostok::render::base_command_vtbl *)&stru_954D10.m_string.m_buffer[148];
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = (vostok::render::base_command *)this->m_channel.m_owner_allocator->call_malloc(
                                         this->m_channel.m_owner_allocator,
                                         84);
  if ( v4 )
  {
    v4->is_deferred_command = 0;
    v4->use_depth = 1;
    v4->remove_frame_id = 0;
    v4->__vftable = (vostok::render::base_command_vtbl *)&stru_954D10.m_string.m_buffer[148];
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  _InterlockedExchange(&this->m_channel.m_forward_queue.m_push_thread_id, GetCurrentThreadId());
  v3->next = 0;
  this->m_channel.m_forward_queue.m_tail = v3;
  this->m_channel.m_forward_queue.m_head = v3;
  _InterlockedExchange(&this->m_channel.m_backward_queue.m_pop_thread_id, GetCurrentThreadId());
  v5->next = 0;
  this->m_channel.m_backward_queue.m_tail = v5;
  this->m_channel.m_backward_queue.m_head = v5;
}
