void __usercall survarium::lobby_menu::query_scene_resources(survarium::lobby_menu *this@<ecx>, void *a2@<eax>)
{
  vostok::variant<32> *v3; // ecx
  vostok::variant<32> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::variant<32> *v6; // ecx
  vostok::variant<32> *v7; // ecx
  vostok::variant<32> *v8; // ecx
  vostok::sound::sound_scene_creation_params v9[3]; // [esp+10h] [ebp-138h] BYREF
  int v10; // [esp+38h] [ebp-110h]
  int v11; // [esp+3Ch] [ebp-10Ch]
  _BYTE v12[40]; // [esp+40h] [ebp-108h] BYREF
  int v13; // [esp+68h] [ebp-E0h]
  int v14; // [esp+6Ch] [ebp-DCh]
  _BYTE v15[40]; // [esp+70h] [ebp-D8h] BYREF
  int v16; // [esp+98h] [ebp-B0h]
  int v17; // [esp+9Ch] [ebp-ACh]
  void (__thiscall *v18)(survarium::lobby_menu *, vostok::resources::queries_result *); // [esp+A0h] [ebp-A8h]
  int v19; // [esp+A4h] [ebp-A4h]
  void (__thiscall *v20)(survarium::lobby_menu *, vostok::resources::queries_result *); // [esp+A8h] [ebp-A0h]
  unsigned int v21; // [esp+ACh] [ebp-9Ch]
  vostok::resources::request v22; // [esp+B0h] [ebp-98h] BYREF
  const char *v23; // [esp+B8h] [ebp-90h]
  int v24; // [esp+BCh] [ebp-8Ch]
  const char *v25; // [esp+C0h] [ebp-88h]
  int v26; // [esp+C4h] [ebp-84h]
  const char *v27; // [esp+C8h] [ebp-80h]
  int v28; // [esp+CCh] [ebp-7Ch]
  const char *v29; // [esp+D0h] [ebp-78h]
  int v30; // [esp+D4h] [ebp-74h]
  const char *v31; // [esp+D8h] [ebp-70h]
  int v32; // [esp+DCh] [ebp-6Ch]
  const char *v33; // [esp+E0h] [ebp-68h]
  int v34; // [esp+E4h] [ebp-64h]
  const char *v35; // [esp+E8h] [ebp-60h]
  int v36; // [esp+ECh] [ebp-5Ch]
  const char *v37; // [esp+F0h] [ebp-58h]
  int v38; // [esp+F4h] [ebp-54h]
  const vostok::variant<32> *v39[9]; // [esp+FCh] [ebp-4Ch] BYREF
  int v40[4]; // [esp+120h] [ebp-28h] BYREF
  void (__thiscall *v41)(survarium::lobby_menu *, vostok::resources::queries_result *); // [esp+130h] [ebp-18h]
  unsigned int v42; // [esp+134h] [ebp-14h] BYREF
  int v43; // [esp+138h] [ebp-10h]
  int v44; // [esp+13Ch] [ebp-Ch]
  void *value; // [esp+140h] [ebp-8h] BYREF
  vostok::render::scene_configuration v46; // [esp+147h] [ebp-1h] BYREF

  v46 = (vostok::render::scene_configuration)(*(_BYTE *)&v46 & 0xC0 | 0x2A);
  v13 = 0;
  v14 = 0;
  vostok::variant<32>::set<vostok::render::scene_configuration>((vostok::variant<32> *)this, (int)v12, &v46);
  v16 = 0;
  v17 = 0;
  value = a2;
  vostok::variant<32>::set<void *>(v3, (int)v15, &value);
  v42 = 64;
  v43 = 64;
  v44 = 2;
  v10 = 0;
  v11 = 0;
  vostok::variant<32>::set<vostok::sound::sound_scene_creation_params>(v4, v9, &v42);
  v39[0] = (const vostok::variant<32> *)v12;
  v39[2] = (const vostok::variant<32> *)v9;
  v39[3] = (const vostok::variant<32> *)v15;
  v30 = 515;
  v32 = 515;
  v43 = (int)a2;
  v34 = 32;
  v36 = 32;
  v38 = 32;
  v41 = survarium::lobby_menu::on_render_scenes_ready;
  v42 = 0;
  v18 = survarium::lobby_menu::on_render_scenes_ready;
  v19 = 0;
  v20 = (void (__thiscall *)(survarium::lobby_menu *, vostok::resources::queries_result *))a2;
  v39[1] = 0;
  memset(&v39[4], 0, 20);
  v22.path = "game_scene";
  v22.id = scene_class;
  v23 = "game_scene_view";
  v24 = 99;
  v25 = "sound_scene";
  v26 = 39;
  v27 = "lobby_scene/day";
  v28 = 65;
  v29 = "resources/flash_movies/cursor.swf";
  v31 = "resources/flash_movies/lobby_menu.swf";
  v33 = "resources/gameplay/players/default.player";
  v35 = "resources/gameplay/static_game_parameters.options";
  v37 = "resources/gameplay/db_skills_tree";
  v21 = v44;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v40[0] = 0;
  }
  else
  {
    v40[2] = (int)v18;
    v40[3] = v19;
    v41 = v20;
    v42 = v21;
    v40[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_menu,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(&v22, 9u, survarium::g_allocator, v39, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v40);
  vostok::variant<32>::destroy_previous_variable_if_needed(v6, (int)v9);
  vostok::variant<32>::destroy_previous_variable_if_needed(v7, (int)v15);
  vostok::variant<32>::destroy_previous_variable_if_needed(v8, (int)v12);
}
