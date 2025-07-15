void __thiscall survarium::game::on_base_resources_created(
        survarium::game *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *v3; // esi
  vostok::configs::binary_config *m_object; // ebx
  vostok::configs::binary_config *v5; // eax
  survarium::items_dictionary *v6; // ecx
  survarium::items_dictionary *v7; // eax
  bool v8; // zf
  survarium::game *v9; // ecx
  survarium::game_options *v10; // ecx
  vostok::configs::binary_config *v11; // eax
  vostok::resources::unmanaged_intrusive_base *v12; // ecx
  vostok::ui::window *v13; // eax
  vostok::ui::window *m_text_wnd; // ecx
  vostok::engine::console *(__thiscall **p_create_game_console)(vostok::engine_user::engine *, vostok::ui::world *, vostok::input::world *); // esi
  vostok::input::world *v16; // eax
  int v17; // eax
  vostok::engine::console *v18; // eax
  vostok::memory::doug_lea_allocator *f; // ecx
  survarium::stats *v20; // ecx
  survarium::stats *v21; // esi
  vostok::memory::doug_lea_allocator *v22; // ecx
  survarium::stats_graph *v23; // eax
  vostok::memory::doug_lea_allocator *v24; // ecx
  survarium::game *v25; // ecx
  survarium::main_menu *v26; // esi
  survarium::main_menu *v27; // ecx
  BOOL m_enabled; // eax
  void (__thiscall *enable)(struct survarium::game *, bool); // edx
  const vostok::math::float4x4 *v30; // xmm0_4
  void (__thiscall *on_application_activate)(struct survarium::game *); // edx
  int v32; // eax
  int v33; // ebx
  survarium::game *v34; // ecx
  char *v35; // ecx
  vostok::fixed_string<512> v36; // [esp-210h] [ebp-64Ch] BYREF
  bool v37; // [esp-4h] [ebp-440h]
  void *v38[5]; // [esp+0h] [ebp-43Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v39; // [esp+14h] [ebp-428h] BYREF
  int v40; // [esp+18h] [ebp-424h]
  vostok::fixed_string<512> client_str; // [esp+1Ch] [ebp-420h] BYREF
  char v42; // [esp+228h] [ebp-214h] BYREF
  vostok::fixed_string<512> host; // [esp+22Ch] [ebp-210h] BYREF
  char v44; // [esp+438h] [ebp-4h] BYREF

  v3 = 0;
  v39.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v39,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v39.m_object;
  if ( v39.m_object )
  {
    v3 = v39.m_object;
    _InterlockedExchangeAdd(&v39.m_object->m_reference_count, 1u);
  }
  v5 = 0;
  if ( v3 )
  {
    v5 = v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  v6 = (survarium::items_dictionary *)v5;
  v7 = this->m_items_dictionary.m_object;
  this->m_items_dictionary.m_object = v6;
  if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v8 = (_S8 & 1) == 0;
  this->m_initialized = 1;
  if ( v8 )
  {
    _S8 |= 1u;
    g_input_handler.__vftable = (survarium::global_input_handler_vtbl *)&survarium::global_input_handler::`vftable';
    g_input_handler.m_game = this;
    atexit(survarium::game::on_base_resources_created_::_2_::_dynamic_atexit_destructor_for__g_input_handler__);
  }
  this->m_input_world->add_handler(this->m_input_world, &g_input_handler);
  survarium::game::register_cooks(v9, (int)this);
  survarium::game_options::initialize(v10);
  v39.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v39,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  survarium::chat_handler::initialize(
    this->m_chat_handler,
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v39);
  v11 = v39.m_object;
  if ( v39.m_object )
  {
    v12 = &v39.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v39.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v12, v11);
  }
  v13 = this->m_ui_world->create_window(this->m_ui_world);
  v39.m_object = (vostok::configs::binary_config *)1133903872;
  this->m_text_wnd = v13;
  v40 = 0;
  v13->set_position(v13, (const vostok::math::float2 *)&v39);
  m_text_wnd = this->m_text_wnd;
  v39.m_object = (vostok::configs::binary_config *)1142292480;
  v40 = 1142292480;
  m_text_wnd->set_size(m_text_wnd, (const vostok::math::float2 *)&v39);
  this->m_text_wnd->set_visible(this->m_text_wnd, 1);
  p_create_game_console = &this->m_engine->create_game_console;
  v16 = this->input_world(this);
  v17 = ((int (__thiscall *)(survarium::game *, vostok::input::world *))this->ui_world)(this, v16);
  v18 = (vostok::engine::console *)((int (__thiscall *)(vostok::engine_user::engine *, int))*p_create_game_console)(
                                     this->m_engine,
                                     v17);
  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  v38[0] = (void *)72;
  this->m_console = v18;
  v21 = (survarium::stats *)vostok::memory::doug_lea_allocator::malloc_impl(f, (unsigned int)v38[0]);
  if ( v21 )
  {
    v21->m_ui_world = this->m_ui_world;
    v21->m_crosshair_dist = 0.0;
    v21->m_odd_row_color = -8323073;
    v21->m_even_row_color = -128;
    survarium::stats::create(v20, v21);
  }
  else
  {
    v21 = 0;
  }
  v22 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  v38[0] = (void *)40;
  this->m_stats = v21;
  v23 = (survarium::stats_graph *)vostok::memory::doug_lea_allocator::malloc_impl(v22, (unsigned int)v38[0]);
  if ( v23 )
  {
    LODWORD(v23->m_time_interval) = clear_value;
    v23->m_invalid_value = infinity_15;
    v23->m_important_value0 = default_fps_3;
    v23->m_important_value1 = 60.0;
    v23->m_newest_value = 0;
    v23->m_values_pool = 0;
    v23->m_cumulative_value = 0.0;
    v23->m_count = 0;
    v23->m_color = -16711936;
  }
  else
  {
    v23 = 0;
  }
  v24 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  v38[0] = (void *)192;
  this->m_fps_graph = v23;
  v26 = (survarium::main_menu *)vostok::memory::doug_lea_allocator::malloc_impl(v24, (unsigned int)v38[0]);
  if ( v26 )
  {
    survarium::base_game_scene::base_game_scene(v26, this);
    v38[0] = v26;
    v26->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::main_menu_vtbl *)&survarium::main_menu::`vftable'{for `survarium::game_scene'};
    v26->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::main_menu::`vftable'{for `survarium::engine'};
    v26->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::main_menu::`vftable';
    survarium::main_menu::query_resources(v27, v38[0]);
  }
  else
  {
    v26 = 0;
  }
  this->m_main_menu = v26;
  survarium::game::create_debug_window(v25, (int)this);
  m_enabled = this->m_enabled;
  enable = this->enable;
  this->m_viewport.min.x = 0.0;
  this->m_viewport.min.y = 0.0;
  v30 = clear_value;
  v38[0] = (void *)m_enabled;
  LODWORD(this->m_viewport.max.x) = clear_value;
  LODWORD(this->m_viewport.max.y) = v30;
  enable(this, (bool)v38[0]);
  if ( this->m_is_active )
  {
    on_application_activate = this->on_application_activate;
    this->m_is_active = 0;
    on_application_activate(this);
  }
  client_str.m_begin = client_str.m_buffer;
  client_str.m_end = client_str.m_buffer;
  client_str.m_max_end = &v42;
  client_str.m_buffer[0] = 0;
  if ( vostok::command_line::key::is_set_as_string(&s_net_login_client, &client_str) )
  {
    host.m_begin = host.m_buffer;
    host.m_end = host.m_buffer;
    host.m_max_end = &v44;
    host.m_buffer[0] = 0;
    strchr(client_str.m_begin, 0x3Au);
    if ( v32 )
    {
      if ( v32 - (unsigned int)client_str.m_begin != -1 )
      {
        v38[0] = (void *)vostok::command_line::key::is_set(&s_is_spectator);
        *(_DWORD *)v36.m_buffer = v38;
        v33 = client_str.m_end - client_str.m_begin;
        v36.m_end = &v36.m_buffer[4];
        memcpy(
          (unsigned __int8 *)&v36.m_buffer[4],
          (unsigned __int8 *)client_str.m_begin,
          client_str.m_end - client_str.m_begin);
        v36.m_max_end = &v36.m_buffer[v33 + 4];
        v36.m_begin = (char *)this;
        *v36.m_max_end = 0;
        survarium::game::create_and_assign_network_client(v34, v36, v37, (int)v38[0]);
      }
    }
  }
  else
  {
    v38[0] = 0;
    v36.m_end = &v36.m_buffer[4];
    v36.m_max_end = &v36.m_buffer[4];
    *(_DWORD *)v36.m_buffer = v38;
    v36.m_buffer[4] = 0;
    v35 = "188.93.23.27:25100";
    do
    {
      if ( v36.m_max_end >= (char *)*(_DWORD *)v36.m_buffer )
        break;
      *v36.m_max_end++ = *v35++;
    }
    while ( *v35 );
    v36.m_begin = (char *)this;
    *v36.m_max_end = 0;
    survarium::game::create_and_assign_network_client((survarium::game *)v35, v36, v37, (int)v38[0]);
  }
}
