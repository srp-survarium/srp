void __thiscall survarium::breath_vibration_calculator::initialize_logic(survarium::breath_vibration_calculator *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v10; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  survarium::breath_state *v12; // [esp+4h] [ebp-128h]
  survarium::breath_state *v13; // [esp+8h] [ebp-124h]
  survarium::breath_state *v14; // [esp+Ch] [ebp-120h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > > f; // [esp+14h] [ebp-118h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool> > > v17; // [esp+1Ch] [ebp-110h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool> > > v18; // [esp+28h] [ebp-104h]
  void *v19; // [esp+34h] [ebp-F8h]
  void *v20; // [esp+3Ch] [ebp-F0h]
  void *_Where; // [esp+44h] [ebp-E8h]
  boost::function0<bool> v22; // [esp+4Ch] [ebp-E0h] BYREF
  boost::function0<bool> v23; // [esp+6Ch] [ebp-C0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v24; // [esp+8Ch] [ebp-A0h] BYREF
  boost::function0<bool> v25; // [esp+94h] [ebp-98h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<unsigned char>,boost::arg<1> > > v26; // [esp+B8h] [ebp-74h] BYREF
  boost::function0<bool> v27; // [esp+C4h] [ebp-68h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<unsigned char>,boost::arg<1> > > result; // [esp+E8h] [ebp-44h] BYREF
  boost::function0<bool> v29; // [esp+F4h] [ebp-38h] BYREF
  survarium::breath_state *v30; // [esp+114h] [ebp-18h]
  survarium::breath_state *v31; // [esp+118h] [ebp-14h]
  survarium::breath_state *v32; // [esp+11Ch] [ebp-10h]
  survarium::breath_state *holding; // [esp+120h] [ebp-Ch]
  survarium::breath_state *normal; // [esp+124h] [ebp-8h]
  survarium::breath_state *shortbreathing; // [esp+128h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, 0x28u);
  v32 = (survarium::breath_state *)operator new(0x28u, _Where);
  if ( v32 )
  {
    survarium::breath_state::breath_state(v32, &this->m_breath_holding_reserve);
    v32->__vftable = (survarium::breath_state_vtbl *)&stru_977EF0.vostok::resources::unmanaged_intrusive_base;
    LODWORD(v32->m_multiplier) = clear_value;
    v2 = (survarium::game_camera *)v32;
    v14 = v32;
  }
  else
  {
    v14 = 0;
  }
  normal = v14;
  survarium::weapon_user_dead_state::finalize(v2);
  v20 = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x28u);
  v31 = (survarium::breath_state *)operator new(0x28u, v20);
  if ( v31 )
  {
    survarium::breath_state::breath_state(v31, &this->m_breath_holding_reserve);
    v31->__vftable = (survarium::breath_state_vtbl *)&stru_977EF0.m_prev_in_global_list;
    v13 = v31;
  }
  else
  {
    v13 = 0;
  }
  holding = v13;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v13);
  v19 = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x2Cu);
  v30 = (survarium::breath_state *)operator new(0x2Cu, v19);
  if ( v30 )
  {
    survarium::breath_state::breath_state(v30, &this->m_breath_holding_reserve);
    v30->__vftable = (survarium::breath_state_vtbl *)&survarium::breath_state_shortbreathing::`vftable';
    v30[1].__vftable = (survarium::breath_state_vtbl *)clear_value;
    v12 = v30;
  }
  else
  {
    v12 = 0;
  }
  shortbreathing = v12;
  vostok::ai::fsm::add_state(&this->m_logic, normal);
  vostok::ai::fsm::add_state(&this->m_logic, holding);
  vostok::ai::fsm::add_state(&this->m_logic, v12);
  v18 = *boost::bind<bool,survarium::breath_vibration_calculator,bool,survarium::breath_vibration_calculator *,bool>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool> > > *)&result,
           (bool (__thiscall *)(survarium::breath_vibration_calculator *, bool))survarium::breath_vibration_calculator::hold_button_state_equals_to,
           (vostok::network::match_client *)this,
           1u);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v18.f_.f_,
    &v29);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool>>>>(
    &v29,
    v18);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    normal,
    holding,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (int *)&v29);
  v17 = *boost::bind<bool,survarium::breath_vibration_calculator,bool,survarium::breath_vibration_calculator *,bool>(
           (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool> > > *)&v26,
           (bool (__thiscall *)(survarium::breath_vibration_calculator *, bool))survarium::breath_vibration_calculator::hold_button_state_equals_to,
           (vostok::network::match_client *)this,
           0);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v17.l_.a1_.t_,
    &v27);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::breath_vibration_calculator,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_vibration_calculator *>,boost::_bi::value<bool>>>>(
    &v27,
    v17);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    holding,
    normal,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v27);
  f = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v24, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::breath_vibration_calculator::insufficient_breath, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &v25);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::breath_vibration_calculator>,boost::_bi::list1<boost::_bi::value<survarium::breath_vibration_calculator *>>>>(
    &v25,
    f);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    holding,
    shortbreathing,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v25);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v7,
    (int *)&v25);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, &v23);
  boost::function0<bool>::assign_to<bool (__cdecl *)(void)>(&v23, (bool (__cdecl *)())survarium::true_predicate);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    shortbreathing,
    normal,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v23);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v9,
    (int *)&v23);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v10, &v22);
  boost::function0<bool>::assign_to<bool (__cdecl *)(void)>(&v22, (bool (__cdecl *)())survarium::true_predicate);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    shortbreathing,
    holding,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v11,
    (int *)&v22);
}
