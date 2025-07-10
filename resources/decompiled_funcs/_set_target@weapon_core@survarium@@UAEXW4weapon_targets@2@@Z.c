void __thiscall survarium::weapon_core::set_target(survarium::weapon_core *this, survarium::weapon_targets target)
{
  survarium::weapon_core *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::weapon_core *v4; // ecx
  survarium::base_player *v5; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  survarium::weapon_core *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::weapon_core *v10; // ecx
  survarium::game_camera *v11; // ecx
  int v12; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  survarium::game_camera *v14; // ecx
  survarium::inventory_item *v15; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v16; // [esp-14h] [ebp-11Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v17; // [esp-14h] [ebp-11Ch]
  survarium::base_player *v18; // [esp-4h] [ebp-10Ch]
  bool v19; // [esp+4h] [ebp-104h]
  survarium::base_player *v20; // [esp+8h] [ebp-100h]
  survarium::base_player *user; // [esp+Ch] [ebp-FCh]
  survarium::weapon_user_animations_container *v23; // [esp+44h] [ebp-C4h]
  survarium::weapon_user_animations_container *m_object; // [esp+60h] [ebp-A8h]
  char v25; // [esp+78h] [ebp-90h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+7Ch] [ebp-8Ch] BYREF
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp+80h] [ebp-88h] BYREF
  bool v28; // [esp+87h] [ebp-81h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v29; // [esp+88h] [ebp-80h] BYREF
  int (__thiscall *v30)(survarium::weapon_core *, vostok::animation::animation_callback_params *); // [esp+98h] [ebp-70h]
  int v31; // [esp+9Ch] [ebp-6Ch]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v32; // [esp+A0h] [ebp-68h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v33; // [esp+C4h] [ebp-44h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+C8h] [ebp-40h] BYREF
  int (__thiscall *f)(survarium::weapon_core *, vostok::animation::animation_callback_params *); // [esp+D8h] [ebp-30h]
  int f_4; // [esp+DCh] [ebp-2Ch]
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> v37; // [esp+E0h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v38; // [esp+104h] [ebp-4h] BYREF

  if ( target == weapon_target_fire || target == weapon_target_aim_fire )
  {
    if ( this->m_is_round_chambered + this->m_ammo_in_magazine )
    {
      if ( !survarium::weapon_core::is_ready_to_shoot(this) )
      {
        if ( target == weapon_target_fire )
          target = weapon_target_idle;
        else
          target = weapon_target_aim;
      }
    }
    else
    {
      target = weapon_target_reload;
    }
  }
  if ( !this->m_is_in_sprint_transition && this->is_sprinting((survarium::interactive_object *)this) )
  {
    this->m_is_in_sprint_transition = 1;
    f = survarium::weapon_core::on_sprint_animation_ended;
    f_4 = 0;
    v16 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::on_sprint_animation_ended,
             (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
      &v37,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v16,
      0);
    user = survarium::weapon_core::get_user(v2, (int)this);
    survarium::weapon_user_dead_state::finalize(v3);
    m_object = this->m_user_animations_selector.m_animations.m_object;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v38,
      m_object->m_sprint_animations[0]);
    v5 = survarium::weapon_core::get_user(v4, (int)this);
    user->subscribe_animation_player(
      user,
      channel_id_on_animation_lexeme_end,
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v37,
      this,
      &v38,
      v5);
    vostok::animation::mixing::animation_interval::~animation_interval(&v38);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v6,
      (int *)&v37);
    v30 = survarium::weapon_core::on_sprint_animation_ended;
    v31 = 0;
    v17 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v29,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::on_sprint_animation_ended,
             (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
      &v32,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > >)v17,
      0);
    v20 = survarium::weapon_core::get_user(v7, (int)this);
    survarium::weapon_user_dead_state::finalize(v8);
    v23 = this->m_user_animations_selector.m_animations.m_object;
    survarium::weapon_user_dead_state::finalize(v9);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      &v33,
      v23->m_sprint_animations[1]);
    v18 = survarium::weapon_core::get_user(v10, (int)this);
    survarium::weapon_user_dead_state::finalize(v11);
    v20->subscribe_animation_player(
      v20,
      channel_id_on_animation_lexeme_end,
      (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v32,
      (const void *)(v12 + 1),
      &v33,
      v18);
    vostok::animation::mixing::animation_interval::~animation_interval(&v33);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v13,
      (int *)&v32);
  }
  if ( this->m_is_in_sprint_transition
    || survarium::weapon_user_animations_selector::is_in_jump(&this->m_user_animations_selector) )
  {
    if ( target == weapon_target_fire )
    {
      target = weapon_target_idle;
    }
    else if ( target == weapon_target_aim_fire )
    {
      target = weapon_target_aim;
    }
  }
  if ( target == weapon_target_reload && !survarium::weapon_core::ready_to_reload(this) )
  {
    v25 = 1;
    v27.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v27,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
    v19 = 1;
    if ( v27.m_object )
    {
      v25 = 3;
      v26.m_object = 0;
      vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v26,
        (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition);
      survarium::weapon_user_dead_state::finalize(v14);
      if ( survarium::inventory_item::amount(v15, (int)v26.m_object) )
        v19 = 0;
    }
    v28 = v19;
    if ( (v25 & 2) != 0 )
    {
      v25 &= ~2u;
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
    }
    if ( (v25 & 1) != 0 )
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
    if ( v28 )
      this->on_ammo_empty(this);
    if ( this->m_target == weapon_target_aim_fire || this->m_target == weapon_target_aim )
      target = weapon_target_aim;
    else
      target = weapon_target_idle;
  }
  this->m_target = target;
}
