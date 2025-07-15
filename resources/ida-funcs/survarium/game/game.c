void __thiscall survarium::game::game(
        survarium::game *this,
        survarium::flash_text_manager *engine,
        vostok::engine_user::engine *render_world,
        vostok::engine_user::engine_vtbl *sound,
        vostok::engine_user::engine_vtbl *network,
        Scaleform::GFx::DrawTextManager *a6)
{
  vostok::timing::timer *v6; // ecx
  vostok::threading::mutex_tasks_unaware *v7; // ecx
  survarium::flash_text_manager *v8; // ecx
  unsigned int v9; // eax
  survarium::scheduler *v10; // ecx
  float v11; // xmm0_4
  boost::function<void __cdecl(char const *)> *v12; // ecx
  bool v13; // zf
  vostok::console_commands::cc_delegate *v14; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  vostok::render::scene_renderer *v16; // eax
  vostok::console_commands::cc_delegate *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  vostok::render::scene_renderer *v19; // eax
  vostok::console_commands::cc_delegate *v20; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v21; // ecx
  vostok::console_commands::cc_delegate *v22; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v23; // ecx
  vostok::console_commands::cc_delegate *v24; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v25; // ecx
  vostok::console_commands::cc_delegate *v26; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v27; // ecx
  LARGE_INTEGER QPC; // rax
  vostok::timing::timer *v29; // ecx
  survarium::inventory_cook *v30; // ecx
  survarium::profile_skin_visual_cook *v31; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v32; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v33; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v34; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v35; // ecx
  vostok::memory::doug_lea_allocator *v36; // esi
  char *v37; // eax
  vostok::memory::doug_lea_allocator *v38; // ecx
  char *v39; // eax
  survarium::chat_handler *v40; // ecx
  unsigned int v41; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v42; // [esp-Ch] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v43; // [esp-Ch] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v44; // [esp-Ch] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,char const *>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v45; // [esp-Ch] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > time_factor; // [esp+0h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > time_factora; // [esp+0h] [ebp-40h]
  boost::function<void __cdecl(char const *)> *time_floating_factor; // [esp+4h] [ebp-3Ch]
  boost::function<void __cdecl(char const *)> *time_floating_factora; // [esp+4h] [ebp-3Ch]
  boost::function<void __cdecl(char const *)> *time_floating_factorb; // [esp+4h] [ebp-3Ch]
  boost::function<void __cdecl(char const *)> *time_floating_factorc; // [esp+4h] [ebp-3Ch]
  boost::function<void __cdecl(char const *)> *time_floating_factord; // [esp+4h] [ebp-3Ch]
  boost::function<void __cdecl(char const *)> *time_floating_factore; // [esp+4h] [ebp-3Ch]
  boost::function<void __cdecl(char const *)> *time_floating_factorf; // [esp+4h] [ebp-3Ch]
  survarium::inventory_cook *time_floating_factorg; // [esp+4h] [ebp-3Ch]
  survarium::inventory_cook *time_floating_factorh; // [esp+4h] [ebp-3Ch]
  survarium::inventory_cook *time_floating_factori; // [esp+4h] [ebp-3Ch]
  survarium::inventory_cook *time_floating_factorj; // [esp+4h] [ebp-3Ch]
  survarium::profile_skin_visual_cook *time_floating_factork; // [esp+4h] [ebp-3Ch]
  survarium::profile_skin_visual_cook *time_floating_factorl; // [esp+4h] [ebp-3Ch]
  survarium::profile_skin_visual_cook *time_floating_factorm; // [esp+4h] [ebp-3Ch]
  survarium::profile_skin_visual_cook *time_floating_factorn; // [esp+4h] [ebp-3Ch]
  survarium::profile_skin_visual_cook *time_floating_factoro; // [esp+4h] [ebp-3Ch]
  survarium::profile_skin_visual_cook *time_floating_factorp; // [esp+4h] [ebp-3Ch]
  const char *v65; // [esp+8h] [ebp-38h]
  const char *v66; // [esp+Ch] [ebp-34h]
  vostok::console_commands::execution_filter v67; // [esp+10h] [ebp-30h]
  char v68; // [esp+1Bh] [ebp-25h]
  unsigned int v69; // [esp+1Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+20h] [ebp-20h] BYREF

  engine->text_manager_impl = (Scaleform::GFx::DrawTextManager *)&survarium::game::`vftable'{for `vostok::engine_user::world'};
  *(_DWORD *)&engine->need_capture = &survarium::game::`vftable'{for `survarium::scaleform_game_engine'};
  HIBYTE(engine->m_output_width) = 0;
  vostok::timing::floating_timer::floating_timer((vostok::timing::floating_timer *)this, (LARGE_INTEGER *)&engine[1]);
  vostok::timing::timer::timer(v6, (LARGE_INTEGER *)&engine[4]);
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v7, (_RTL_CRITICAL_SECTION *)&engine[5].m_output_width);
  engine[7].text_manager_impl = 0;
  *(_DWORD *)&engine[9].need_capture = render_world;
  engine[9].m_output_height = (unsigned int)network;
  engine[9].m_output_width = (unsigned int)sound;
  engine[10].text_manager_impl = a6;
  *(_DWORD *)&engine[10].need_capture = 0;
  engine[10].m_output_width = 0;
  engine[10].m_output_height = (unsigned int)sound[8].enter_editor_mode;
  survarium::flash_factory::flash_factory(
    (survarium::flash_factory *)a6,
    &engine[11].text_manager_impl,
    (survarium::scaleform_game_engine *)&engine->need_capture);
  v8 = (survarium::flash_text_manager *)operator new(0x10u);
  if ( v8 )
    survarium::flash_text_manager::flash_text_manager(v8, (Scaleform::GFx::Loader *)engine[11].text_manager_impl);
  else
    v9 = 0;
  engine[11].m_output_width = v9;
  survarium::game_world::game_world((survarium::game_world *)v8, (survarium::game *)&engine[12], engine, v9);
  engine[865].text_manager_impl = 0;
  *(_DWORD *)&engine[865].need_capture = 0;
  survarium::scheduler::scheduler(v10, &engine[865].m_output_height);
  engine[868].m_output_height = 0;
  engine[869].text_manager_impl = 0;
  *(_DWORD *)&engine[869].need_capture = 0;
  engine[869].m_output_width = 0;
  memset(&f, 0, 16);
  engine[869].m_output_height = 0;
  engine[870].text_manager_impl = (Scaleform::GFx::DrawTextManager *)(&f.vtable)[1];
  *(_QWORD *)&engine[870].need_capture = *(_QWORD *)&f.functor.obj_ptr;
  LOBYTE(engine[869].m_output_height) = 0;
  engine[870].text_manager_impl = 0;
  *(_DWORD *)&engine[870].need_capture = (char *)engine + 13916;
  engine[870].m_output_width = (unsigned int)&engine[869].m_output_height;
  engine[870].m_output_height = 0;
  LOBYTE(engine[871].text_manager_impl) = v68;
  survarium::swf_input_translator::initialize(
    (survarium::swf_input_translator *)&engine[869].m_output_height,
    (survarium::swf_input_translator *)&engine[869].m_output_height);
  engine[871].need_capture = 0;
  engine[871].m_output_width = 0;
  engine[872].m_output_height = -1;
  engine[873].text_manager_impl = (Scaleform::GFx::DrawTextManager *)-1;
  engine[872].m_output_width = 0;
  v11 = s_bm_current_air_resistance;
  engine[871].m_output_height = 0;
  engine[872].text_manager_impl = 0;
  *(_DWORD *)&engine[872].need_capture = 0;
  engine[873].m_output_width = 0;
  engine[873].m_output_height = 0;
  *(_DWORD *)&engine[873].need_capture = 20;
  LOBYTE(engine[874].text_manager_impl) = 0;
  BYTE1(engine[874].text_manager_impl) = 0;
  *(float *)&engine[874].need_capture = v11;
  LOBYTE(engine[874].m_output_width) = 0;
  BYTE1(engine[874].m_output_width) = 0;
  LOBYTE(engine[874].m_output_height) = 0;
  engine[875].text_manager_impl = (Scaleform::GFx::DrawTextManager *)&engine[875].m_output_height;
  *(_DWORD *)&engine[875].need_capture = (char *)engine + 14012;
  engine[875].m_output_width = (unsigned int)&engine[907].m_output_height;
  LOBYTE(engine[875].m_output_height) = 0;
  LOBYTE(engine[875].m_output_height) = 0;
  engine[907].m_output_height = (unsigned int)&engine[908].m_output_width;
  engine[908].text_manager_impl = (Scaleform::GFx::DrawTextManager *)&engine[908].m_output_width;
  *(_DWORD *)&engine[908].need_capture = (char *)engine + 15048;
  LOBYTE(engine[908].m_output_width) = 0;
  LOBYTE(engine[908].m_output_width) = 0;
  engine[940].m_output_height = 0;
  engine[940].m_output_width = (unsigned int)&s_hdd;
  *(_DWORD *)&engine[941].need_capture = -1;
  engine[941].text_manager_impl = 0;
  engine[941].m_output_width = 0;
  survarium::game_options::game_options(
    (survarium::game_options *)&engine[907].m_output_height,
    &engine[942].text_manager_impl,
    (survarium::game *)engine);
  v13 = (_S10_1 & 1) == 0;
  engine[946].m_output_width = 0;
  engine[946].m_output_height = 0;
  LOBYTE(engine[947].text_manager_impl) = 0;
  engine[947].need_capture = 0;
  engine[947].m_output_height = 0;
  engine[948].text_manager_impl = 0;
  s_max_angular_velocity_command.m_engine = render_world;
  if ( v13 )
  {
    _S10_1 |= 1u;
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = engine;
    f.vtable = (boost::detail::function::vtable_base *)survarium::game::build_lpv_geometry;
    HIDWORD(v42.f_.f_) = survarium::game::build_lpv_geometry;
    v42.l_.a1_.t_ = 0;
    *((_DWORD *)&v42.l_ + 1) = engine;
    LODWORD(v42.f_.f_) = &f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v12,
      v42,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    vostok::console_commands::cc_delegate::cc_delegate(
      v14,
      (int)&s_build_lpv_geometry,
      "build_lpv_geometry",
      &f,
      0,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v15,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_build_lpv_geometry__);
    v12 = time_floating_factor;
  }
  if ( (_S10_1 & 2) == 0 )
  {
    v16 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + engine[10].m_output_height);
    _S10_1 |= 2u;
    time_factor.l_.a1_.t_ = v16;
    time_factor.f_.f_ = vostok::render::scene_renderer::reload_shaders;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      (boost::function<void __cdecl(char const *)> *)vostok::render::scene_renderer::reload_shaders,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > *)&f,
      time_factor,
      (int)v65);
    vostok::console_commands::cc_delegate::cc_delegate(
      v17,
      (int)&s_reload_shaders,
      "reload_shaders",
      &f,
      0,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v18,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_reload_shaders__);
    v12 = time_floating_factora;
  }
  if ( (_S10_1 & 4) == 0 )
  {
    _S10_1 |= 4u;
    vostok::fixed_string<512>::fixed_string<512>(
      (vostok::fixed_string<512> *)v12,
      &s_current_render_configuration,
      (char *)uri);
  }
  if ( (_S10_1 & 8) == 0 )
  {
    _S10_1 |= 8u;
    vostok::console_commands::cc_string::cc_string(
      (vostok::console_commands::cc_string *)v12,
      (int)&s_current_render_configuration_cc,
      "r_current_render_configuration",
      s_current_render_configuration.m_buffer,
      0x100u,
      (bool)v65,
      (const vostok::console_commands::command_type)v66,
      v67);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_current_render_configuration_cc__);
    v12 = time_floating_factorb;
  }
  if ( (_S10_1 & 0x10) == 0 )
  {
    v19 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + engine[10].m_output_height);
    _S10_1 |= 0x10u;
    time_factora.l_.a1_.t_ = v19;
    time_factora.f_.f_ = vostok::render::scene_renderer::reload_modified_textures;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      (boost::function<void __cdecl(char const *)> *)vostok::render::scene_renderer::reload_modified_textures,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > *)&f,
      time_factora,
      (int)v65);
    vostok::console_commands::cc_delegate::cc_delegate(
      v20,
      (int)&s_reload_modified_textures,
      "reload_modified_textures",
      &f,
      0,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v21,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_reload_modified_textures__);
    v12 = time_floating_factorc;
  }
  if ( (_S10_1 & 0x20) == 0 )
  {
    _S10_1 |= 0x20u;
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = engine;
    f.vtable = (boost::detail::function::vtable_base *)survarium::game::pause;
    HIDWORD(v43.f_.f_) = survarium::game::pause;
    v43.l_.a1_.t_ = 0;
    *((_DWORD *)&v43.l_ + 1) = engine;
    LODWORD(v43.f_.f_) = &f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v12,
      v43,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    vostok::console_commands::cc_delegate::cc_delegate(
      v22,
      (int)&pause_game_command,
      "pause",
      &f,
      0,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v23,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__pause_game_command__);
    v12 = time_floating_factord;
  }
  if ( (_S10_1 & 0x40) == 0 )
  {
    _S10_1 |= 0x40u;
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = engine;
    f.vtable = (boost::detail::function::vtable_base *)survarium::game::resume;
    HIDWORD(v44.f_.f_) = survarium::game::resume;
    v44.l_.a1_.t_ = 0;
    *((_DWORD *)&v44.l_ + 1) = engine;
    LODWORD(v44.f_.f_) = &f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v12,
      v44,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    vostok::console_commands::cc_delegate::cc_delegate(
      v24,
      (int)&resume_game_command,
      "resume",
      &f,
      0,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v25,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__resume_game_command__);
    v12 = time_floating_factore;
  }
  if ( (_S10_1 & 0x80u) == 0 )
  {
    _S10_1 |= 0x80u;
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = engine;
    f.vtable = (boost::detail::function::vtable_base *)survarium::game::demo_play;
    HIDWORD(v45.f_.f_) = survarium::game::demo_play;
    v45.l_.a1_.t_ = 0;
    *((_DWORD *)&v45.l_ + 1) = engine;
    LODWORD(v45.f_.f_) = &f;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v12,
      v45,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    vostok::console_commands::cc_delegate::cc_delegate(
      v26,
      (int)&demo_play_cc,
      "demo_play",
      &f,
      0,
      command_type_engine_internal);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v27,
      (int *)&f);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__demo_play_cc__);
    v12 = time_floating_factorf;
  }
  v69 = LODWORD(s_time_floating_factor);
  vostok::timing::floating_timer::set_time_factor_impl(
    (vostok::timing::floating_timer *)v12,
    (int)&engine[1],
    *(float *)&engine[2].m_output_width,
    s_time_floating_factor);
  engine[3].m_output_width = v69;
  QPC = vostok::timing::get_QPC();
  engine[1].m_output_width = QPC.LowPart;
  engine[2].text_manager_impl = (Scaleform::GFx::DrawTextManager *)QPC.LowPart;
  engine[1].m_output_height = QPC.HighPart;
  engine[1].text_manager_impl = 0;
  *(_DWORD *)&engine[1].need_capture = 0;
  *(_DWORD *)&engine[2].need_capture = QPC.HighPart;
  vostok::timing::timer::start(v29, (LARGE_INTEGER *)&engine[4]);
  if ( (_S10_1 & 0x100) == 0 )
  {
    _S10_1 |= 0x100u;
    survarium::inventory_cook::inventory_cook(v30);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_inventory_cook__);
    v30 = time_floating_factorg;
  }
  if ( (_S10_1 & 0x200) == 0 )
  {
    _S10_1 |= 0x200u;
    survarium::items_dictionary_cook::items_dictionary_cook((survarium::items_dictionary_cook *)v30);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_items_dictionary_cook__);
    v30 = time_floating_factorh;
  }
  if ( (_S10_1 & 0x400) == 0 )
  {
    _S10_1 |= 0x400u;
    survarium::scaleform_movie_cook::scaleform_movie_cook(
      (survarium::scaleform_movie_cook *)v30,
      (survarium::flash_factory *)&engine[11]);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_scaleform_movie_cook__);
    v30 = time_floating_factori;
  }
  if ( (_S10_1 & 0x800) == 0 )
  {
    _S10_1 |= 0x800u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x55,
      &s_player_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v65);
    s_player_cook.__vftable = (survarium::player_cook_vtbl *)&survarium::player_cook::`vftable';
    s_player_cook.m_game = (const survarium::game *)engine;
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_player_cook__);
    v30 = time_floating_factorj;
  }
  vostok::resources::resources_manager::register_cook(
    &s_player_cook,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)v30);
  if ( (_S10_1 & 0x1000) == 0 )
  {
    _S10_1 |= 0x1000u;
    survarium::profile_skin_visual_cook::profile_skin_visual_cook(v31, (survarium::game *)engine);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_profile_skin_visual_cook__);
    v31 = time_floating_factork;
  }
  if ( (_S10_1 & 0x2000) == 0 )
  {
    _S10_1 |= 0x2000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x5D,
      &s_pvp_match_core_cook,
      reuse_false,
      0xFFFFFFFC,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v65);
    s_pvp_match_core_cook.__vftable = (survarium::pvp_match_core_cook_vtbl *)&survarium::pvp_match_core_cook::`vftable';
    s_pvp_match_core_cook.m_is_server = 0;
    vostok::resources::resources_manager::register_cook(&s_pvp_match_core_cook, v32);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_pvp_match_core_cook__);
    v31 = time_floating_factorl;
  }
  if ( (_S10_1 & 0x4000) == 0 )
  {
    _S10_1 |= 0x4000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x59,
      &s_gather_victory_items_rule_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v65);
    s_gather_victory_items_rule_cook.__vftable = (survarium::gather_victory_items_rule_cook_vtbl *)&survarium::gather_victory_items_rule_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_gather_victory_items_rule_cook, v33);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_gather_victory_items_rule_cook__);
    v31 = time_floating_factorm;
  }
  if ( (_S10_1 & 0x8000) == 0 )
  {
    _S10_1 |= 0x8000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x5A,
      &s_player_respawn_rule_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v65);
    s_player_respawn_rule_cook.__vftable = (survarium::player_respawn_rule_cook_vtbl *)&survarium::player_respawn_rule_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_player_respawn_rule_cook, v34);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_player_respawn_rule_cook__);
    v31 = time_floating_factorn;
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S10_1) == 0 )
  {
    _S10_1 |= (unsigned int)&_sbh_sizeHeaderList;
    survarium::timelimit_rule_cook::timelimit_rule_cook(
      (survarium::timelimit_rule_cook *)v31,
      (survarium::game *)engine);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_timelimit_rule_cook__);
    v31 = time_floating_factoro;
  }
  if ( ((unsigned int)&loc_20000 & _S10_1) == 0 )
  {
    _S10_1 |= (unsigned int)&loc_20000;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x5C,
      &s_kd_stats_rule_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v65);
    s_kd_stats_rule_cook.__vftable = (survarium::kd_stats_rule_cook_vtbl *)&survarium::kd_stats_rule_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&s_kd_stats_rule_cook, v35);
    atexit((int (__cdecl *)())survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_kd_stats_rule_cook__);
    v31 = time_floating_factorp;
  }
  survarium::game::query_base_resources((survarium::game *)v31, (int)engine);
  v36 = survarium::g_allocator;
  v37 = type_info::raw_name(&survarium::chat_handler `RTTI Type Descriptor');
  v39 = vostok::memory::doug_lea_allocator::malloc_impl(v38, (int)v36, 0x28u, v37, v65, v66, v67);
  if ( v39 )
    survarium::chat_handler::chat_handler(v40, (int)v39, (survarium::game *)engine);
  else
    v41 = 0;
  engine[865].m_output_width = v41;
}
