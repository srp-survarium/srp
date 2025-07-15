void __thiscall survarium::weapon_core_melee_state::subscribe_animation_player(
        survarium::weapon_core_melee_state *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_melee_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_melee_state *>,boost::arg<1> > > v4; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_melee_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_melee_state *>,boost::arg<1> > > v5; // [esp-14h] [ebp-44h]
  const void *v6; // [esp+0h] [ebp-30h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v7; // [esp+Ch] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  (&f.vtable)[1] = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_melee_state::on_animation_end;
  HIDWORD(v4.f_.f_) = survarium::weapon_core_melee_state::on_animation_end;
  *(_QWORD *)&v4.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v4.f_.f_) = &f;
  v7.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v4,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&f,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
    &f,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v7,
    this->m_weapon->m_user);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v2, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  (&f.vtable)[1] = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_melee_state::on_shot_event;
  HIDWORD(v5.f_.f_) = survarium::weapon_core_melee_state::on_shot_event;
  *(_QWORD *)&v5.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v5.f_.f_) = &f;
  v7.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v5,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&f,
    (int)this->m_weapon->m_user,
    "shoot",
    &f,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v7,
    this->m_weapon->m_user,
    v6);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
}
