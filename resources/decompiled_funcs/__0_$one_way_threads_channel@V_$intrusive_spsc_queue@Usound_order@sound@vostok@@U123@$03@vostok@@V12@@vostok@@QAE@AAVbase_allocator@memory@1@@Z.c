void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *this,
        vostok::memory::base_allocator *owner_allocator)
{
  this->m_forward_queue.m_head = 0;
  this->m_forward_queue.m_push_thread_id = -1;
  this->m_forward_queue.m_pop_thread_id = -1;
  this->m_forward_queue.m_tail = 0;
  this->m_backward_queue.m_head = 0;
  this->m_backward_queue.m_push_thread_id = -1;
  this->m_backward_queue.m_pop_thread_id = -1;
  this->m_backward_queue.m_tail = 0;
  this->m_owner_allocator = owner_allocator;
}
