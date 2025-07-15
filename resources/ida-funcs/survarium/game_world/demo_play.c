void __thiscall survarium::game_world::demo_play(survarium::game_world *this, const char *track_name)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *m_object; // ecx
  char v4; // bl
  bool v5; // al
  bool v6; // zf
  int v7; // eax
  bool has_passed_filters; // al
  survarium::game_camera *m_active_camera; // edi
  survarium::demo_camera *m_demo_camera; // edx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+10h] [ebp-20h] BYREF

  m_object = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this->m_game_project.m_object;
  v4 = 0;
  if ( m_object )
  {
    v7 = ((int (__thiscall *)(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *, const char *))m_object->vtable[1].manager)(
           m_object,
           track_name);
    if ( v7 )
    {
      m_active_camera = this->m_camera_director->m_active_camera;
      m_demo_camera = this->m_demo_camera;
      m_demo_camera->m_track = (survarium::object_track *)(v7 - 336);
      m_demo_camera->m_prev_camera = m_active_camera;
      survarium::camera_director::switch_to_camera(this->m_camera_director, this->m_demo_camera);
      return;
    }
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)3),
          m_object = v12,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_object,
        &v13);
      v4 = 2;
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world.cpp",
        0x344u,
        "void __thiscall survarium::game_world::demo_play(const char *)",
        "game",
        warning,
        "no track found [%s]",
        track_name);
    }
    v6 = (v4 & 2) == 0;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v5 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)3),
          m_object = v11,
          v5) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_object,
        &v13);
      v4 = 1;
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world.cpp",
        0x33Du,
        "void __thiscall survarium::game_world::demo_play(const char *)",
        "game",
        warning,
        "no project loaded...");
    }
    v6 = (v4 & 1) == 0;
  }
  if ( !v6 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_object,
      (int *)&v13);
}
