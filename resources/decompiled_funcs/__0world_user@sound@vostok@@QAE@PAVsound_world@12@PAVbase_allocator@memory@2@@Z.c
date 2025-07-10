void __thiscall vostok::sound::world_user::world_user(
        vostok::sound::world_user *this,
        vostok::sound::sound_world *owner,
        vostok::memory::base_allocator *allocator)
{
  vostok::sound::sound_order *v3; // eax
  vostok::sound::sound_order *const v4; // eax
  vostok::sound::sound_order *backward_queue_initial_value; // [esp+4h] [ebp-44h]
  vostok::sound::sound_response *v7; // [esp+40h] [ebp-8h]
  vostok::sound::sound_response *v8; // [esp+44h] [ebp-4h]

  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>(
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>(
    &this->m_channel.orders,
    allocator);
  this->m_deleted_producers = 0;
  this->m_deleted_receivers = 0;
  this->m_owner_world = owner;
  this->m_allocator = allocator;
  this->m_is_paused = 0;
  v8 = (vostok::sound::sound_response *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                          8u);
  if ( v8 )
  {
    vostok::sound::sound_response::sound_response(v8);
    backward_queue_initial_value = v3;
  }
  else
  {
    backward_queue_initial_value = 0;
  }
  v7 = (vostok::sound::sound_response *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                          8u);
  if ( v7 )
  {
    vostok::sound::sound_response::sound_response(v7);
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_initialize(
      (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this,
      v4,
      backward_queue_initial_value);
  }
  else
  {
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_initialize(
      (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this,
      0,
      backward_queue_initial_value);
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_initialize(&this->m_channel.orders);
}
