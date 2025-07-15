void __thiscall survarium::weapon_core_shotgun_reload_finish_substate::initialize(
        survarium::weapon_core_shotgun_reload_finish_substate *this)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v4; // [esp+8h] [ebp-7Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+4Ch] [ebp-38h] BYREF
  vostok::animation::callback_return_type_enum (__thiscall *f)(survarium::weapon_core_shotgun_reload_finish_substate *, survarium::game_camera *); // [esp+5Ch] [ebp-28h]
  int f_4; // [esp+60h] [ebp-24h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> animation_callback; // [esp+64h] [ebp-20h] BYREF

  f = survarium::weapon_core_shotgun_reload_finish_substate::on_animation_end;
  f_4 = 0;
  v1 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core_shotgun_reload_finish_substate::on_animation_end,
         (survarium::weapon_core_animation_end_aware_state *)this);
  v4 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v1;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v1->f_.f_),
    &animation_callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_shotgun_reload_finish_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_shotgun_reload_finish_substate *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v4,
         &animation_callback.functor) )
  {
    animation_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_shotgun_reload_finish_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_shotgun_reload_finish_substate *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                                       + 1);
  }
  else
  {
    animation_callback.vtable = 0;
  }
  survarium::weapon_core::set_animation_callback(this->m_weapon, channel_id_on_animation_end, this, &animation_callback);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&animation_callback);
}
