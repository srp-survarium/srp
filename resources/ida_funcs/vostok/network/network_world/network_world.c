void __thiscall vostok::network::network_world::network_world(
        vostok::network::network_world *this,
        vostok::network::engine *engine,
        vostok::memory::base_allocator *orders_allocator)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  boost::asio::io_service *v5; // eax
  survarium::game_camera *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // eax
  survarium::game_camera *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // eax
  vostok::network::response *backward_queue_initial_value; // [esp+4h] [ebp-84h]
  boost::asio::io_service *v11; // [esp+8h] [ebp-80h]
  void *v13; // [esp+10h] [ebp-78h]
  void *v14; // [esp+18h] [ebp-70h]
  vostok::memory::doug_lea_allocator *owner_allocator; // [esp+20h] [ebp-68h]
  void *_Where; // [esp+2Ch] [ebp-5Ch]
  char v17; // [esp+34h] [ebp-54h]
  boost::function<void __cdecl(void)> v18; // [esp+38h] [ebp-50h] BYREF
  vostok::network::response *v19; // [esp+5Ch] [ebp-2Ch]
  boost::function<void __cdecl(void)> f; // [esp+60h] [ebp-28h] BYREF
  char *v21; // [esp+80h] [ebp-8h]
  boost::asio::io_service *v22; // [esp+84h] [ebp-4h]

  v17 = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_io_service);
  this->__vftable = (vostok::network::network_world_vtbl *)&vostok::network::network_world::`vftable';
  survarium::weapon_user_dead_state::finalize(v3);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0xCu);
  v22 = (boost::asio::io_service *)operator new(0xCu, _Where);
  if ( v22 )
  {
    boost::asio::io_service::io_service(v22);
    v11 = v5;
  }
  else
  {
    v11 = 0;
  }
  this->m_io_service = v11;
  owner_allocator = vostok::network::g_allocator;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_channel);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>(
    &this->m_channel.responses,
    owner_allocator);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>(
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *)&this->m_channel.orders,
    orders_allocator);
  this->m_engine = engine;
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::user_initialize((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *)&this->m_channel.orders);
  survarium::weapon_user_dead_state::finalize(v6);
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v7, 0x28u);
  v21 = (char *)operator new(0x28u, v14);
  if ( v21 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&f, empty_function);
    v17 = 1;
    *(_DWORD *)v21 = &vostok::network::response::`vftable';
    *(_DWORD *)v21 = &vostok::network::functor_response::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)(v21 + 8),
      &f);
    backward_queue_initial_value = (vostok::network::response *)v21;
  }
  else
  {
    backward_queue_initial_value = 0;
  }
  survarium::weapon_user_dead_state::finalize(v8);
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x28u);
  v19 = (vostok::network::response *)operator new(0x28u, v13);
  if ( v19 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&v18, empty_function);
    v17 |= 2u;
    v19->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
    v19->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_response::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v19[1],
      &v18);
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_initialize(
      &this->m_channel.responses,
      v19,
      backward_queue_initial_value);
  }
  else
  {
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_initialize(
      &this->m_channel.responses,
      0,
      backward_queue_initial_value);
  }
  if ( (v17 & 2) != 0 )
  {
    v17 &= ~2u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v18);
  }
  if ( (v17 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
}
