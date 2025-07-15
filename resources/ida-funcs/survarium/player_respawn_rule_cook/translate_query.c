void __thiscall survarium::player_respawn_rule_cook::translate_query(
        survarium::player_respawn_rule_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v2; // eax
  void *v3; // esp
  void *v4; // esp
  const survarium::match_options *match_options; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  _BYTE v7[8]; // [esp-8h] [ebp-5Ch] BYREF
  int v8; // [esp+0h] [ebp-54h] BYREF
  int v9; // [esp+Ch] [ebp-48h] BYREF
  survarium::player_respawn_rule_query_data v10[2]; // [esp+14h] [ebp-40h] BYREF
  vostok::buffer_vector<vostok::resources::request> v11; // [esp+2Ch] [ebp-28h] BYREF
  vostok::resources::request v12[3]; // [esp+38h] [ebp-1Ch] BYREF
  vostok::physics::world *v13; // [esp+50h] [ebp-4h]

  v2 = parent[66];
  v13 = (vostok::physics::world *)this;
  vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>(
    (vostok::variant<32> *)&v10[1],
    (int)v2,
    &v10[1]);
  v3 = alloca(8);
  v11.m_begin = (vostok::resources::request *)v7;
  v11.m_end = (vostok::resources::request *)v7;
  v11.m_max_end = (vostok::resources::request *)&v8;
  v4 = alloca(4);
  match_options = v10[1].match_options;
  v12[2].path = v10[1].match_options->map_name;
  v12[2].id = game_project_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v11, &v12[2]);
  LOBYTE(match_options) = match_options->respawn_time;
  LOBYTE(v12[2].path) = v10[1].single_player;
  *(_DWORD *)&v10[0].single_player = 0;
  LOBYTE(v12[1].id) = (_BYTE)match_options;
  v10[0].match_options = (const survarium::match_options *)survarium::player_respawn_rule_cook::on_resources_loaded;
  v10[0].physics_world = v13;
  v10[1].match_options = (const survarium::match_options *)v12[1].id;
  *(_DWORD *)&v10[1].single_player = v12[2].path;
  qmemcpy(v12, v10, sizeof(v12));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v9 = 0;
  }
  else
  {
    qmemcpy(v10, v12, sizeof(v10));
    v9 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::player_respawn_rule_cook,vostok::resources::queries_result &,unsigned char,bool,vostok::physics::world *>,boost::_bi::list5<boost::_bi::value<survarium::player_respawn_rule_cook *>,boost::arg<1>,boost::_bi::value<unsigned char>,boost::_bi::value<bool>,boost::_bi::value<vostok::physics::world *>>>>'::`2'::stored_vtable
       + 1;
  }
  vostok::resources::query_resources(
    v11.m_begin,
    v11.m_end - v11.m_begin,
    survarium::g_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, &v9);
}
