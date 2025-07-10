void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_aimed_state> *this)
{
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *v2; // ecx
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v4; // [esp-8h] [ebp-38h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> animation_callback; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_chamber_a_round_aimed_state_base::initialize(this);
  v4.l_.a1_.t_ = &this->m_sound_effect;
  v4.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  this->m_sound_effect.m_sounds_counter = -1;
  animation_callback.vtable = 0;
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1>>>>(
    v2,
    v4);
  survarium::weapon_core::set_animation_callback(
    this->m_weapon,
    "sound_events",
    &this->m_sound_effect,
    &animation_callback);
  if ( animation_callback.vtable && ((int)animation_callback.vtable & 1) == 0 )
  {
    v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)animation_callback.vtable & 0xFFFFFFFE);
    if ( v3 )
      v3(&animation_callback.functor, &animation_callback.functor, 2);
  }
}
