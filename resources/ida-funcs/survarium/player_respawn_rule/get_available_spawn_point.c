unsigned int __userpurge survarium::player_respawn_rule::get_available_spawn_point@<eax>(
        survarium::player_respawn_rule *this@<ecx>,
        _DWORD *a2@<eax>,
        stlp_std::priv::_Rb_tree_node_base *team_id)
{
  int v4; // esi
  void *v5; // esp
  void *v6; // esp
  stlp_std::priv::_Rb_tree_node_base *v7; // ebx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  stlp_std::priv::_Rb_tree_node_base *M_left; // ecx
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  survarium::respawn_point_core **v11; // ebx
  survarium::respawn_point_core *point_priority; // eax
  bool has_passed_filters; // al
  int *v15; // edi
  int v16; // ecx
  int v17; // edx
  vostok::buffer_vector<survarium::respawn_point_core *> *v18; // eax
  survarium::player_respawn_rule *v19; // [esp-4h] [ebp-50h]
  survarium::player_respawn_rule *v20; // [esp-4h] [ebp-50h]
  _BYTE v21[12]; // [esp+0h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v22; // [esp+Ch] [ebp-40h] BYREF
  survarium::respawn_point_core **v23; // [esp+2Ch] [ebp-20h] BYREF
  survarium::respawn_point_core **v24; // [esp+30h] [ebp-1Ch]
  _BYTE *v25; // [esp+34h] [ebp-18h]
  vostok::buffer_vector<survarium::respawn_point_core *> *v26; // [esp+38h] [ebp-14h] BYREF
  vostok::buffer_vector<survarium::respawn_point_core *> *v27; // [esp+3Ch] [ebp-10h]
  _BYTE *v28; // [esp+40h] [ebp-Ch]
  int v29; // [esp+44h] [ebp-8h]
  survarium::respawn_point_core *value; // [esp+48h] [ebp-4h] BYREF

  v29 = 0;
  v4 = 4 * a2[72];
  v5 = alloca(v4);
  v23 = (survarium::respawn_point_core **)v21;
  v24 = (survarium::respawn_point_core **)v21;
  v25 = &v21[v4];
  v6 = alloca(v4);
  v7 = (stlp_std::priv::_Rb_tree_node_base *)a2[70];
  v26 = (vostok::buffer_vector<survarium::respawn_point_core *> *)v21;
  v27 = (vostok::buffer_vector<survarium::respawn_point_core *> *)v21;
  v28 = &v21[v4];
  while ( v7 != (stlp_std::priv::_Rb_tree_node_base *)(a2 + 68) )
  {
    M_parent = v7[1]._M_parent;
    if ( M_parent[1]._M_right == team_id && !M_parent[2]._M_parent[2]._M_color )
    {
      M_left = M_parent[2]._M_left;
      if ( !M_left[2]._M_color )
      {
        value = (survarium::respawn_point_core *)v7[1]._M_parent;
        vostok::buffer_vector<survarium::respawn_point_core *>::push_back(
          (vostok::buffer_vector<survarium::respawn_point_core *> *)M_left,
          (int)&v23,
          &value);
      }
    }
    v10 = stlp_std::priv::_Rb_global<bool>::_M_increment(v7);
    this = v19;
    v7 = v10;
  }
  v11 = v23;
  value = 0;
  if ( v23 == v24 )
    goto LABEL_24;
  do
  {
    point_priority = (survarium::respawn_point_core *)(*v11)->point_priority;
    if ( point_priority >= value )
    {
      if ( point_priority > value )
      {
        this = (survarium::player_respawn_rule *)v26;
        v27 = v26;
      }
      value = point_priority;
      vostok::buffer_vector<survarium::respawn_point_core *>::push_back(
        (vostok::buffer_vector<survarium::respawn_point_core *> *)this,
        (int)&v26,
        v11);
    }
    ++v11;
  }
  while ( v11 != v24 );
  if ( v26 == v27 )
  {
LABEL_24:
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game_core",
                                 (const char *)2),
          this = v20,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v22);
      v29 = 1;
      vostok::logging::append(
        &v22,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\player_respawn_rule.cpp",
        0xDCu,
        "unsigned int __thiscall survarium::player_respawn_rule::get_available_spawn_point(enum survarium::game_team_id)",
        "game_core",
        error,
        "No available points for respawn!  team: [%d]",
        team_id);
    }
    if ( (v29 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v22);
    return 0;
  }
  else
  {
    v15 = a2 + 94;
    v16 = 134775813 * *v15 + 1;
    v17 = ((unsigned int)v16 * (unsigned __int64)(unsigned int)(((char *)v27 - (char *)v26) >> 2)) >> 32;
    v18 = v26;
    *v15 = v16;
    return *(_DWORD *)(*((_DWORD *)&v18->m_begin + v17) + 4);
  }
}
