void __userpurge survarium::generic_anomaly_core::load(
        survarium::generic_anomaly_core *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  survarium::game_camera *v9; // ecx
  void *const *v10; // eax
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // ecx
  const vostok::configs::binary_config_value *v13; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::configs::binary_config_value *v15; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v16; // ecx
  const vostok::configs::binary_config_value *v17; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  const vostok::configs::binary_config_value *v19; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v20; // ecx
  const vostok::configs::binary_config_value *v21; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v22; // ecx
  const vostok::configs::binary_config_value *v23; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v24; // ecx
  const vostok::configs::binary_config_value *v25; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v26; // ecx
  const vostok::configs::binary_config_value *v27; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v28; // ecx
  const vostok::configs::binary_config_value *v29; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v30; // ecx
  const vostok::configs::binary_config_value *v31; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  void *const *v34; // eax
  vostok::configs::binary_config_value *v35; // eax
  vostok::memory::doug_lea_allocator *v36; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v37; // ecx
  const vostok::variant<32> **v38; // eax
  boost::arg<1> *v39; // eax
  vostok::configs::binary_config_value *v40; // eax
  bool v41; // al
  const vostok::configs::binary_config_value *v42; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v43; // ecx
  const vostok::variant<32> **v44; // eax
  vostok::configs::binary_config_value *v45; // eax
  bool v46; // al
  vostok::configs::binary_config_value *v47; // eax
  bool v48; // al
  const vostok::configs::binary_config_value *v49; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v50; // ecx
  const vostok::variant<32> **v51; // eax
  const vostok::configs::binary_config_value *v52; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v53; // ecx
  const vostok::variant<32> **v54; // eax
  const vostok::configs::binary_config_value *v55; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v56; // ecx
  const vostok::variant<32> **v57; // eax
  vostok::configs::binary_config_value *v58; // eax
  void *const *v59; // eax
  vostok::configs::binary_config_value *v60; // eax
  vostok::memory::doug_lea_allocator *v61; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v62; // ecx
  const vostok::variant<32> **v63; // eax
  boost::arg<1> *v64; // eax
  vostok::configs::binary_config_value *v65; // eax
  bool v66; // al
  const vostok::configs::binary_config_value *v67; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v68; // ecx
  const vostok::variant<32> **v69; // eax
  const vostok::configs::binary_config_value *v70; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v71; // ecx
  const vostok::variant<32> **v72; // eax
  vostok::configs::binary_config_value *v73; // eax
  survarium::game_camera *v74; // [esp+4h] [ebp-118h]
  survarium::game_camera *v75; // [esp+8h] [ebp-114h]
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> v77; // [esp+63h] [ebp-B9h] BYREF
  void *v78; // [esp+64h] [ebp-B8h]
  vostok::memory::doug_lea_allocator *v79; // [esp+68h] [ebp-B4h]
  boost::arg<1> *v80; // [esp+8Ch] [ebp-90h]
  char v81; // [esp+93h] [ebp-89h]
  stlp_std::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *> > *v82; // [esp+94h] [ebp-88h]
  survarium::std_allocator<survarium::zone_group *> __a; // [esp+9Bh] [ebp-81h] BYREF
  void *_Where; // [esp+9Ch] [ebp-80h]
  vostok::memory::doug_lea_allocator *v85; // [esp+A0h] [ebp-7Ch]
  survarium::zone_group::zone_wrapper __x; // [esp+B0h] [ebp-6Ch] BYREF
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *v87; // [esp+B8h] [ebp-64h]
  boost::arg<1> v88[4]; // [esp+BCh] [ebp-60h] BYREF
  char *v89; // [esp+C0h] [ebp-5Ch]
  boost::arg<1> result[4]; // [esp+C4h] [ebp-58h] BYREF
  int v91; // [esp+C8h] [ebp-54h]
  survarium::zone_group *group; // [esp+CCh] [ebp-50h]
  unsigned int zones_count; // [esp+D0h] [ebp-4Ch]
  vostok::configs::binary_config_value current_group; // [esp+D4h] [ebp-48h] BYREF
  unsigned int g; // [esp+ECh] [ebp-30h]
  survarium::anomaly_state *state; // [esp+F0h] [ebp-2Ch]
  vostok::configs::binary_config_value current_state; // [esp+F4h] [ebp-28h] BYREF
  unsigned int groups_count; // [esp+10Ch] [ebp-10h]
  unsigned int s; // [esp+110h] [ebp-Ch]
  unsigned int artefact_containers_count; // [esp+114h] [ebp-8h]
  unsigned int states_count; // [esp+118h] [ebp-4h]

  v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 config,
                                                 "artefacts_enabled");
  this->artefacts_enabled = vostok::configs::binary_config_value::operator bool(v3);
  v4 = vostok::configs::binary_config_value::operator[](config, "artefacts_max_count");
  this->artefacts_max_count = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                              v5,
                                              (int)v4);
  v6 = vostok::configs::binary_config_value::operator[](config, "artefacts_respawn_time_sec");
  this->artefacts_respawn_time_sec = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                     v7,
                                                     (int)v6);
  if ( this->artefacts_enabled )
  {
    v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   config,
                                                   "artefact_containers");
    artefact_containers_count = vostok::configs::binary_config_value::size(v8);
    v91 = 0;
    survarium::weapon_user_dead_state::finalize(v9);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
      &this->m_artefact_containers._M_impl,
      artefact_containers_count,
      v10);
    this->artefacts_max_count = vostok::math::min(this->artefacts_max_count, artefact_containers_count);
  }
  v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "energy_enabled");
  this->energy_enabled = vostok::configs::binary_config_value::operator bool(v11);
  vostok::configs::binary_config_value::operator[](config, "energy_initial");
  vostok::configs::binary_config_value::operator float(v12);
  this->m_energy_current = a2;
  v13 = vostok::configs::binary_config_value::operator[](config, "energy_decrease_speed");
  this->energy_decrease_speed = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                v14,
                                                (int)v13);
  v15 = vostok::configs::binary_config_value::operator[](config, "energy_af_container_use");
  this->energy_af_container_use = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                  v16,
                                                  (int)v15);
  v17 = vostok::configs::binary_config_value::operator[](config, "energy_on_walk");
  this->energy_on_walk = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                         v18,
                                         (int)v17);
  v19 = vostok::configs::binary_config_value::operator[](config, "energy_on_run");
  this->energy_on_run = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                        v20,
                                        (int)v19);
  v21 = vostok::configs::binary_config_value::operator[](config, "energy_on_sprint");
  this->energy_on_sprint = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                           v22,
                                           (int)v21);
  v23 = vostok::configs::binary_config_value::operator[](config, "energy_on_jump");
  this->energy_on_jump = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                         v24,
                                         (int)v23);
  v25 = vostok::configs::binary_config_value::operator[](config, "energy_on_shoot");
  this->energy_on_shoot = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                          v26,
                                          (int)v25);
  v27 = vostok::configs::binary_config_value::operator[](config, "energy_on_character_hit");
  this->energy_on_character_hit = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                  v28,
                                                  (int)v27);
  v29 = vostok::configs::binary_config_value::operator[](config, "energy_on_explosion");
  this->energy_on_explosion = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                              v30,
                                              (int)v29);
  v31 = vostok::configs::binary_config_value::operator[](config, "energy_on_character_kill");
  this->energy_on_character_kill = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                   v32,
                                                   (int)v31);
  v33 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](config, "states");
  states_count = vostok::configs::binary_config_value::size(v33);
  *(_DWORD *)result = 0;
  v34 = (void *const *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
    &this->m_states._M_impl,
    states_count,
    v34);
  for ( s = 0; s < states_count; ++s )
  {
    v35 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](config, "states");
    current_state = *vostok::configs::binary_config_value::operator[](v35, s);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)HIDWORD(current_state.id.max_storage));
    v85 = v36;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v36, 0x30u);
    v89 = (char *)operator new(0x30u, _Where);
    if ( v89 )
    {
      v82 = (stlp_std::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *> > *)(v89 + 28);
      stlp_std::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *>>::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *>>(
        (stlp_std::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *> > *)(v89 + 28),
        &__a);
      *((_DWORD *)v89 + 10) = this;
      v75 = (survarium::game_camera *)v89;
    }
    else
    {
      v75 = 0;
    }
    state = (survarium::anomaly_state *)v75;
    v81 = 0;
    survarium::weapon_user_dead_state::finalize(v75);
    v38 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v37,
            (int)&this->m_states);
    v80 = (boost::arg<1> *)&v38[s];
    v39 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v80);
    *(_DWORD *)v39 = state;
    state->debug_idx = s;
    v40 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &current_state,
                                                    "enabled");
    v41 = vostok::configs::binary_config_value::operator bool(v40);
    state->enabled = v41;
    v42 = vostok::configs::binary_config_value::operator[](&current_state, "energy_threshold");
    v44 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v43, (int)v42);
    state->energy_threshold = (unsigned int)v44;
    v45 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &current_state,
                                                    "shoot_trigger");
    v46 = vostok::configs::binary_config_value::operator bool(v45);
    state->shoot_trigger = v46;
    v47 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &current_state,
                                                    "zone_activity_trigger");
    v48 = vostok::configs::binary_config_value::operator bool(v47);
    state->zone_activity_trigger = v48;
    v49 = vostok::configs::binary_config_value::operator[](&current_state, "active_time_sec");
    v51 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v50, (int)v49);
    state->active_time_sec = (unsigned int)v51;
    v52 = vostok::configs::binary_config_value::operator[](&current_state, "energy_on_exit");
    v54 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v53, (int)v52);
    state->energy_on_exit = (unsigned int)v54;
    v55 = vostok::configs::binary_config_value::operator[](&current_state, "select_priority");
    v57 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v56, (int)v55);
    state->select_priority = (unsigned int)v57;
    v58 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    &current_state,
                                                    "groups");
    groups_count = vostok::configs::binary_config_value::size(v58);
    *(_DWORD *)v88 = 0;
    v59 = (void *const *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v88);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
      &state->groups._M_impl,
      groups_count,
      v59);
    for ( g = 0; g < groups_count; ++g )
    {
      v60 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      &current_state,
                                                      "groups");
      current_group = *vostok::configs::binary_config_value::operator[](v60, g);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)HIDWORD(current_group.id.max_storage));
      v79 = v61;
      v78 = vostok::memory::doug_lea_allocator::malloc_impl(v61, 0x24u);
      v87 = (stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *)operator new(0x24u, v78);
      if ( v87 )
      {
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
          v87 + 1,
          &v77);
        v87[2]._M_start = (vostok::ai::planning::specified_action *)state;
        v74 = (survarium::game_camera *)v87;
      }
      else
      {
        v74 = 0;
      }
      group = (survarium::zone_group *)v74;
      survarium::weapon_user_dead_state::finalize(v74);
      v63 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v62,
              (int)&state->groups);
      v64 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref((boost::arg<1> *)&v63[g]);
      *(_DWORD *)v64 = group;
      v65 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      &current_group,
                                                      "enabled");
      v66 = vostok::configs::binary_config_value::operator bool(v65);
      group->enabled = v66;
      v67 = vostok::configs::binary_config_value::operator[](&current_group, "max_charged_count");
      v69 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v68, (int)v67);
      group->max_charged_count = (unsigned int)v69;
      v70 = vostok::configs::binary_config_value::operator[](&current_group, "recharge_time_sec");
      v72 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v71, (int)v70);
      group->recharge_time_sec = (unsigned int)v72;
      v73 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      &current_group,
                                                      "zones");
      zones_count = vostok::configs::binary_config_value::size(v73);
      __x.zone = 0;
      *(_DWORD *)&__x.active = 0;
      stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::resize(
        &group->zones._M_impl,
        zones_count,
        &__x);
      vostok::math::clamp<unsigned int>(&group->max_charged_count, 0, zones_count);
    }
  }
}
