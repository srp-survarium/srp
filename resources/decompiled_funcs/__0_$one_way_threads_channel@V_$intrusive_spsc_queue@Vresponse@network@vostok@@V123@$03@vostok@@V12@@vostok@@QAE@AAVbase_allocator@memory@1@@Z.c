void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this,
        vostok::memory::base_allocator *owner_allocator)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
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
