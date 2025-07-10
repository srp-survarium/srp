void __thiscall vostok::network::network_world::initialize(vostok::network::network_world *this)
{
  vostok::memory::base_allocator *v1; // eax
  survarium::game_camera *v2; // ecx
  vostok::memory::base_allocator *v3; // eax
  vostok::network::response *backward_queue_initial_value; // [esp+4h] [ebp-80h]
  void *v6; // [esp+10h] [ebp-74h]
  void *_Where; // [esp+20h] [ebp-64h]
  char v8; // [esp+30h] [ebp-54h]
  boost::function<void __cdecl(void)> v9; // [esp+34h] [ebp-50h] BYREF
  vostok::network::response *v10; // [esp+58h] [ebp-2Ch]
  boost::function<void __cdecl(void)> f; // [esp+5Ch] [ebp-28h] BYREF
  char *v12; // [esp+80h] [ebp-4h]

  v8 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x28u);
  v12 = (char *)operator new(0x28u, _Where);
  if ( v12 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&f, empty_function);
    v8 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v12 + 4));
    *(_DWORD *)v12 = &vostok::network::order::`vftable';
    *(_DWORD *)v12 = &vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)(v12 + 8),
      &f);
    v2 = (survarium::game_camera *)v12;
    backward_queue_initial_value = (vostok::network::response *)v12;
  }
  else
  {
    backward_queue_initial_value = 0;
  }
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_channel.orders.m_owner_allocator);
  v6 = vostok::memory::base_allocator::malloc_impl(v3, 0x28u);
  v10 = (vostok::network::response *)operator new(0x28u, v6);
  if ( v10 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&v9, empty_function);
    v8 |= 2u;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10->next_for_responses);
    v10->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v10->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v10[1],
      &v9);
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_initialize(
      (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *)&this->m_channel.orders,
      v10,
      backward_queue_initial_value);
  }
  else
  {
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>>::owner_initialize(
      (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *)&this->m_channel.orders,
      0,
      backward_queue_initial_value);
  }
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v9);
  }
  if ( (v8 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::user_initialize(&this->m_channel.responses);
}
