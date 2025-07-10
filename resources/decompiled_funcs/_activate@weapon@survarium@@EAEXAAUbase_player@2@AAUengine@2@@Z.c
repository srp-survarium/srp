void __thiscall survarium::weapon::activate(
        survarium::weapon *this,
        survarium::base_player *user,
        survarium::engine *engine)
{
  survarium::base_game_scene *v4; // eax
  const vostok::animation::skeleton *v5; // eax
  vostok::resources::managed_resource *v6; // edx
  const vostok::animation::skeleton_bone *v7; // eax
  const vostok::animation::skeleton_bone *v8; // edi
  const vostok::animation::skeleton *v9; // eax
  const vostok::animation::skeleton *v10; // eax
  vostok::resources::managed_resource *v11; // edx
  const vostok::animation::skeleton_bone *v12; // eax
  const vostok::animation::skeleton_bone *v13; // edi
  const vostok::animation::skeleton *v14; // eax
  void (__cdecl *v15)(_QWORD *, _QWORD *, int); // eax
  void (__cdecl *v16)(_QWORD *, _QWORD *, int); // eax
  void (__cdecl *v17)(_QWORD *, _QWORD *, int); // eax
  void (__cdecl *v18)(_QWORD *, _QWORD *, int); // eax
  unsigned int m_current_time_in_ms; // eax
  survarium::fingers_to_weapon_corrector *p_m_fingers_corrector; // edi
  unsigned int v21; // eax
  vostok::render::render_model_instance *m_object; // eax
  vostok::render::render_model_instance *v23; // esi
  const vostok::animation::skeleton *v24; // eax
  survarium::fingers_to_weapon_corrector *v25; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon *>,boost::arg<1> > > v26; // [esp+3Eh] [ebp-48h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon *>,boost::arg<1> > > v27; // [esp+3Eh] [ebp-48h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::weapon,vostok::animation::animation_callback_params &,enum survarium::fingers_to_weapon_corrector::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::weapon *>,boost::arg<1>,boost::_bi::value<enum survarium::fingers_to_weapon_corrector::hands_enum> > > v28; // [esp+3Eh] [ebp-48h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::weapon,vostok::animation::animation_callback_params &,enum survarium::fingers_to_weapon_corrector::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::weapon *>,boost::arg<1>,boost::_bi::value<enum survarium::fingers_to_weapon_corrector::hands_enum> > > v29; // [esp+3Eh] [ebp-48h]
  int v30; // [esp+4Eh] [ebp-38h]
  int v31; // [esp+4Eh] [ebp-38h]
  int v32; // [esp+4Eh] [ebp-38h]
  int v33; // [esp+4Eh] [ebp-38h]
  bool first_person_view; // [esp+61h] [ebp-25h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v35; // [esp+62h] [ebp-24h] BYREF
  unsigned int v36; // [esp+66h] [ebp-20h] BYREF
  int v37; // [esp+6Ah] [ebp-1Ch]
  _QWORD v38[3]; // [esp+6Eh] [ebp-18h] BYREF

  if ( byte_10F80[(_DWORD)user] )
    this->m_user_animations_selector.m_player_logic_initial_state = (survarium::player_logic_base_state *)this->m_user_animations_selector.survarium::weapon_core::m_logic.m_states.m_last;
  if ( engine )
    v4 = (survarium::base_game_scene *)&engine[-3];
  else
    v4 = 0;
  this->m_game_scene = v4;
  survarium::weapon_core::activate(this, user, engine);
  v5 = user->skeleton(user);
  v6 = (vostok::resources::managed_resource *)&v5[1];
  v7 = (const vostok::animation::skeleton_bone *)((char *)&v5[1] + 20 * v5->m_bones_count);
  v35.m_object = v6;
  v8 = stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
         (const vostok::animation::skeleton_bone *)v6,
         v7,
         (bone_id_predicate)"LeftFoot");
  v9 = user->skeleton(user);
  this->m_left_toe_bone_index = ((char *)v8 - (char *)v35.m_object) / 20
                              - (v9[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                               - (int)&v9[1])
                              / 20;
  v10 = user->skeleton(user);
  v11 = (vostok::resources::managed_resource *)&v10[1];
  v12 = (const vostok::animation::skeleton_bone *)((char *)&v10[1] + 20 * v10->m_bones_count);
  v35.m_object = v11;
  v13 = stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
          (const vostok::animation::skeleton_bone *)v11,
          v12,
          (bone_id_predicate)"RightFoot");
  v14 = user->skeleton(user);
  this->m_right_toe_bone_index = ((char *)v13 - (char *)v35.m_object) / 20
                               - (v14[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                - (int)&v14[1])
                               / 20;
  v35.m_object = 0;
  v36 = (unsigned int)survarium::weapon::on_foot_step;
  v37 = 0;
  v26.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *__ptr64)(survarium::weapon *, vostok::animation::animation_callback_params *))(unsigned int)survarium::weapon::on_foot_step;
  LODWORD(v38[0]) = this;
  *(_QWORD *)&v26.l_.a1_.t_ = v38[0];
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    0,
    (int)&v36,
    (int)this,
    v26,
    v30);
  ((void (__stdcall *)(const char *, unsigned int *, survarium::base_player *, vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *, int, _DWORD))this->m_user->subscribe_animation_player)(
    "sound_events",
    &v36,
    this->m_user,
    &v35,
    255,
    0);
  if ( v36 )
  {
    if ( (v36 & 1) == 0 )
    {
      v15 = *(void (__cdecl **)(_QWORD *, _QWORD *, int))(v36 & 0xFFFFFFFE);
      if ( v15 )
        v15(v38, v38, 2);
    }
    v36 = 0;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v35);
  v36 = (unsigned int)survarium::weapon::on_shell_extraction_event;
  v37 = 0;
  v27.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *__ptr64)(survarium::weapon *, vostok::animation::animation_callback_params *))(unsigned int)survarium::weapon::on_shell_extraction_event;
  v35.m_object = 0;
  LODWORD(v38[0]) = this;
  *(_QWORD *)&v27.l_.a1_.t_ = v38[0];
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    0,
    (int)&v36,
    (int)this,
    v27,
    v31);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "shell_extraction",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v36,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v35,
    255u,
    0);
  if ( v36 )
  {
    if ( (v36 & 1) == 0 )
    {
      v16 = *(void (__cdecl **)(_QWORD *, _QWORD *, int))(v36 & 0xFFFFFFFE);
      if ( v16 )
        v16(v38, v38, 2);
    }
    v36 = 0;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v35);
  v36 = (unsigned int)survarium::weapon::on_hand_correction_event;
  v37 = 0;
  v28.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *__ptr64)(survarium::weapon *, vostok::animation::animation_callback_params *, survarium::fingers_to_weapon_corrector::hands_enum))(unsigned int)survarium::weapon::on_hand_correction_event;
  v35.m_object = 0;
  v38[0] = (unsigned int)this;
  v28.l_ = (boost::_bi::list3<boost::_bi::value<survarium::weapon *>,boost::arg<1>,boost::_bi::value<enum survarium::fingers_to_weapon_corrector::hands_enum> >)(unsigned int)this;
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    0,
    (int)&v36,
    (int)this,
    v28,
    v32);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "left_hand_corrector",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v36,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v35,
    255u,
    0);
  if ( v36 )
  {
    if ( (v36 & 1) == 0 )
    {
      v17 = *(void (__cdecl **)(_QWORD *, _QWORD *, int))(v36 & 0xFFFFFFFE);
      if ( v17 )
        v17(v38, v38, 2);
    }
    v36 = 0;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v35);
  v36 = (unsigned int)survarium::weapon::on_hand_correction_event;
  v37 = 0;
  v29.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *__ptr64)(survarium::weapon *, vostok::animation::animation_callback_params *, survarium::fingers_to_weapon_corrector::hands_enum))(unsigned int)survarium::weapon::on_hand_correction_event;
  v35.m_object = 0;
  v38[0] = (unsigned int)this | 0x100000000LL;
  v29.l_ = (boost::_bi::list3<boost::_bi::value<survarium::weapon *>,boost::arg<1>,boost::_bi::value<enum survarium::fingers_to_weapon_corrector::hands_enum> >)v38[0];
  boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>(
    0,
    (int)&v36,
    (int)this,
    v29,
    v33);
  this->m_user->subscribe_animation_player(
    this->m_user,
    "right_hand_corrector",
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&v36,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v35,
    255u,
    0);
  if ( v36 )
  {
    if ( (v36 & 1) == 0 )
    {
      v18 = *(void (__cdecl **)(_QWORD *, _QWORD *, int))(v36 & 0xFFFFFFFE);
      if ( v18 )
        v18(v38, v38, 2);
    }
    v36 = 0;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v35);
  m_current_time_in_ms = this->m_game_scene->m_game->m_current_time_in_ms;
  p_m_fingers_corrector = &this->m_fingers_corrector;
  if ( !this->m_fingers_corrector.m_hands[0].is_active )
  {
    this->m_fingers_corrector.m_hands[0].is_active = 1;
    this->m_fingers_corrector.m_hands[0].start_transition_time_in_ms = m_current_time_in_ms;
  }
  v21 = this->m_game_scene->m_game->m_current_time_in_ms;
  if ( !this->m_fingers_corrector.m_hands[1].is_active )
  {
    this->m_fingers_corrector.m_hands[1].is_active = 1;
    this->m_fingers_corrector.m_hands[1].start_transition_time_in_ms = v21;
  }
  first_person_view = this->m_game_ui != 0;
  m_object = this->model.m_object->m_render_model.m_object;
  v23 = 0;
  if ( m_object )
  {
    v23 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v24 = user->skeleton(user);
  survarium::fingers_to_weapon_corrector::initialize_bones_indices(v25, (int)p_m_fingers_corrector, v24);
  survarium::fingers_to_weapon_corrector::initialize_locators(p_m_fingers_corrector, first_person_view, v23);
  if ( v23 )
  {
    if ( !_InterlockedExchangeAdd(&v23->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v23->vostok::resources::unmanaged_intrusive_base, v23);
  }
}
