void __thiscall survarium::generic_anomaly_core::resolve_links(
        survarium::generic_anomaly_core *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value config)
{
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  survarium::game_camera *v6; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  survarium::game_camera *v8; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v17; // ecx
  survarium::game_camera *v18; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  const vostok::ai::sound_item **v20; // eax
  survarium::game_camera *v21; // [esp+0h] [ebp-A0h]
  survarium::base_game_object *v22; // [esp+4h] [ebp-9Ch]
  boost::arg<1> *v24; // [esp+Ch] [ebp-94h]
  const vostok::ai::sound_item **__last; // [esp+10h] [ebp-90h]
  boost::arg<1> *v26; // [esp+14h] [ebp-8Ch]
  boost::arg<1> *v27; // [esp+4Ch] [ebp-54h]
  boost::arg<1> *v28; // [esp+54h] [ebp-4Ch]
  boost::arg<1> *result; // [esp+5Ch] [ebp-44h]
  survarium::base_game_object *v30; // [esp+70h] [ebp-30h]
  survarium::base_game_object *v31; // [esp+74h] [ebp-2Ch]
  const vostok::variant<32> **v32; // [esp+78h] [ebp-28h]
  unsigned int z; // [esp+7Ch] [ebp-24h]
  survarium::zone_group *group; // [esp+80h] [ebp-20h]
  unsigned int g; // [esp+84h] [ebp-1Ch]
  survarium::anomaly_state *state; // [esp+88h] [ebp-18h]
  unsigned int s; // [esp+8Ch] [ebp-14h]
  const char *full_path_name; // [esp+90h] [ebp-10h]
  unsigned int a; // [esp+94h] [ebp-Ch]
  unsigned int artefact_containers_count; // [esp+98h] [ebp-8h]
  unsigned int states_count; // [esp+9Ch] [ebp-4h]

  artefact_containers_count = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_artefact_containers._M_impl);
  for ( a = 0; a < artefact_containers_count; ++a )
  {
    v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   &config,
                                                   "artefact_containers");
    v4 = vostok::configs::binary_config_value::operator[](v3, a);
    full_path_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                     v5,
                                     (int)v4);
    v31 = p->get_object_by_name(p, full_path_name);
    if ( v31 )
    {
      v6 = (survarium::game_camera *)&v31[-4];
      v22 = v31 - 4;
    }
    else
    {
      v22 = 0;
    }
    survarium::weapon_user_dead_state::finalize(v6);
    result = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v7,
                                 (int)&this->m_artefact_containers)[a];
    *(_DWORD *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result) = v22;
  }
  states_count = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_states._M_impl);
  for ( s = 0; s < states_count; ++s )
  {
    survarium::weapon_user_dead_state::finalize(v8);
    v28 = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                              v9,
                              (int)&this->m_states)[s];
    state = *(survarium::anomaly_state **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v28);
    for ( g = 0;
          g < stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&state->groups._M_impl);
          ++g )
    {
      survarium::weapon_user_dead_state::finalize(v8);
      v27 = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                v10,
                                (int)&state->groups)[g];
      group = *(survarium::zone_group **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v27);
      for ( z = 0; z < group->zones._M_impl._M_finish - group->zones._M_impl._M_start; ++z )
      {
        v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        &config,
                                                        "states");
        v12 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v11, s);
        v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v12, "groups");
        v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v13, g);
        v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v14, "zones");
        v16 = vostok::configs::binary_config_value::operator[](v15, z);
        v32 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v17, (int)v16);
        v30 = p->get_object_by_name(p, v32);
        if ( v30 )
        {
          v18 = (survarium::game_camera *)&v30[-4];
          v21 = (survarium::game_camera *)&v30[-4];
        }
        else
        {
          v21 = 0;
        }
        survarium::weapon_user_dead_state::finalize(v18);
        group->zones._M_impl._M_start[z].zone = (survarium::damage_zone_core *)v21;
        survarium::weapon_user_dead_state::finalize(v21);
        group->zones._M_impl._M_start[z].zone->m_standalone = 0;
      }
    }
  }
  v26 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)v8,
                           (int)&this->m_states);
  __last = (const vostok::ai::sound_item **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v26);
  v24 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                           v19,
                           (int)&this->m_states);
  v20 = (const vostok::ai::sound_item **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v24);
  stlp_std::sort<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
    v20,
    __last,
    (bool (__cdecl *)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))survarium::state_prio);
}
