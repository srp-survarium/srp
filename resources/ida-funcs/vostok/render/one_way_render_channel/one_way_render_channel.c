void __usercall vostok::render::one_way_render_channel::one_way_render_channel(
        vostok::render::one_way_render_channel *this@<edi>,
        vostok::memory::base_allocator *owner_allocator@<eax>,
        vostok::threading::event_tasks_unaware *a3@<ecx>)
{
  this->m_owner_allocator = owner_allocator;
  this->m_channel.m_forward_queue.m_head = 0;
  this->m_channel.m_forward_queue.m_pop_thread_id = -1;
  this->m_channel.m_forward_queue.m_tail = 0;
  this->m_channel.m_backward_queue.m_head = 0;
  this->m_channel.m_backward_queue.m_push_thread_id = -1;
  this->m_channel.m_backward_queue.m_pop_thread_id = -1;
  this->m_channel.m_backward_queue.m_tail = 0;
  vostok::threading::event_tasks_unaware::event_tasks_unaware(a3, (HANDLE *)&this->m_wait_form_command_event);
  this->m_next_frame_commands_queue.m_size = 0;
  this->m_next_frame_commands_queue.m_first = 0;
  this->m_next_frame_commands_queue.m_last = 0;
  this->m_scenes.m_object = 0;
  this->m_scene_views.m_object = 0;
  this->m_current_frame_id = 0;
  this->m_process_next_frame_commands = 0;
  _InterlockedExchange(&this->m_channel.m_forward_queue.m_pop_thread_id, GetCurrentThreadId());
  _InterlockedExchange(&this->m_channel.m_backward_queue.m_push_thread_id, GetCurrentThreadId());
}
