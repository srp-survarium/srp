void __thiscall survarium::weapon_core_shotgun_reload_state::initialize_logic(
        survarium::weapon_core_shotgun_reload_state *this,
        survarium::weapon_core_shotgun_reload_base_substate *reload_start,
        survarium::weapon_core_shotgun_reload_base_substate *reload_one_round,
        survarium::weapon_core_shotgun_reload_base_substate *reload_finish)
{
  vostok::memory::doug_lea_allocator *v4; // eax
  vostok::ai::fsm *v5; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v6; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v8; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  vostok::ai::fsm *v10; // [esp+4h] [ebp-D4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v12; // [esp+Ch] [ebp-CCh]
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> f; // [esp+50h] [ebp-88h]
  void *_Where; // [esp+68h] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v15; // [esp+70h] [ebp-68h] BYREF
  char (__thiscall *v16)(survarium::weapon_core_shotgun_reload_state *); // [esp+80h] [ebp-58h]
  int v17; // [esp+84h] [ebp-54h]
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+88h] [ebp-50h] BYREF
  boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> result; // [esp+A8h] [ebp-30h] BYREF
  boost::function0<bool> v20; // [esp+B0h] [ebp-28h] BYREF
  vostok::ai::fsm *v21; // [esp+D4h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x14u);
  v21 = (vostok::ai::fsm *)operator new(0x14u, _Where);
  if ( v21 )
  {
    vostok::ai::fsm::fsm(v21);
    v10 = v5;
  }
  else
  {
    v10 = 0;
  }
  this->m_logic = v10;
  reload_start->m_animation_playback_state = &this->m_animation_playback_state;
  reload_one_round->m_animation_playback_state = &this->m_animation_playback_state;
  reload_finish->m_animation_playback_state = &this->m_animation_playback_state;
  vostok::ai::fsm::add_state(this->m_logic, reload_start);
  vostok::ai::fsm::add_state(this->m_logic, reload_one_round);
  vostok::ai::fsm::add_state(this->m_logic, reload_finish);
  reload_finish[1].vostok::ai::fsm_state::__vftable = (survarium::weapon_core_shotgun_reload_base_substate_vtbl *)&this->m_animation_has_been_ended;
  f = *boost::bind<bool>(&result, (bool (__cdecl *)())survarium::true_predicate);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v6, &v20);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>(&v20, f);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    reload_start,
    reload_one_round,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v7,
    (int *)&v20);
  v16 = survarium::weapon_core_shotgun_reload_state::finish_reload_predicate;
  v17 = 0;
  v8 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v15,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core_shotgun_reload_state::finish_reload_predicate,
         (survarium::weapon_core_animation_end_aware_state *)this);
  v12 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v8;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v8->f_.f_),
    &transition_predicate);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core_shotgun_reload_state>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core_shotgun_reload_state *>>>>'::`2'::stored_vtable,
         v12,
         &transition_predicate.functor) )
  {
    transition_predicate.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core_shotgun_reload_state>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core_shotgun_reload_state *>>>>'::`2'::stored_vtable.base.manager
                                                                         + 1);
  }
  else
  {
    transition_predicate.vtable = 0;
  }
  vostok::ai::fsm::add_transition(
    this->m_logic,
    reload_one_round,
    reload_finish,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&transition_predicate);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v9,
    (int *)&transition_predicate);
}
