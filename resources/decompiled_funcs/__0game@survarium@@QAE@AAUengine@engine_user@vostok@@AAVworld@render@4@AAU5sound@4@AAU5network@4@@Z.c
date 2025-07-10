void __userpurge survarium::game::game(
        vostok::render::world *render_world@<eax>,
        survarium::game *this,
        vostok::engine_user::engine *engine,
        vostok::sound::world *sound,
        vostok::network::world *network)
{
  vostok::memory::base_allocator *f; // edx
  const vostok::math::float4x4 *v8; // xmm0_4
  void *p_functor; // esi
  boost::function1<void,char const *> *v10; // ecx
  unsigned int v11; // eax
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::game::renderer *m_renderer; // edx
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char *m_buffer; // ecx
  void (__cdecl *v16)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v18)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v19)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned __int64 QuadPart; // rax
  unsigned __int64 v21; // rax
  vostok::memory::doug_lea_allocator *v22; // ecx
  Scaleform::RefCountVImpl *v23; // eax
  survarium::scaleform_movie_cook *v24; // ecx
  survarium::flash_factory *v25; // eax
  survarium::flash_factory *m_flash_factory; // edx
  void *v27; // eax
  survarium::chat_handler *v28; // ecx
  survarium::chat_handler *v29; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v30; // [esp-10h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v31; // [esp-10h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v32; // [esp-10h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::game>,boost::_bi::list1<boost::_bi::value<survarium::game *> > > v33; // [esp-10h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > v34; // [esp-8h] [ebp-48h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > v35; // [esp-8h] [ebp-48h]
  int v36; // [esp+0h] [ebp-40h]
  char v37; // [esp+17h] [ebp-29h]
  LARGE_INTEGER PerformanceCount; // [esp+18h] [ebp-28h] BYREF
  boost::function<void __cdecl(char const *)> functor; // [esp+20h] [ebp-20h] BYREF

  this->vostok::engine_user::world::__vftable = (survarium::game_vtbl *)&survarium::game::`vftable'{for `vostok::engine_user::world'};
  this->survarium::scaleform_game_engine::__vftable = (survarium::scaleform_game_engine_vtbl *)&survarium::game::`vftable'{for `survarium::scaleform_game_engine'};
  this->hide_game_stats = 0;
  vostok::timing::timer::timer(&this->m_timer);
  vostok::timing::timer::timer(&this->m_permanent_timer);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&this->m_application_activation, 0x2710u);
  this->m_render_output_window.m_object = 0;
  this->m_engine = engine;
  this->m_network_world = network;
  this->m_render_world = render_world;
  this->m_sound_world = sound;
  this->m_input_world = 0;
  this->m_ui_world = 0;
  this->m_renderer = render_world->m_game_renderer;
  survarium::game_world::game_world(&this->m_game_world, this);
  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  this->m_main_menu = 0;
  this->m_lobby_menu = 0;
  this->m_login_menu = 0;
  this->m_scheduler.m_inactive_objects._M_impl._M_start = 0;
  this->m_scheduler.m_inactive_objects._M_impl._M_finish = 0;
  this->m_scheduler.m_inactive_objects._M_impl._M_end_of_storage.m_allocator = f;
  this->m_scheduler.m_inactive_objects._M_impl._M_end_of_storage._M_data = 0;
  this->m_scheduler.m_active_objects._M_impl._M_start = 0;
  this->m_scheduler.m_active_objects._M_impl._M_finish = 0;
  this->m_scheduler.m_active_objects._M_impl._M_end_of_storage.m_allocator = f;
  this->m_scheduler.m_active_objects._M_impl._M_end_of_storage._M_data = 0;
  this->m_scheduler.m_current_index = 0;
  this->m_scheduler.m_objects[0] = &this->m_scheduler.m_inactive_objects;
  this->m_scheduler.m_objects[1] = &this->m_scheduler.m_active_objects;
  this->m_active_scene = 0;
  this->m_text_wnd = 0;
  this->m_items_dictionary.m_object = 0;
  this->m_network_client = 0;
  *(_OWORD *)&functor.vtable = 0;
  *(_QWORD *)&this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_left = *(_QWORD *)&functor.functor.obj_ptr;
  this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_color = 0;
  this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_parent = 0;
  this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_left = &this->m_swf_input_translator.char_map._M_t._M_header._M_data;
  this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_right = &this->m_swf_input_translator.char_map._M_t._M_header._M_data;
  this->m_swf_input_translator.char_map._M_t._M_node_count = 0;
  this->m_swf_input_translator.char_map._M_t._M_key_compare.gap0 = v37;
  survarium::swf_input_translator::initialize(
    (survarium::swf_input_translator *)&this->m_scheduler.m_active_objects,
    &this->m_swf_input_translator.char_map);
  this->m_is_active = 0;
  this->m_text_translator.m_text_data.m_object = 0;
  this->m_last_frame_time = 0.0;
  v8 = clear_value;
  this->m_first_frame_time_in_ms = 0;
  this->m_previous_frame_time_in_ms = 0;
  this->m_permanent_time_in_ms = 0;
  this->m_current_frame_id = -1;
  this->m_current_time_in_ms = 0;
  this->m_enabled = 0;
  this->m_initialized = 0;
  LODWORD(this->m_last_sound_timescale_factor) = v8;
  this->m_is_paused = 0;
  this->m_lpv_geometry_builded = 0;
  this->m_network_client_options.m_begin = this->m_network_client_options.m_buffer;
  this->m_network_client_options.m_end = this->m_network_client_options.m_buffer;
  this->m_network_client_options.m_max_end = (char *)&this->m_project_resource_name;
  this->m_network_client_options.m_buffer[0] = 0;
  this->m_network_client_options.m_buffer[0] = 0;
  this->m_project_resource_name.m_begin = this->m_project_resource_name.m_buffer;
  this->m_project_resource_name.m_end = this->m_project_resource_name.m_buffer;
  this->m_project_resource_name.m_max_end = (char *)&this->m_game_options;
  this->m_project_resource_name.m_buffer[0] = 0;
  p_functor = &this->m_game_options.survarium::flash_external_handler;
  this->m_project_resource_name.m_buffer[0] = 0;
  survarium::flash_external_handler::flash_external_handler(
    (survarium::flash_external_handler *)&this->m_project_resource_name,
    &this->m_game_options.__vftable);
  this->m_game_options.__vftable = (survarium::game_options_vtbl *)&survarium::game_options::`vftable'{for `vostok::input::handler'};
  this->m_game_options.__vftable = (survarium::flash_external_handler_vtbl *)&survarium::game_options::`vftable'{for `survarium::flash_external_handler'};
  this->m_game_options.m_options_ui.m_object = 0;
  this->m_game_options.m_cursor_ui.m_object = 0;
  this->m_game_options.m_game = this;
  this->m_game_options.m_mouse_pos = 0;
  this->m_game_options.m_waiting_for_bind_action = kLASTACTION;
  this->m_game_options.m_conflicted_action_ids._M_impl._M_start = 0;
  this->m_game_options.m_conflicted_action_ids._M_impl._M_finish = 0;
  this->m_game_options.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data = 0;
  this->m_debug_window_type = debug_window_none;
  this->m_debug_window = 0;
  s_max_angular_velocity_command.m_engine = engine;
  v11 = _S7_5;
  if ( (_S7_5 & 1) == 0 )
  {
    _S7_5 |= 1u;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::build_lpv_geometry;
    (&functor.vtable)[1] = 0;
    v30.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *))(unsigned int)survarium::game::build_lpv_geometry;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v30.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(v10, (int)&functor, (int)p_functor, v30, v36);
    vostok::console_commands::cc_delegate::cc_delegate(
      &s_build_lpv_geometry,
      "build_lpv_geometry",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v12 )
          v12(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_build_lpv_geometry__);
    v11 = _S7_5;
  }
  if ( (v11 & 2) == 0 )
  {
    m_renderer = this->m_renderer;
    _S7_5 = v11 | 2;
    v34.l_.a1_.t_ = m_renderer->m_scene;
    v34.f_.f_ = vostok::render::scene_renderer::reload_shaders;
    p_functor = &functor;
    functor.vtable = 0;
    boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *>>>>(
      (boost::function1<void,char const *> *)vostok::render::scene_renderer::reload_shaders,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > *)&functor,
      v34);
    vostok::console_commands::cc_delegate::cc_delegate(
      &s_reload_shaders,
      "reload_shaders",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v14 )
          v14(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_reload_shaders__);
    v11 = _S7_5;
  }
  m_buffer = s_current_render_configuration.m_buffer;
  if ( (v11 & 4) == 0 )
  {
    v11 |= 4u;
    _S7_5 = v11;
    s_current_render_configuration.m_begin = s_current_render_configuration.m_buffer;
    s_current_render_configuration.m_end = s_current_render_configuration.m_buffer;
    s_current_render_configuration.m_max_end = (char *)&scaleform_alloc;
    s_current_render_configuration.m_buffer[0] = 0;
  }
  if ( (v11 & 8) == 0 )
  {
    _S7_5 = v11 | 8;
    vostok::console_commands::cc_string::cc_string(
      (vostok::console_commands::cc_string *)s_current_render_configuration.m_buffer,
      "r_current_render_configuration",
      s_current_render_configuration.m_buffer,
      0x100u,
      1,
      command_type_user_specific,
      execution_filter_general);
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_current_render_configuration_cc__);
    v11 = _S7_5;
  }
  if ( (v11 & 0x10) == 0 )
  {
    _S7_5 = v11 | 0x10;
    v35.l_.a1_.t_ = this->m_renderer->m_scene;
    v35.f_.f_ = vostok::render::scene_renderer::reload_modified_textures;
    p_functor = &functor;
    functor.vtable = 0;
    boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *>>>>(
      (boost::function1<void,char const *> *)vostok::render::scene_renderer::reload_modified_textures,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::scene_renderer>,boost::_bi::list1<boost::_bi::value<vostok::render::scene_renderer *> > > *)&functor,
      v35);
    vostok::console_commands::cc_delegate::cc_delegate(
      &s_reload_modified_textures,
      "reload_modified_textures",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v16 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v16 )
          v16(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_reload_modified_textures__);
    v11 = _S7_5;
  }
  if ( (v11 & 0x20) == 0 )
  {
    _S7_5 = v11 | 0x20;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::pause;
    (&functor.vtable)[1] = 0;
    v31.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *))(unsigned int)survarium::game::pause;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v31.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(
      (boost::function1<void,char const *> *)m_buffer,
      (int)&functor,
      (int)p_functor,
      v31,
      v36);
    vostok::console_commands::cc_delegate::cc_delegate(
      &pause_game_command,
      "pause",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v17 )
          v17(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__pause_game_command__);
    v11 = _S7_5;
  }
  if ( (v11 & 0x40) == 0 )
  {
    _S7_5 = v11 | 0x40;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::resume;
    (&functor.vtable)[1] = 0;
    v32.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *))(unsigned int)survarium::game::resume;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v32.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(
      (boost::function1<void,char const *> *)m_buffer,
      (int)&functor,
      (int)p_functor,
      v32,
      v36);
    vostok::console_commands::cc_delegate::cc_delegate(
      &resume_game_command,
      "resume",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v18 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v18 )
          v18(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__resume_game_command__);
    v11 = _S7_5;
  }
  if ( (v11 & 0x80u) == 0 )
  {
    _S7_5 = v11 | 0x80;
    functor.vtable = (boost::detail::function::vtable_base *)survarium::game::commit_suicide;
    (&functor.vtable)[1] = 0;
    v33.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *))(unsigned int)survarium::game::commit_suicide;
    functor.functor.obj_ptr = this;
    *(_QWORD *)&v33.l_.a1_.t_ = *(_QWORD *)&functor.functor.obj_ptr;
    boost::function1<void,char const *>::function1<void,char const *>(
      (boost::function1<void,char const *> *)m_buffer,
      (int)&functor,
      (int)p_functor,
      v33,
      v36);
    vostok::console_commands::cc_delegate::cc_delegate(
      &commit_suicide_cc,
      "suicide",
      &functor,
      0,
      command_type_engine_internal);
    if ( functor.vtable )
    {
      if ( ((int)functor.vtable & 1) == 0 )
      {
        v19 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
        if ( v19 )
          v19(&functor.functor, &functor.functor, 2);
      }
    }
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__commit_suicide_cc__);
  }
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    QuadPart = PerformanceCount.QuadPart;
  }
  this->m_timer.m_start_time = QuadPart;
  this->m_timer.m_current_time = 0;
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v21 = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter((LARGE_INTEGER *)&functor);
    v21 = *(_QWORD *)&functor.vtable;
  }
  v22 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->m_permanent_timer.m_start_time = v21;
  this->m_permanent_timer.m_current_time = 0;
  v23 = (Scaleform::RefCountVImpl *)vostok::memory::doug_lea_allocator::malloc_impl(v22, 8u);
  if ( v23 )
    survarium::flash_factory::flash_factory(
      (survarium::flash_factory *)&this->survarium::scaleform_game_engine,
      v23,
      &this->survarium::scaleform_game_engine);
  else
    v25 = 0;
  this->m_flash_factory = v25;
  if ( (_S7_5 & 0x100) == 0 )
  {
    _S7_5 |= 0x100u;
    survarium::inventory_cook::inventory_cook(&s_inventory_cook);
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_inventory_cook__);
  }
  if ( (_S7_5 & 0x200) == 0 )
  {
    _S7_5 |= 0x200u;
    survarium::player_parameters_modifyer_cook::player_parameters_modifyer_cook(&s_player_parameters_cook);
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_player_parameters_cook__);
  }
  if ( (_S7_5 & 0x400) == 0 )
  {
    _S7_5 |= 0x400u;
    survarium::items_dictionary_cook::items_dictionary_cook(&s_items_dictionary_cook);
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_items_dictionary_cook__);
  }
  if ( (_S7_5 & 0x800) == 0 )
  {
    m_flash_factory = this->m_flash_factory;
    _S7_5 |= 0x800u;
    survarium::scaleform_movie_cook::scaleform_movie_cook(v24, m_flash_factory);
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_scaleform_movie_cook__);
  }
  if ( (_S7_5 & 0x1000) == 0 )
  {
    _S7_5 |= 0x1000u;
    survarium::profile_skin_visual_cook::profile_skin_visual_cook((survarium::profile_skin_visual_cook *)v24, this);
    atexit(survarium::game::game_::_2_::_dynamic_atexit_destructor_for__s_profile_skin_visual_cook__);
  }
  survarium::game::query_base_resources((survarium::game *)v24, this);
  v27 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0x20u);
  if ( v27 )
  {
    survarium::chat_handler::chat_handler(v28, (int)v27, this);
    this->m_chat_handler = v29;
  }
  else
  {
    this->m_chat_handler = 0;
  }
}
