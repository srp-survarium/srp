void __thiscall vostok::ai::fsm::add_transition(
        vostok::ai::fsm *this,
        vostok::ai::fsm_state *from,
        vostok::ai::fsm_state *to,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *transition_predicate)
{
  vostok::memory::doug_lea_allocator *v4; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  vostok::ai::fsm_state_transition *v7; // [esp+4h] [ebp-60h]
  boost::function0<bool> v8; // [esp+34h] [ebp-30h] BYREF
  void *_Where; // [esp+54h] [ebp-10h]
  vostok::memory::doug_lea_allocator *v10; // [esp+58h] [ebp-Ch]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v11; // [esp+5Ch] [ebp-8h]
  vostok::ai::fsm_state_transition *transition; // [esp+60h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v10 = v4;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x28u);
  v11 = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)operator new(0x28u, _Where);
  if ( v11 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, v11);
    v5 = v11;
    v7 = (vostok::ai::fsm_state_transition *)v11;
  }
  else
  {
    v7 = 0;
  }
  transition = v7;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &v8);
  boost::function0<bool>::assign_to_own(&v8, transition_predicate);
  boost::function0<bool>::swap(&v8, &transition->predicate);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v8);
  transition->target_state = to;
  vostok::intrusive_list<vostok::ai::fsm_state_transition,vostok::ai::fsm_state_transition *,36,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &from->transitions,
    (survarium::game_camera *)transition,
    0);
}
