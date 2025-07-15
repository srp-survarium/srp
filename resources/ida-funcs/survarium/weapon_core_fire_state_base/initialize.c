void __thiscall survarium::weapon_core_fire_state_base::initialize(survarium::weapon_core_fire_state_base *this)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  survarium::game_camera *m_bullets_in_queue; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_fire_state_base,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_fire_state_base *>,boost::arg<1> > > v5; // [esp+Ch] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+24h] [ebp-38h] BYREF
  int (__thiscall *f)(void *); // [esp+34h] [ebp-28h]
  int f_4; // [esp+38h] [ebp-24h]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v9; // [esp+3Ch] [ebp-20h] BYREF

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  f =  __thiscall survarium::weapon_core_fire_state_base::`vcall'{36,{flat}};
  f_4 = 0;
  v1 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int) __thiscall survarium::weapon_core_fire_state_base::`vcall'{36,{flat}},
         this);
  v5 = *(boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_fire_state_base,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_fire_state_base *>,boost::arg<1> > > *)v1;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v1->f_.f_),
    &v9);
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_fire_state_base,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_fire_state_base *>,boost::arg<1>>>>(
    &v9,
    v5);
  survarium::weapon_core::set_animation_callback(
    this->m_weapon,
    "shoot",
    this,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v9);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&v9);
  m_bullets_in_queue = (survarium::game_camera *)this->m_weapon->m_bullets_in_queue;
  this->m_playback_type = (unsigned int)m_bullets_in_queue <= 1;
  survarium::weapon_user_dead_state::finalize(m_bullets_in_queue);
  *this->m_is_firing_ptr = 1;
}
