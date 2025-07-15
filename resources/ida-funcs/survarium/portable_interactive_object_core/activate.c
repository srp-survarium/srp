void __thiscall survarium::portable_interactive_object_core::activate(
        survarium::portable_interactive_object_core *this,
        const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *__formal)
{
  survarium::base_player *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  survarium::base_player *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  survarium::base_player *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  survarium::base_player *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v11; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v12; // eax
  survarium::base_player *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v15; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v16; // eax
  survarium::base_player *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  survarium::weapon_user_animations_selector *v19; // ecx
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v20; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::portable_interactive_object_core *>,boost::arg<1> > > v21; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::portable_interactive_object_core *>,boost::arg<1> > > v22; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::portable_interactive_object_core *>,boost::arg<1> > > v23; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::portable_interactive_object_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::portable_interactive_object_core *>,boost::arg<1> > > v24; // [esp-14h] [ebp-44h]
  const void *v25; // [esp+0h] [ebp-30h]
  const void *v26; // [esp+0h] [ebp-30h]
  const void *v27; // [esp+0h] [ebp-30h]
  const void *v28; // [esp+0h] [ebp-30h]
  const void *v29; // [esp+0h] [ebp-30h]
  const void *v30; // [esp+0h] [ebp-30h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v31; // [esp+Ch] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  (&f.vtable)[1] = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object_core::on_animation_ik_interval;
  HIDWORD(v21.f_.f_) = survarium::portable_interactive_object_core::on_animation_ik_interval;
  *(_QWORD *)&v21.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v21.f_.f_) = &f;
  v31.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v21,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::base_player::subscribe_animation_player(
    v3,
    (int)this->m_user,
    "Left toe",
    &f,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v31,
    0,
    v25);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
  v31.m_object = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object_core::on_animation_ik_interval;
  (&f.vtable)[1] = 0;
  HIDWORD(v22.f_.f_) = survarium::portable_interactive_object_core::on_animation_ik_interval;
  *(_QWORD *)&v22.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v22.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v22,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::base_player::subscribe_animation_player(
    v5,
    (int)this->m_user,
    "Left heel",
    &f,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v31,
    0,
    v26);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
  v31.m_object = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object_core::on_animation_ik_interval;
  (&f.vtable)[1] = 0;
  HIDWORD(v23.f_.f_) = survarium::portable_interactive_object_core::on_animation_ik_interval;
  *(_QWORD *)&v23.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v23.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v23,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::base_player::subscribe_animation_player(
    v7,
    (int)this->m_user,
    "Right toe",
    &f,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v31,
    0,
    v27);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
  v31.m_object = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::portable_interactive_object_core::on_animation_ik_interval;
  (&f.vtable)[1] = 0;
  HIDWORD(v24.f_.f_) = survarium::portable_interactive_object_core::on_animation_ik_interval;
  *(_QWORD *)&v24.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v24.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v24,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::base_player::subscribe_animation_player(
    v9,
    (int)this->m_user,
    "Right heel",
    &f,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v31,
    0,
    v28);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
  v31.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v11,
    &f);
  survarium::base_player::subscribe_animation_player(
    v13,
    (int)this->m_user,
    "left_hand_ik",
    v12,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v31,
    0,
    v29);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
  v31.m_object = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v15,
    &f);
  survarium::base_player::subscribe_animation_player(
    v17,
    (int)this->m_user,
    "right_hand_ik",
    v16,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v31,
    0,
    v30);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v18,
    (int *)&f);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
  this->subscribe_on_client_animation_events(this);
  survarium::weapon_user_animations_selector::activate(v19, (int)&this->m_user_animations_selector);
  v20 = this->m_user->damage_model(&this->m_user->survarium::inventory_holder);
  survarium::damage_model::subscribe_on_damage(
    v20->m_object,
    ranged_damage,
    &this->m_user_hit_animations_selector.m_damage_subscriber);
  this->m_legs_ik_solver.m_character_controller = *(vostok::physics::bt_character_controller **)((char *)&dword_10E74
                                                                                               + (unsigned int)this->m_user);
}
