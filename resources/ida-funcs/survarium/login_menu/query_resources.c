void __thiscall survarium::login_menu::query_resources(survarium::login_menu *this, const char *a2)
{
  vostok::variant<32> *v2; // ecx
  vostok::strings::detail::tuples *v3; // ecx
  vostok::strings::detail::tuples *v4; // ecx
  void *v5; // esp
  vostok::strings::detail::tuples *v6; // ecx
  vostok::particle::particle_action *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::variant<32> *v9; // ecx
  vostok::variant<32> *v10; // ecx
  const char *v11[2]; // [esp+0h] [ebp-104h] BYREF
  _BYTE v12[40]; // [esp+8h] [ebp-FCh] BYREF
  int v13; // [esp+30h] [ebp-D4h]
  int v14; // [esp+34h] [ebp-D0h]
  vostok::sound::sound_scene_creation_params v15[3]; // [esp+38h] [ebp-CCh] BYREF
  int v16; // [esp+60h] [ebp-A4h]
  int v17; // [esp+64h] [ebp-A0h]
  vostok::strings::detail::tuples::pair v18; // [esp+68h] [ebp-9Ch]
  vostok::strings::detail::tuples::pair v19; // [esp+70h] [ebp-94h]
  vostok::resources::request v20; // [esp+78h] [ebp-8Ch] BYREF
  const char *v21; // [esp+80h] [ebp-84h]
  int v22; // [esp+84h] [ebp-80h]
  const char *v23; // [esp+88h] [ebp-7Ch]
  int v24; // [esp+8Ch] [ebp-78h]
  const char *v25; // [esp+90h] [ebp-74h]
  int v26; // [esp+94h] [ebp-70h]
  const char *v27; // [esp+98h] [ebp-6Ch]
  int v28; // [esp+9Ch] [ebp-68h]
  const char **v29; // [esp+A0h] [ebp-64h]
  int v30; // [esp+A4h] [ebp-60h]
  const vostok::variant<32> *v31[6]; // [esp+A8h] [ebp-5Ch] BYREF
  vostok::strings::detail::tuples v32; // [esp+C0h] [ebp-44h] BYREF
  const char **v33; // [esp+F8h] [ebp-Ch]
  vostok::render::scene_configuration v34; // [esp+FFh] [ebp-5h] BYREF

  v34 = (vostok::render::scene_configuration)(*(_BYTE *)&v34 & 0xC0 | 0x20);
  v13 = 0;
  v14 = 0;
  vostok::variant<32>::set<vostok::render::scene_configuration>((vostok::variant<32> *)this, (int)v12, &v34);
  v32.m_strings[5].first = (const char *)64;
  v32.m_strings[5].second = 64;
  v32.m_count = 2;
  v16 = 0;
  v17 = 0;
  vostok::variant<32>::set<vostok::sound::sound_scene_creation_params>(v2, v15, (unsigned int *)&v32.m_strings[5]);
  v31[0] = (const vostok::variant<32> *)v12;
  v31[2] = (const vostok::variant<32> *)v15;
  v31[1] = 0;
  memset(&v31[3], 0, 12);
  vostok::strings::detail::tuples::tuples(v3, &v32, g_localization_name.m_begin, "/eula", v11[0]);
  v5 = alloca(vostok::strings::detail::tuples::size(v4, (unsigned int *)&v32));
  v33 = v11;
  vostok::strings::detail::tuples::concat(v6, (int)&v32, (char *)v11);
  v26 = 515;
  v28 = 515;
  v29 = v33;
  v32.m_strings[4].first = (const char *)survarium::login_menu::on_resources_ready;
  v32.m_strings[4].second = 0;
  v32.m_strings[5].first = a2;
  v18.first = (const char *)survarium::login_menu::on_resources_ready;
  v18.second = 0;
  v19.first = a2;
  v20.path = "game_scene";
  v20.id = scene_class;
  v21 = "game_scene_view";
  v22 = 99;
  v23 = "sound_scene";
  v24 = 39;
  v25 = "resources/flash_movies/login_menu.swf";
  v27 = "resources/flash_movies/cursor.swf";
  v30 = 3;
  v19.second = v32.m_strings[5].second;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v7) )
  {
    v32.m_strings[2].first = 0;
  }
  else
  {
    v32.m_strings[3] = v18;
    v32.m_strings[4] = v19;
    v32.m_strings[2].first = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::login_menu,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::login_menu *>,boost::arg<1>>>>'::`2'::stored_vtable
                           + 1;
  }
  vostok::resources::query_resources(&v20, 6u, survarium::g_allocator, v31, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v32.m_strings[2]);
  vostok::variant<32>::destroy_previous_variable_if_needed(v9, (int)v15);
  vostok::variant<32>::destroy_previous_variable_if_needed(v10, (int)v12);
}
