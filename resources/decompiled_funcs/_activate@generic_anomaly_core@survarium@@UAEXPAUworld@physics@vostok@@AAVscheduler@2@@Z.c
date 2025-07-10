void __thiscall survarium::generic_anomaly_core::activate(
        survarium::generic_anomaly_core *this,
        vostok::physics::world *world,
        survarium::scheduler *scheduler)
{
  survarium::game_camera *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  unsigned int v5; // eax
  survarium::game_camera *v6; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  boost::arg<1> *v10; // [esp+Ch] [ebp-64h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v11; // [esp+1Ch] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+30h] [ebp-40h] BYREF
  int (__thiscall *f)(void *); // [esp+40h] [ebp-30h]
  int f_4; // [esp+44h] [ebp-2Ch]
  int callback[2]; // [esp+48h] [ebp-28h] BYREF
  boost::detail::function::function_buffer callback_8; // [esp+50h] [ebp-20h] BYREF
  char v17; // [esp+6Ah] [ebp-6h]
  char v18; // [esp+6Bh] [ebp-5h]
  unsigned int a; // [esp+6Ch] [ebp-4h]

  v18 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v17 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_physics_world = world;
  this->m_scheduler = scheduler;
  f =  __thiscall survarium::booby_trap_core::`vcall'{16,{flat}};
  f_4 = 0;
  v11 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int) __thiscall survarium::booby_trap_core::`vcall'{16,{flat}},
           (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v11.l_.a1_.t_,
    callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function2<void,unsigned int,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::generic_anomaly_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::generic_anomaly_core *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > >)v11,
         &callback_8) )
  {
    callback[0] = (int)&`boost::function2<void,unsigned int,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::generic_anomaly_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::generic_anomaly_core *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                + 1;
  }
  else
  {
    callback[0] = 0;
  }
  survarium::scheduler::register_on_frame(
    (survarium::scheduler *)callback,
    1,
    this->m_scheduler,
    &this->m_scheduler_identifier);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    callback);
  for ( a = 0; ; ++a )
  {
    v5 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_artefact_containers._M_impl);
    if ( a >= v5 )
      break;
    survarium::weapon_user_dead_state::finalize(v6);
    v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           v7,
           (int)&this->m_artefact_containers);
    v10 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref((boost::arg<1> *)&v8[a]);
    (*(void (__thiscall **)(_DWORD, survarium::generic_anomaly_core *, vostok::physics::world *, survarium::scheduler *))(**(_DWORD **)v10 + 32))(
      *(_DWORD *)v10,
      this,
      world,
      scheduler);
  }
  this->m_was_zone_trigger_event = 0;
  this->m_was_shoot_trigger_event = 0;
  survarium::generic_anomaly_core::spawn_artefacts(this);
}
