void __thiscall survarium::portable_interactive_object::activate(
        survarium::portable_interactive_object *this,
        const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *item_skeleton)
{
  survarium::base_player *v3; // ecx
  survarium::base_player *v4; // ecx
  survarium::base_player *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  survarium::base_player *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::animation::hand_to_weapon_ik_solver *v9; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object,vostok::animation::animation_callback_params &,enum vostok::animation::hand_to_weapon_ik_solver::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::hand_to_weapon_ik_solver::hands_enum> > > v10; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object,vostok::animation::animation_callback_params &,enum vostok::animation::hand_to_weapon_ik_solver::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::hand_to_weapon_ik_solver::hands_enum> > > v11; // [esp-14h] [ebp-44h]
  const void *v12; // [esp+0h] [ebp-30h]
  const void *v13; // [esp+0h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+Ch] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  survarium::portable_interactive_object_core::activate(this, item_skeleton);
  survarium::base_player::unsubscribe_animation_player(v3, (int)this->m_user, "left_hand_ik", this);
  survarium::base_player::unsubscribe_animation_player(v4, (int)this->m_user, "right_hand_ik", this);
  *(_QWORD *)&f.functor.obj_ptr = (unsigned int)this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object::on_hand_ik_event;
  (&f.vtable)[1] = 0;
  HIDWORD(v10.f_.f_) = survarium::portable_interactive_object::on_hand_ik_event;
  v10.l_ = (boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::hand_to_weapon_ik_solver::hands_enum> >)__PAIR64__((unsigned int)this, 0);
  LODWORD(v10.f_.f_) = &f;
  animation.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v10,
    0);
  survarium::base_player::subscribe_animation_player(v5, "left_hand_ik", &f, this, &animation, 0, v12);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
  animation.m_object = 0;
  *(_QWORD *)&f.functor.obj_ptr = (unsigned int)this | 0x100000000LL;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object::on_hand_ik_event;
  (&f.vtable)[1] = 0;
  HIDWORD(v11.f_.f_) = survarium::portable_interactive_object::on_hand_ik_event;
  v11.l_ = (boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::hand_to_weapon_ik_solver::hands_enum> >)__PAIR64__((unsigned int)this, 0);
  LODWORD(v11.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v11,
    1);
  survarium::base_player::subscribe_animation_player(v7, "right_hand_ik", &f, this, &animation, 0, v13);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
  vostok::animation::hand_to_weapon_ik_solver::activate(v9, &this->m_hand_ik_solver, item_skeleton->m_object);
}
