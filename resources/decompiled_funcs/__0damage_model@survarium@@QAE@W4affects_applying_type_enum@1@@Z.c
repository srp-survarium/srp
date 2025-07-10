void __thiscall survarium::damage_model::damage_model(
        survarium::damage_model *this,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *affects_applying_type)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v8; // [esp-14h] [ebp-E8h]
  boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> v10; // [esp+1Ch] [ebp-B8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v11; // [esp+3Ch] [ebp-98h]
  boost::function0<bool> *other; // [esp+4Ch] [ebp-88h]
  boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> v13; // [esp+70h] [ebp-64h] BYREF
  survarium::game_options *p_m_hand_damaged_subscriber; // [esp+90h] [ebp-44h]
  survarium::game_options *p_m_leg_damaged_subscriber; // [esp+94h] [ebp-40h]
  vostok::intrusive_list<survarium::booster_damage_protector,survarium::booster_damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_damage_protectors; // [esp+98h] [ebp-3Ch]
  void *__t; // [esp+9Ch] [ebp-38h]
  vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_body_parts; // [esp+A0h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v19; // [esp+A4h] [ebp-30h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v20; // [esp+B4h] [ebp-20h] BYREF
  void (__thiscall *f)(survarium::damage_model *, const char *, survarium::hit_affects_type_enum, survarium::affect_event_type_enum); // [esp+CCh] [ebp-8h]
  int f_4; // [esp+D0h] [ebp-4h]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_body_parts);
  this->__vftable = (survarium::damage_model_vtbl *)&survarium::damage_model::`vftable';
  p_m_body_parts = &this->m_body_parts;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_body_parts,
    &this->m_body_parts.m_size);
  survarium::weapon_user_dead_state::finalize(v2);
  this->m_body_parts.m_first = 0;
  p_m_body_parts->m_last = 0;
  __t = &this->m_affect_subscriptions;
  `vector constructor iterator'(
    (char *)&this->m_affect_subscriptions,
    0x30u,
    9,
    (void *(__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  this->m_affects_applying_type = (survarium::affects_applying_type_enum)affects_applying_type;
  p_m_damage_protectors = &this->m_damage_protectors;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    affects_applying_type,
    &this->m_damage_protectors.m_size);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_damage_protectors.m_first = 0;
  p_m_damage_protectors->m_last = 0;
  this->m_last_tick_time_in_ms = 0;
  this->m_last_hit_initiator = -1;
  p_m_leg_damaged_subscriber = (survarium::game_options *)&this->m_leg_damaged_subscriber;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_leg_damaged_subscriber);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v4,
    &this->m_leg_damaged_subscriber.subscription_callback.vtable);
  this->m_leg_damaged_subscriber.next = 0;
  p_m_hand_damaged_subscriber = (survarium::game_options *)&this->m_hand_damaged_subscriber;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_hand_damaged_subscriber);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v5,
    &this->m_hand_damaged_subscriber.subscription_callback.vtable);
  this->m_hand_damaged_subscriber.next = 0;
  this->m_broken_legs_count[0] = 0;
  this->m_broken_legs_count[1] = 0;
  this->m_broken_hands_count[0] = 0;
  this->m_broken_hands_count[1] = 0;
  f = survarium::damage_model::on_broken_limb_affect;
  f_4 = 0;
  v11 = *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v20.l_, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::damage_model::on_broken_limb_affect, (survarium::weapon_core_animation_end_aware_state *)this);
  other = (boost::function0<bool> *)&this->m_leg_damaged_subscriber;
  boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>(
    &v13,
    v11,
    0);
  boost::function0<bool>::swap(
    (boost::function0<bool> *)&v13,
    (boost::function0<bool> *)&this->m_leg_damaged_subscriber);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v13);
  LODWORD(v20.f_.f_) = survarium::damage_model::on_broken_limb_affect;
  HIDWORD(v20.f_.f_) = 0;
  v8 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v19,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::damage_model::on_broken_limb_affect,
          (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>(
    &v10,
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > >)v8,
    0);
  boost::function0<bool>::swap(
    (boost::function0<bool> *)&v10,
    (boost::function0<bool> *)&this->m_hand_damaged_subscriber);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v7,
    (int *)&v10);
  survarium::damage_model::subscribe_on_affect(
    this,
    affects_type_leg_damage,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_leg_damaged_subscriber);
  survarium::damage_model::subscribe_on_affect(
    this,
    affects_type_hand_damage,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_hand_damaged_subscriber);
}
