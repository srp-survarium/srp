void __thiscall survarium::game::on_base_resources_created(
        survarium::game *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // edi
  vostok::particle::particle_system_instance_impl *v4; // esi
  survarium::items_dictionary *v5; // eax
  bool v6; // zf
  vostok::particle::particle_system_instance_impl *v7; // eax
  survarium::game *v8; // ecx
  survarium::game_options *v9; // ecx
  vostok::ui::window *v10; // eax
  vostok::ui::window *m_text_wnd; // ecx
  vostok::engine::console *(__thiscall **p_create_game_console)(vostok::engine_user::engine *, vostok::ui::world *, vostok::input::world *); // esi
  vostok::input::world *v13; // eax
  int v14; // eax
  vostok::engine::console *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // esi
  char *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // ecx
  survarium::stats *v19; // ecx
  char *v20; // esi
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // ecx
  char *v24; // eax
  vostok::ui::world *m_ui_world; // ecx
  vostok::ui::window *v26; // eax
  vostok::ui::window *m_debug_window; // ecx
  vostok::ui::window *v28; // ecx
  BOOL m_enabled; // ecx
  survarium::game_vtbl *v30; // eax
  float v31; // xmm0_4
  vostok::command_line::key *v32; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // ecx
  int v34; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // ecx
  int v36; // eax
  bool v37; // al
  survarium::game *v38; // ecx
  bool has_passed_filters; // al
  vostok::fixed_string<512> v40; // [esp-208h] [ebp-678h] BYREF
  BOOL is_set; // [esp+4h] [ebp-46Ch]
  const char *v42; // [esp+8h] [ebp-468h]
  const char *v43; // [esp+Ch] [ebp-464h]
  unsigned int v44; // [esp+10h] [ebp-460h]
  int v45; // [esp+18h] [ebp-458h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v46; // [esp+1Ch] [ebp-454h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v47; // [esp+20h] [ebp-450h] BYREF
  float v48; // [esp+24h] [ebp-44Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v49; // [esp+28h] [ebp-448h] BYREF
  int v50; // [esp+2Ch] [ebp-444h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v51; // [esp+30h] [ebp-440h] BYREF
  vostok::fixed_string<512> string; // [esp+50h] [ebp-420h] BYREF
  char v53; // [esp+25Ch] [ebp-214h] BYREF
  _BYTE *v54; // [esp+260h] [ebp-210h]
  _BYTE *v55; // [esp+264h] [ebp-20Ch]
  char *v56; // [esp+268h] [ebp-208h]
  _BYTE v57[512]; // [esp+26Ch] [ebp-204h] BYREF
  char v58; // [esp+46Ch] [ebp-4h] BYREF

  v50 = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v47,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v47.m_object;
  v4 = 0;
  v49.m_object = 0;
  if ( v47.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
    v4 = m_object;
    v49.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v46.m_object = 0;
  if ( v4 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v46);
    v46.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  v5 = (survarium::items_dictionary *)v46.m_object;
  v46.m_object = (vostok::particle::particle_system_instance_impl *)this->m_items_dictionary.m_object;
  this->m_items_dictionary.m_object = v5;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v46);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47);
  v6 = this->m_ui_sounds_count == 0;
  HIBYTE(v45) = 0;
  if ( !v6 )
  {
    v49.m_object = (vostok::particle::particle_system_instance_impl *)&data->m_queries[1];
    do
    {
      v7 = v49.m_object;
      v49.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v49.m_object + 736);
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v46,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v7->m_sub_fat.m_parent);
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        &v47,
        (survarium::pure_game_effect_emitter_base *)v46.m_object);
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        &v47,
        &this->m_ui_sounds[HIBYTE(v45)]);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v46);
      ++HIBYTE(v45);
    }
    while ( HIBYTE(v45) < this->m_ui_sounds_count );
  }
  v6 = (_S12 & 1) == 0;
  this->m_initialized = 1;
  if ( v6 )
  {
    _S12 |= 1u;
    g_input_handler.__vftable = (survarium::global_input_handler_vtbl *)&survarium::global_input_handler::`vftable';
    g_input_handler.m_game = this;
    atexit((int (__cdecl *)())survarium::game::on_base_resources_created_::_8_::_dynamic_atexit_destructor_for__g_input_handler__);
  }
  this->m_input_world->add_handler(this->m_input_world, &g_input_handler);
  survarium::game::register_cooks(v8, (int)this);
  survarium::game_options::initialize(v9, (int)&this->m_game_options);
  v10 = this->m_ui_world->create_window(this->m_ui_world);
  v47.m_object = (survarium::pure_game_effect_emitter_base *)LODWORD(FLOAT_300_0);
  this->m_text_wnd = v10;
  v48 = 0.0;
  v10->set_position(v10, (const vostok::math::float2 *)&v47);
  m_text_wnd = this->m_text_wnd;
  v47.m_object = (survarium::pure_game_effect_emitter_base *)LODWORD(FLOAT_600_0);
  v48 = FLOAT_600_0;
  m_text_wnd->set_size(m_text_wnd, (const vostok::math::float2 *)&v47);
  this->m_text_wnd->set_visible(this->m_text_wnd, 1);
  p_create_game_console = &this->m_engine->create_game_console;
  v13 = this->input_world(this);
  v14 = ((int (__thiscall *)(survarium::game *, vostok::input::world *))this->ui_world)(this, v13);
  v15 = (vostok::engine::console *)((int (__thiscall *)(vostok::engine_user::engine *, int))*p_create_game_console)(
                                     this->m_engine,
                                     v14);
  v16 = survarium::g_allocator;
  this->m_console = v15;
  v17 = type_info::raw_name(&survarium::stats `RTTI Type Descriptor');
  v20 = vostok::memory::doug_lea_allocator::malloc_impl(v18, (int)v16, 0x4Cu, v17, v42, v43, v44);
  if ( v20 )
  {
    *(_DWORD *)v20 = this->m_ui_world;
    *((_DWORD *)v20 + 16) = 0;
    *((_DWORD *)v20 + 17) = -8323073;
    *((_DWORD *)v20 + 18) = -128;
    survarium::stats::create(v19, (int **)v20);
  }
  else
  {
    v20 = 0;
  }
  this->m_stats = (survarium::stats *)v20;
  v21 = survarium::g_allocator;
  v22 = type_info::raw_name(&survarium::stats_graph `RTTI Type Descriptor');
  v24 = vostok::memory::doug_lea_allocator::malloc_impl(v23, (int)v21, 0x28u, v22, v42, v43, v44);
  if ( v24 )
  {
    *((float *)v24 + 2) = s_bm_current_air_resistance;
    *((float *)v24 + 3) = infinity_21;
    *((float *)v24 + 4) = default_fps_4;
    *((float *)v24 + 5) = FLOAT_60_0;
    *(_DWORD *)v24 = 0;
    *((_DWORD *)v24 + 1) = 0;
    *((_DWORD *)v24 + 6) = 0;
    *((_DWORD *)v24 + 8) = 0;
    *((_DWORD *)v24 + 9) = -16711936;
  }
  else
  {
    v24 = 0;
  }
  m_ui_world = this->m_ui_world;
  this->m_fps_graph = (survarium::stats_graph *)v24;
  v26 = m_ui_world->create_window(m_ui_world);
  this->m_debug_window = v26;
  v26->set_visible(v26, 1);
  m_debug_window = this->m_debug_window;
  v47.m_object = 0;
  v48 = FLOAT_120_0;
  m_debug_window->set_position(m_debug_window, (const vostok::math::float2 *)&v47);
  v28 = this->m_debug_window;
  v47.m_object = (survarium::pure_game_effect_emitter_base *)LODWORD(FLOAT_2024_0);
  v48 = FLOAT_768_0;
  v28->set_size(v28, (const vostok::math::float2 *)&v47);
  m_enabled = this->m_enabled;
  v30 = this->vostok::engine_user::world::__vftable;
  this->m_viewport.min.x = 0.0;
  this->m_viewport.min.y = 0.0;
  v31 = s_bm_current_air_resistance;
  is_set = m_enabled;
  this->m_viewport.max.x = s_bm_current_air_resistance;
  this->m_viewport.max.y = v31;
  v30->enable(this, is_set);
  if ( this->m_is_active )
  {
    this->m_is_active = 0;
    this->on_application_activate(this);
  }
  string.m_begin = string.m_buffer;
  string.m_end = string.m_buffer;
  string.m_max_end = &v53;
  string.m_buffer[0] = 0;
  if ( !vostok::command_line::key::is_set_as_string(v32, &s_net_login_client.m_string_value, &string) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)4),
          v33 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)is_set,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v33,
        &v51);
      v50 = 2;
      vostok::logging::append(
        &v51,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game.cpp",
        0x26Du,
        "void __thiscall survarium::game::on_base_resources_created(class vostok::resources::queries_result &)",
        "game",
        info,
        "create network client");
    }
    if ( (v50 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v33,
        (int *)&v51);
    is_set = 0;
    vostok::fixed_string<512>::fixed_string<512>((vostok::fixed_string<512> *)v33, &v40, "188.93.23.27:25100");
    goto LABEL_35;
  }
  v54 = v57;
  v55 = v57;
  v56 = &v58;
  v57[0] = 0;
  strchr(string.m_begin, 0x3Au);
  v35 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)is_set;
  if ( v34 )
    v36 = v34 - (unsigned int)string.m_begin;
  else
    v36 = -1;
  if ( v36 != -1 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v37 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
          v35 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)is_set,
          v37) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v35,
        &v51);
      v50 = 1;
      vostok::logging::append(
        &v51,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game.cpp",
        0x247u,
        "void __thiscall survarium::game::on_base_resources_created(class vostok::resources::queries_result &)",
        "game",
        info,
        "create network client");
    }
    if ( (v50 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v35,
        (int *)&v51);
    is_set = vostok::command_line::key::is_set((vostok::command_line::key *)v35, (int)&s_is_spectator);
    vostok::fixed_string<512>::fixed_string<512>(&v40, &string);
LABEL_35:
    survarium::game::create_and_assign_network_client(v38, v40, is_set);
  }
}
