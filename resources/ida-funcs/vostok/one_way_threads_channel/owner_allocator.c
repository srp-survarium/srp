vostok::memory::base_allocator *__thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::owner_allocator(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4> > *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_owner_allocator;
}
