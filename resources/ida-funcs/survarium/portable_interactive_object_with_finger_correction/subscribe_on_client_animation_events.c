void __thiscall survarium::portable_interactive_object_with_finger_correction::subscribe_on_client_animation_events(
        survarium::portable_interactive_object_with_finger_correction *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object_with_finger_correction,vostok::animation::animation_callback_params &,enum vostok::animation::fingers_to_weapon_corrector::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object_with_finger_correction *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::fingers_to_weapon_corrector::hands_enum> > > v4; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object_with_finger_correction,vostok::animation::animation_callback_params &,enum vostok::animation::fingers_to_weapon_corrector::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object_with_finger_correction *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::fingers_to_weapon_corrector::hands_enum> > > v5; // [esp-14h] [ebp-44h]
  const void *v6; // [esp+0h] [ebp-30h]
  const void *v7; // [esp+0h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+Ch] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  survarium::portable_interactive_object::subscribe_on_client_animation_events(this);
  *(_QWORD *)&f.functor.obj_ptr = (unsigned int)this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object_with_finger_correction::on_hand_correction_event;
  (&f.vtable)[1] = 0;
  HIDWORD(v4.f_.f_) = survarium::portable_interactive_object_with_finger_correction::on_hand_correction_event;
  v4.l_ = (boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object_with_finger_correction *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::fingers_to_weapon_corrector::hands_enum> >)__PAIR64__((unsigned int)this, 0);
  LODWORD(v4.f_.f_) = &f;
  animation.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v4,
    0);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&f,
    "left_hand_corrector",
    &f,
    this,
    &animation,
    (unsigned __int8)this->m_user,
    v6);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v2, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
  (&f.vtable)[1] = 0;
  *(_QWORD *)&f.functor.obj_ptr = (unsigned int)this | 0x100000000LL;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object_with_finger_correction::on_hand_correction_event;
  HIDWORD(v5.f_.f_) = survarium::portable_interactive_object_with_finger_correction::on_hand_correction_event;
  v5.l_ = (boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object_with_finger_correction *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::fingers_to_weapon_corrector::hands_enum> >)__PAIR64__((unsigned int)this, 0);
  LODWORD(v5.f_.f_) = &f;
  animation.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v5,
    1);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&f,
    "right_hand_corrector",
    &f,
    this,
    &animation,
    (unsigned __int8)this->m_user,
    v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
}
