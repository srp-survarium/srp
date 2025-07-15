void __thiscall survarium::weapon_user_animations_selector::weapon_user_animations_selector(
        survarium::weapon_user_animations_selector *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  survarium::player_logic_base_state *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // eax
  survarium::game_camera *v6; // ecx
  survarium::player_logic_base_state *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // eax
  survarium::game_camera *v9; // ecx
  survarium::player_logic_base_state *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // eax
  survarium::player_logic_base_state *v12; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v14; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v15; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v16; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v17; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v18; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v19; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v20; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v21; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v22; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v23; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_user_animations_selector,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::weapon_user_animations_selector *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *v24; // eax
  boost::function0<bool> *v25; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v26; // ecx
  survarium::player_logic_base_state *v27; // [esp+4h] [ebp-2A0h]
  survarium::player_logic_base_state *v28; // [esp+8h] [ebp-29Ch]
  survarium::player_logic_base_state *v29; // [esp+Ch] [ebp-298h]
  survarium::player_logic_base_state *v30; // [esp+10h] [ebp-294h]
  boost::function<void __cdecl(char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum)> v32; // [esp+24h] [ebp-280h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v33; // [esp+44h] [ebp-260h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v34; // [esp+4Ch] [ebp-258h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v35; // [esp+54h] [ebp-250h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v36; // [esp+5Ch] [ebp-248h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v37; // [esp+64h] [ebp-240h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v38; // [esp+6Ch] [ebp-238h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v39; // [esp+74h] [ebp-230h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v40; // [esp+7Ch] [ebp-228h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v41; // [esp+84h] [ebp-220h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > v42; // [esp+8Ch] [ebp-218h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > > f; // [esp+94h] [ebp-210h]
  void *v44; // [esp+9Ch] [ebp-208h]
  vostok::memory::doug_lea_allocator *v45; // [esp+A0h] [ebp-204h]
  void *v46; // [esp+A4h] [ebp-200h]
  vostok::memory::doug_lea_allocator *v47; // [esp+A8h] [ebp-1FCh]
  void *v48; // [esp+ACh] [ebp-1F8h]
  vostok::memory::doug_lea_allocator *v49; // [esp+B0h] [ebp-1F4h]
  void *_Where; // [esp+B4h] [ebp-1F0h]
  vostok::memory::doug_lea_allocator *v51; // [esp+B8h] [ebp-1ECh]
  vostok::resources::resource_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base> *p_m_animations; // [esp+BCh] [ebp-1E8h]
  survarium::game_options *p_m_leg_damaged_subscriber; // [esp+C0h] [ebp-1E4h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v54; // [esp+C4h] [ebp-1E0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v55; // [esp+CCh] [ebp-1D8h] BYREF
  boost::function0<bool> v56; // [esp+D4h] [ebp-1D0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v57; // [esp+F4h] [ebp-1B0h] BYREF
  boost::function0<bool> v58; // [esp+FCh] [ebp-1A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v59; // [esp+11Ch] [ebp-188h] BYREF
  boost::function0<bool> v60; // [esp+124h] [ebp-180h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v61; // [esp+144h] [ebp-160h] BYREF
  boost::function0<bool> v62; // [esp+14Ch] [ebp-158h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v63; // [esp+16Ch] [ebp-138h] BYREF
  boost::function0<bool> v64; // [esp+174h] [ebp-130h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v65; // [esp+194h] [ebp-110h] BYREF
  boost::function0<bool> v66; // [esp+19Ch] [ebp-108h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v67; // [esp+1BCh] [ebp-E8h] BYREF
  boost::function0<bool> v68; // [esp+1C4h] [ebp-E0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v69; // [esp+1E4h] [ebp-C0h] BYREF
  boost::function0<bool> v70; // [esp+1ECh] [ebp-B8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v71; // [esp+20Ch] [ebp-98h] BYREF
  boost::function0<bool> v72; // [esp+214h] [ebp-90h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v73; // [esp+234h] [ebp-70h] BYREF
  boost::function0<bool> v74; // [esp+23Ch] [ebp-68h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+25Ch] [ebp-48h] BYREF
  boost::function0<bool> v76; // [esp+264h] [ebp-40h] BYREF
  survarium::player_logic_jump_state *v77; // [esp+284h] [ebp-20h]
  survarium::player_logic_sprint_state *v78; // [esp+288h] [ebp-1Ch]
  survarium::player_logic_crouch_state *v79; // [esp+28Ch] [ebp-18h]
  survarium::player_logic_stand_state *v80; // [esp+290h] [ebp-14h]
  survarium::player_logic_base_state *crouch; // [esp+294h] [ebp-10h]
  survarium::player_logic_base_state *sprint; // [esp+298h] [ebp-Ch]
  survarium::player_logic_base_state *stand; // [esp+29Ch] [ebp-8h]
  survarium::player_logic_base_state *jumping; // [esp+2A0h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::ai::fsm::fsm(&this->m_logic);
  p_m_leg_damaged_subscriber = (survarium::game_options *)&this->m_leg_damaged_subscriber;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_leg_damaged_subscriber);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v1,
    &this->m_leg_damaged_subscriber.subscription_callback.vtable);
  this->m_leg_damaged_subscriber.next = 0;
  p_m_animations = &this->m_animations;
  this->m_animations.m_object = 0;
  this->m_forced_not_to_sprint = 0;
  this->m_right_leg_is_supporting = 1;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v51 = v2;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x28u);
  v80 = (survarium::player_logic_stand_state *)operator new(0x28u, _Where);
  if ( v80 )
  {
    survarium::player_logic_stand_state::player_logic_stand_state(v80, this);
    v30 = v4;
  }
  else
  {
    v30 = 0;
  }
  stand = v30;
  survarium::weapon_user_dead_state::finalize(v3);
  v49 = v5;
  v48 = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x28u);
  v79 = (survarium::player_logic_crouch_state *)operator new(0x28u, v48);
  if ( v79 )
  {
    survarium::player_logic_crouch_state::player_logic_crouch_state(v79, this);
    v29 = v7;
  }
  else
  {
    v29 = 0;
  }
  crouch = v29;
  survarium::weapon_user_dead_state::finalize(v6);
  v47 = v8;
  v46 = vostok::memory::doug_lea_allocator::malloc_impl(v8, 0x90u);
  v78 = (survarium::player_logic_sprint_state *)operator new(0x90u, v46);
  if ( v78 )
  {
    survarium::player_logic_sprint_state::player_logic_sprint_state(v78, this);
    v28 = v10;
  }
  else
  {
    v28 = 0;
  }
  sprint = v28;
  survarium::weapon_user_dead_state::finalize(v9);
  v45 = v11;
  v44 = vostok::memory::doug_lea_allocator::malloc_impl(v11, 0x40u);
  v77 = (survarium::player_logic_jump_state *)operator new(0x40u, v44);
  if ( v77 )
  {
    survarium::player_logic_jump_state::player_logic_jump_state(v77, this);
    v27 = v12;
  }
  else
  {
    v27 = 0;
  }
  jumping = v27;
  vostok::ai::fsm::add_state(&this->m_logic, stand);
  vostok::ai::fsm::add_state(&this->m_logic, crouch);
  vostok::ai::fsm::add_state(&this->m_logic, sprint);
  vostok::ai::fsm::add_state(&this->m_logic, v27);
  f = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::crouch_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &v76);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v76,
    f);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    stand,
    crouch,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v76);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v13,
    (int *)&v76);
  v42 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v73, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::sprint_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v42.f_.f_,
    &v74);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v74,
    v42);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    stand,
    sprint,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v74);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v14,
    (int *)&v74);
  v41 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v71, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::jump_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v41.f_.f_,
    &v72);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v72,
    v41);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    stand,
    jumping,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v72);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v15,
    (int *)&v72);
  v40 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v69, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::stand_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v40.f_.f_,
    &v70);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v70,
    v40);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    crouch,
    stand,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v70);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v16,
    (int *)&v70);
  v39 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v67, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::sprint_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v39.f_.f_,
    &v68);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v68,
    v39);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    crouch,
    sprint,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v68);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v17,
    (int *)&v68);
  v38 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v65, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::crouch_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v38.f_.f_,
    &v66);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v66,
    v38);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    sprint,
    crouch,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v18,
    (int *)&v66);
  v37 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v63, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::stand_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v37.f_.f_,
    &v64);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v64,
    v37);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    sprint,
    stand,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v64);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v19,
    (int *)&v64);
  v36 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v61, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::jump_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v36.f_.f_,
    &v62);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v62,
    v36);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    sprint,
    jumping,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v62);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v20,
    (int *)&v62);
  v35 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v59, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::broken_legs_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v35.f_.f_,
    &v60);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v60,
    v35);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    jumping,
    crouch,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v60);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v21,
    (int *)&v60);
  v34 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v57, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::stand_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v34.f_.f_,
    &v58);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v58,
    v34);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    jumping,
    stand,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v58);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v22,
    (int *)&v58);
  v33 = (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v55, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::sprint_predicate, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v33.f_.f_,
    &v56);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_user_animations_selector>,boost::_bi::list1<boost::_bi::value<survarium::weapon_user_animations_selector *>>>>(
    &v56,
    v33);
  vostok::ai::fsm::add_transition(
    &this->m_logic,
    jumping,
    sprint,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v56);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v23,
    (int *)&v56);
  v24 = (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_user_animations_selector,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::weapon_user_animations_selector *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *)boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v54, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::weapon_user_animations_selector::on_broken_limb_affect, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum)>::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum)>(
    &v32,
    *v24,
    0);
  boost::function0<bool>::swap(v25, (boost::function0<bool> *)&this->m_leg_damaged_subscriber);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v26,
    (int *)&v32);
  this->m_player_logic_initial_state = stand;
}
