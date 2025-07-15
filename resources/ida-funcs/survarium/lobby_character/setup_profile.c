void __thiscall survarium::lobby_character::setup_profile(
        survarium::lobby_character *this,
        survarium::lobby_player_profile *p)
{
  unsigned int profile_id; // edx
  int m_current_profile_idx; // eax
  char *v5; // ecx
  bool v6; // zf
  unsigned __int8 *v7; // esi
  vostok::variant<32> *v8; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::variant<32> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_character,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_character *>,boost::arg<1> > > v12; // [esp-8h] [ebp-68h]
  int v13; // [esp+0h] [ebp-60h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_character,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_character *>,boost::arg<1> > > v14; // [esp+10h] [ebp-50h] BYREF
  survarium::lobby_menu *m_lobby_menu; // [esp+18h] [ebp-48h]
  vostok::physics::world *m_physics_world; // [esp+1Ch] [ebp-44h]
  char v17; // [esp+20h] [ebp-40h]
  vostok::variant<32> value; // [esp+30h] [ebp-30h] BYREF

  profile_id = p->profile_id;
  m_current_profile_idx = this->m_current_profile_idx;
  v5 = (char *)this + 1512 * m_current_profile_idx;
  if ( *((_DWORD *)v5 + 7) != profile_id || *((_DWORD *)v5 + 381) != p->revision )
  {
    v6 = this->m_current_query_id == -1;
    this->profile_id = profile_id;
    if ( v6 )
    {
      v7 = (unsigned __int8 *)&this->m_profiles[(unsigned __int8)((m_current_profile_idx + 1) % 3)];
      memcpy(v7, (unsigned __int8 *)p, 0x5E8u);
      m_lobby_menu = this->m_lobby_menu;
      m_physics_world = this->m_physics_world;
      v7[444] = 0;
      LOBYTE(v14.l_.a1_.t_) = 0;
      v17 = 1;
      v14.f_.f_ = (void (__thiscall *)(survarium::lobby_character *, vostok::resources::queries_result *))v7;
      value.m_helper = 0;
      value.m_type_id = 0;
      vostok::variant<32>::set<survarium::player_initial_info>(v8, (survarium::player_profile *)&value, &v14);
      v12.l_.a1_.t_ = this;
      v12.f_.f_ = survarium::lobby_character::on_player_ready;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        v9,
        &v14,
        v12,
        v13);
      this->m_current_query_id = vostok::resources::query_resource(
                                   "gameplay/players/default.player",
                                   (vostok::variant<32> *)0x55,
                                   survarium::g_allocator,
                                   &value,
                                   0,
                                   assert_on_fail_true);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v10,
        (int *)&v14);
      vostok::variant<32>::destroy_previous_variable_if_needed(v11, (int)&value);
    }
    else
    {
      memcpy(
        (unsigned __int8 *)&this->m_profiles[(unsigned __int8)((m_current_profile_idx + 2) % 3)],
        (unsigned __int8 *)p,
        sizeof(this->m_profiles[(unsigned __int8)((m_current_profile_idx + 2) % 3)]));
      this->m_need_to_requery = 1;
    }
  }
}
