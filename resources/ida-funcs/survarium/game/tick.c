void __thiscall survarium::game::tick(survarium::game *this, unsigned int current_frame_id)
{
  unsigned __int64 v3; // rax
  unsigned int v4; // ebx
  survarium::base_game_scene *m_active_scene; // eax
  survarium::chat_handler *v6; // ecx
  survarium::chat_handler *m_chat_handler; // eax
  survarium::base_network_client *m_network_client; // ecx
  vostok::ui::window_vtbl *v9; // esi
  int v10; // eax
  survarium::game *v11; // ecx
  survarium::game *v12; // ecx
  vostok::ui::world *v13; // eax
  vostok::render::base_output_window *m_object; // ecx
  vostok::resources::unmanaged_resource *v15; // esi
  survarium::base_game_scene *v16; // edx
  vostok::render::game::renderer *m_renderer; // ecx
  const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene_view; // ebx
  vostok::ui::world_vtbl *v19; // edx
  const vostok::ui::font *v20; // eax
  vostok::render::game::renderer *v21; // ecx
  unsigned int m_current_time_in_ms; // [esp+14h] [ebp-1Ch]
  unsigned int v23; // [esp+18h] [ebp-18h]
  bool v24; // [esp+1Ch] [ebp-14h]
  vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> render_output_window; // [esp+24h] [ebp-Ch] BYREF
  vostok::render::game::renderer *v26; // [esp+28h] [ebp-8h]
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene; // [esp+2Ch] [ebp-4h]

  v3 = 1000 * vostok::timing::timer::get_elapsed_ticks(&this->m_timer) / vostok::timing::g_qpc_per_second.QuadPart;
  v4 = v3 - this->m_current_time_in_ms;
  this->m_current_time_in_ms = v3;
  this->m_permanent_time_in_ms = 1000
                               * vostok::timing::timer::get_elapsed_ticks(&this->m_permanent_timer)
                               / vostok::timing::g_qpc_per_second.QuadPart;
  m_current_time_in_ms = this->m_current_time_in_ms;
  this->m_current_frame_id = current_frame_id;
  survarium::scheduler::on_frame(&this->m_scheduler, v4, m_current_time_in_ms);
  m_active_scene = this->m_active_scene;
  if ( m_active_scene && m_active_scene->m_render_scene.m_object )
  {
    this->m_input_world->tick(this->m_input_world, this->m_permanent_time_in_ms);
    this->m_active_scene->tick(this->m_active_scene, v4, this->m_current_time_in_ms, this->m_is_paused);
    if ( this->m_game_options.m_is_active )
      survarium::game_options::tick(&this->m_game_options, v4, v23, v24);
    m_chat_handler = this->m_chat_handler;
    if ( m_chat_handler->m_active )
      survarium::chat_handler::tick(v6, (int)m_chat_handler, v4);
    m_network_client = this->m_network_client;
    if ( m_network_client )
      m_network_client->tick(m_network_client, this->m_current_time_in_ms, this->m_is_paused);
    this->m_active_scene->on_after_tick(this->m_active_scene);
    this->m_text_wnd->remove_all_children(this->m_text_wnd);
    this->m_text_wnd->tick(this->m_text_wnd);
    v9 = this->m_text_wnd->__vftable;
    v10 = ((int (__thiscall *)(vostok::ui::world *, vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *))this->m_ui_world->get_renderer)(
            this->m_ui_world,
            &this->m_active_scene->m_render_scene_view);
    ((void (__thiscall *)(vostok::ui::window *, int))v9->draw)(this->m_text_wnd, v10);
    this->m_ui_world->tick(this->m_ui_world);
    if ( this->m_console->get_active(this->m_console) )
      this->m_console->tick(this->m_console, &this->m_active_scene->m_render_scene_view);
    survarium::game::update_stats(v11, (int)this);
    if ( this->m_debug_window_type && !this->m_console->get_active(this->m_console) )
      survarium::game::draw_debug_window(v12, (int)this);
    v13 = this->ui_world(this);
    m_object = this->m_render_output_window.m_object;
    v15 = 0;
    render_output_window.m_object = 0;
    if ( m_object )
    {
      v15 = m_object;
      render_output_window.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    v16 = this->m_active_scene;
    m_renderer = this->m_renderer;
    p_m_render_scene_view = &v16->m_render_scene_view;
    scene = &v16->m_render_scene;
    v19 = v13->__vftable;
    v26 = m_renderer;
    v20 = v19->default_font(v13);
    vostok::render::game::renderer::draw_scene(
      v26,
      scene,
      p_m_render_scene_view,
      &render_output_window,
      &this->m_viewport,
      v20);
    if ( v15 )
    {
      if ( !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
    }
    vostok::render::game::renderer::end_frame(this->m_renderer);
  }
  else
  {
    v21 = (vostok::render::game::renderer *)this->m_network_client;
    if ( v21 )
      (*(void (__thiscall **)(vostok::render::game::renderer *, unsigned int, bool))&v21->m_world->m_logic_channel.m_channel.m_forward_queue.m_cache_line_pad[4])(
        v21,
        this->m_current_time_in_ms,
        this->m_is_paused);
    vostok::render::game::renderer::end_frame(v21);
  }
}
