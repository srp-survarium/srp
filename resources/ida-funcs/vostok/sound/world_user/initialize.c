void __thiscall vostok::sound::world_user::initialize(vostok::sound::world_user *this)
{
  vostok::memory::base_allocator *m_orders_allocator; // ebp
  char *v3; // eax
  vostok::vectora<unsigned __int64> *v4; // eax
  vostok::memory::base_allocator *v5; // ecx
  vostok::memory::base_allocator *v6; // ebp
  char *v7; // eax
  vostok::vectora<unsigned __int64> *v8; // eax
  vostok::memory::base_allocator *v9; // ecx
  vostok::memory::base_allocator *v10; // ebp
  char *v11; // eax
  vostok::sound::sound_order *v12; // eax
  vostok::sound::sound_order *v13; // ebp
  vostok::memory::base_allocator *v14; // ecx
  char *v15; // eax
  vostok::sound::sound_order *v16; // eax
  vostok::sound::sound_order *v17; // ebx
  vostok::memory::base_allocator *v18; // ecx
  vostok::memory::base_allocator *v19; // [esp+3Ch] [ebp-4h]

  m_orders_allocator = this->m_orders_allocator;
  if ( m_orders_allocator )
  {
    v3 = type_info::raw_name(&vostok::vectora<unsigned __int64> `RTTI Type Descriptor');
    v4 = (vostok::vectora<unsigned __int64> *)m_orders_allocator->call_malloc(
                                                m_orders_allocator,
                                                16u,
                                                v3,
                                                "vostok::sound::world_user::initialize",
                                                ".\\world_user.cpp",
                                                46u);
    if ( v4 )
    {
      v5 = this->m_orders_allocator;
      v4->_M_impl._M_start = 0;
      v4->_M_impl._M_finish = 0;
      v4->_M_impl._M_end_of_storage.m_allocator = v5;
      v4->_M_impl._M_end_of_storage._M_data = 0;
    }
    else
    {
      v4 = 0;
    }
    v6 = this->m_orders_allocator;
    this->m_deleted_producers = v4;
    v7 = type_info::raw_name(&vostok::vectora<unsigned __int64> `RTTI Type Descriptor');
    v8 = (vostok::vectora<unsigned __int64> *)v6->call_malloc(
                                                v6,
                                                16u,
                                                v7,
                                                "vostok::sound::world_user::initialize",
                                                ".\\world_user.cpp",
                                                47u);
    if ( v8 )
    {
      v9 = this->m_orders_allocator;
      v8->_M_impl._M_start = 0;
      v8->_M_impl._M_finish = 0;
      v8->_M_impl._M_end_of_storage.m_allocator = v9;
      v8->_M_impl._M_end_of_storage._M_data = 0;
    }
    else
    {
      v8 = 0;
    }
    this->m_deleted_receivers = v8;
  }
  v10 = this->m_orders_allocator;
  v11 = type_info::raw_name(&vostok::sound::sound_order `RTTI Type Descriptor');
  v12 = (vostok::sound::sound_order *)v10->call_malloc(
                                        v10,
                                        16u,
                                        v11,
                                        "vostok::sound::world_user::initialize",
                                        ".\\world_user.cpp",
                                        52u);
  v13 = 0;
  if ( v12 )
  {
    v14 = this->m_orders_allocator;
    v12->m_next_for_orders = 0;
    v12->m_next_for_postponed_orders = 0;
    v12->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::sound_order::`vftable';
    v12->allocator = v14;
    v13 = v12;
  }
  v19 = this->m_orders_allocator;
  v15 = type_info::raw_name(&vostok::sound::sound_order `RTTI Type Descriptor');
  v16 = (vostok::sound::sound_order *)v19->call_malloc(
                                        v19,
                                        16u,
                                        v15,
                                        "vostok::sound::world_user::initialize",
                                        ".\\world_user.cpp",
                                        51u);
  v17 = 0;
  if ( v16 )
  {
    v18 = this->m_orders_allocator;
    v16->m_next_for_orders = 0;
    v16->m_next_for_postponed_orders = 0;
    v16->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::sound_order::`vftable';
    v16->allocator = v18;
    v17 = v16;
  }
  _InterlockedExchange(&this->m_channel.orders.m_forward_queue.m_push_thread_id, GetCurrentThreadId());
  v13->m_next_for_orders = 0;
  this->m_channel.orders.m_forward_queue.m_tail = v13;
  this->m_channel.orders.m_forward_queue.m_head = v13;
  _InterlockedExchange(&this->m_channel.orders.m_backward_queue.m_pop_thread_id, GetCurrentThreadId());
  v17->m_next_for_orders = 0;
  this->m_channel.orders.m_backward_queue.m_tail = v17;
  this->m_channel.orders.m_backward_queue.m_head = v17;
  _InterlockedExchange(&this->m_channel.responses.m_forward_queue.m_pop_thread_id, GetCurrentThreadId());
  _InterlockedExchange(&this->m_channel.responses.m_backward_queue.m_push_thread_id, GetCurrentThreadId());
}
