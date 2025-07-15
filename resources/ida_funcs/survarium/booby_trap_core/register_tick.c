void __thiscall survarium::booby_trap_core::register_tick(
        survarium::booby_trap_core *this,
        survarium::scheduler *scheduler)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  void (__thiscall *__ptr64 v3)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *); // [esp-14h] [ebp-E8h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v5; // [esp+70h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+9Ch] [ebp-38h] BYREF
  int (__thiscall *f)(void *); // [esp+ACh] [ebp-28h]
  int f_4; // [esp+B0h] [ebp-24h]
  boost::function<void __cdecl(unsigned int,unsigned int)> callback; // [esp+B4h] [ebp-20h] BYREF

  f =  __thiscall survarium::booby_trap_core::`vcall'{16,{flat}};
  f_4 = 292;
  HIDWORD(v3) = 292;
  LODWORD(v3) =  __thiscall survarium::booby_trap_core::`vcall'{16,{flat}};
  v5 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          v3,
          (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v5.l_.a1_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function2<void,unsigned int,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_core *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > >)v5,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,unsigned int,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_core *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
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
    v2,
    (int *)&callback);
}
