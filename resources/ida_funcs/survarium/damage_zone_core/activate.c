void __thiscall survarium::damage_zone_core::activate(
        survarium::damage_zone_core *this,
        survarium::zone_group *owner,
        vostok::physics::world *p_world,
        survarium::scheduler *scheduler)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v4; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v7; // [esp+70h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+9Ch] [ebp-38h] BYREF
  int (__thiscall *f)(void *); // [esp+ACh] [ebp-28h]
  int f_4; // [esp+B0h] [ebp-24h]
  boost::function<void __cdecl(unsigned int,unsigned int)> callback; // [esp+B4h] [ebp-20h] BYREF

  this->m_physics_world = p_world;
  survarium::collision_sensor::insert(this, p_world);
  this->m_owner = owner;
  this->m_accumulated_hit_time_ms = 0;
  this->m_scheduler = scheduler;
  f =  __thiscall survarium::booby_trap_core::`vcall'{16,{flat}};
  f_4 = 0;
  v4 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int) __thiscall survarium::booby_trap_core::`vcall'{16,{flat}},
         (survarium::weapon_core_animation_end_aware_state *)this);
  v7 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v4;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v4->f_.f_),
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function2<void,unsigned int,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_core *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
         v7,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,unsigned int,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_core *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  survarium::scheduler::register_on_frame(
    (survarium::scheduler *)&callback,
    1,
    scheduler,
    &this->m_scheduler_identifier);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (int *)&callback);
}
