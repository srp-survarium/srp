char __thiscall survarium::game::tick(survarium::game *this, unsigned int current_frame_id)
{
  survarium::base_game_scene *m_active_scene; // eax
  vostok::journaling::journal *v4; // ecx
  unsigned int elapsed_msec; // eax
  vostok::journaling::journal *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // eax
  bool has_passed_filters; // al
  survarium::scheduler *v11; // ecx
  vostok::command_line::key *v12; // ecx
  vostok::replay_match_reader *v13; // ecx
  unsigned int *p_m_replay_last_read_input_time_in_ms; // esi
  vostok::replay_match_reader *v15; // ecx
  vostok::replay_match_reader *v16; // ecx
  survarium::game_world_core *v17; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v18; // ecx
  survarium::game_world_core *v19; // ecx
  vostok::replay_match_reader *v20; // ecx
  survarium::game_world_core *v21; // ecx
  unsigned int m_replay_match_finish_time_in_ms; // eax
  survarium::flash_movie *v23; // ecx
  vostok::ui::window *m_text_wnd; // ecx
  vostok::ui::world **p_m_ui_world; // edi
  void (__thiscall **p_draw)(vostok::ui::window *, vostok::render::ui::renderer *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *); // esi
  int v27; // eax
  survarium::game *v28; // ecx
  survarium::game *v29; // ecx
  vostok::ui::world *v30; // eax
  survarium::base_game_scene *v31; // edx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene_view; // esi
  vostok::render::game::renderer *p_m_render_scene; // edi
  vostok::ui::world_vtbl *v34; // edx
  const vostok::ui::font *v35; // eax
  vostok::render::game::renderer *v36; // ecx
  vostok::journaling::journal *v37; // [esp+0h] [ebp-54h]
  vostok::journaling::data_chunk_type_enum v38; // [esp+4h] [ebp-50h]
  int buffer; // [esp+14h] [ebp-40h] BYREF
  unsigned int current_time; // [esp+18h] [ebp-3Ch] BYREF
  unsigned int frame_delta; // [esp+1Ch] [ebp-38h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v42; // [esp+20h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v43; // [esp+24h] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v44; // [esp+28h] [ebp-2Ch] BYREF
  unsigned __int8 player_id[4]; // [esp+2Ch] [ebp-28h] BYREF
  vostok::render::game::renderer *m_renderer; // [esp+30h] [ebp-24h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> is_server_aware_of; // [esp+34h] [ebp-20h] BYREF

  v42.m_object = 0;
  this->m_current_frame_id = current_frame_id;
  m_active_scene = this->m_active_scene;
  if ( !m_active_scene || !m_active_scene->m_render_scene.m_object )
  {
    vostok::render::game::renderer::end_frame((vostok::render::game::renderer *)this, (int)this->m_renderer);
    return 1;
  }
  if ( vostok::core::journal_usage() == replay_journal )
  {
    vostok::journaling::journal::try_start_reading(
      v4,
      (int)vostok::core::g_journal.m_variable,
      &v44,
      (vostok::journaling::reader_ptr *)1,
      v38);
    if ( !v44.m_object )
      return 0;
    elapsed_msec = vostok::journaling::reader::r<unsigned int>((vostok::journaling::reader *)v44.m_object);
  }
  else
  {
    elapsed_msec = vostok::timing::floating_timer::get_elapsed_msec(
                     (vostok::timing::floating_timer *)v4,
                     &this->m_timer);
  }
  current_time = elapsed_msec;
  if ( vostok::core::journal_usage() == record_journal && this->m_active_scene == &this->m_game_world )
  {
    vostok::journaling::journal::start_writing(
      v7,
      (int)vostok::core::g_journal.m_variable,
      &v44,
      (vostok::journaling::writer_ptr *)1,
      v38);
    vostok::fs_new::device_file_system_no_watcher_proxy::write(
      (vostok::fs_new::device_file_system_no_watcher_proxy *)v44.m_object,
      (_DWORD *)v44.m_object->type,
      (void **)&v44.m_object->~vostok::particle::particle_system_instance,
      &current_time,
      4u);
  }
  v8 = current_time;
  if ( this->m_current_time_in_ms == -1 )
    this->m_current_time_in_ms = current_time;
  v9 = v8 - this->m_current_time_in_ms;
  this->m_time_was_eaten_last_tick = 0;
  frame_delta = v9;
  if ( v9 > 0x7D0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)4),
          v7 = v37,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7,
        &is_server_aware_of);
      v42.m_object = (vostok::particle::particle_system_instance_impl *)1;
      vostok::logging::append(
        &is_server_aware_of,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game.cpp",
        0x376u,
        "bool __thiscall survarium::game::tick(unsigned int)",
        "game",
        info,
        "eating time: %d.%03d, but max frame delta is %d.%03d",
        frame_delta / 0x3E8,
        frame_delta % 0x3E8,
        2,
        0);
    }
    if ( ((int)v42.m_object & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&is_server_aware_of);
    this->m_current_time_in_ms = current_time - 2000;
    frame_delta = 2000;
    this->m_time_was_eaten_last_tick = 1;
  }
  this->m_permanent_time_in_ms = vostok::timing::timer::get_elapsed_msec(
                                   (vostok::timing::timer *)v7,
                                   (int)&this->m_permanent_timer);
  if ( frame_delta )
    survarium::scheduler::on_frame(
      v11,
      &this->m_scheduler.m_inactive_objects._M_impl._M_start,
      (vostok::math::float4x4 *)frame_delta,
      (survarium::scheduler::record *)current_time);
  this->m_input_world->tick(this->m_input_world, this->m_permanent_time_in_ms);
  if ( !frame_delta )
    goto LABEL_43;
  if ( !vostok::command_line::key::is_set(v12, (int)&s_match_replay) )
    goto $LN179;
  p_m_replay_last_read_input_time_in_ms = &this->m_replay_last_read_input_time_in_ms;
  if ( !this->m_replay_last_read_input_time_in_ms )
    survarium::game::pause(this);
  while ( *p_m_replay_last_read_input_time_in_ms <= current_time + 50 )
  {
    if ( this->m_replay_match_finish_time_in_ms != -1 )
      break;
    HIBYTE(buffer) = 0;
    if ( !vostok::replay_match_reader::read_bytes(v13, (int)&this->m_replay_match_reader, (char *)&buffer + 3, 1u) )
      break;
    if ( HIBYTE(buffer) )
    {
      if ( HIBYTE(buffer) == 1 )
      {
        vostok::replay_match_reader::read_bytes(v15, (int)&this->m_replay_match_reader, &m_renderer, 1u);
        vostok::replay_match_reader::read_bytes(
          v20,
          (int)&this->m_replay_match_reader,
          p_m_replay_last_read_input_time_in_ms,
          4u);
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v44,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world.m_match);
        survarium::game_world_core::enter_match(
          v21,
          (int)v44.m_object->m_lods[1].m_emitter_instance_list.m_last,
          (survarium::game_event_history_item::events_enum)m_renderer,
          this->m_replay_last_read_input_time_in_ms);
        v18 = &v44;
      }
      else
      {
        if ( HIBYTE(buffer) == 2 )
        {
          is_server_aware_of.functor.vostok_pointer_size_alignment[2] = (void *)-1;
          LOBYTE(is_server_aware_of.vtable) = -1;
          memset(&(&is_server_aware_of.vtable)[1], 0, 12);
          vostok::replay_match_reader::read_bytes(v15, (int)&this->m_replay_match_reader, &is_server_aware_of, 0x14u);
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v43,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world.m_match);
          survarium::game_world_core::change_input(
            v19,
            (survarium::game_world_core *)v43.m_object->m_lods[1].m_emitter_instance_list.m_last,
            (unsigned __int8 *)&is_server_aware_of,
            0);
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v43);
          this->m_replay_last_read_input_time_in_ms = (unsigned int)is_server_aware_of.functor.vostok_pointer_size_alignment[2];
          goto LABEL_36;
        }
        vostok::replay_match_reader::read_bytes(v15, (int)&this->m_replay_match_reader, player_id, 1u);
        vostok::replay_match_reader::read_bytes(
          v16,
          (int)&this->m_replay_match_reader,
          p_m_replay_last_read_input_time_in_ms,
          4u);
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v42,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world.m_match);
        survarium::game_world_core::leave_match(
          v17,
          (survarium::game_world_core *)v42.m_object->m_lods[1].m_emitter_instance_list.m_last,
          *(survarium::game_event_history_item::events_enum *)player_id,
          this->m_replay_last_read_input_time_in_ms);
        v18 = &v42;
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v18);
    }
    else
    {
      vostok::replay_match_reader::read_bytes(
        v15,
        (int)&this->m_replay_match_reader,
        &this->m_replay_match_finish_time_in_ms,
        4u);
    }
LABEL_36:
    p_m_replay_last_read_input_time_in_ms = &this->m_replay_last_read_input_time_in_ms;
  }
  m_replay_match_finish_time_in_ms = this->m_replay_match_finish_time_in_ms;
  if ( m_replay_match_finish_time_in_ms != -1 && current_time >= m_replay_match_finish_time_in_ms )
    vostok::debug::terminate("Match replay finished");
$LN179:
  this->m_active_scene->tick(this->m_active_scene, frame_delta, current_time, this->m_is_paused);
  if ( this->m_game_options.m_is_active )
    survarium::game_options::tick(&this->m_game_options, frame_delta, v23);
LABEL_43:
  this->m_network_client->tick(this->m_network_client, current_time, this->m_is_paused);
  if ( frame_delta )
    this->m_active_scene->on_after_tick(this->m_active_scene);
  m_text_wnd = this->m_text_wnd;
  this->m_current_time_in_ms = current_time;
  m_text_wnd->remove_all_children(m_text_wnd);
  this->m_text_wnd->tick(this->m_text_wnd);
  p_m_ui_world = &this->m_ui_world;
  p_draw = &this->m_text_wnd->draw;
  v27 = ((int (__thiscall *)(vostok::ui::world *, vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *))this->m_ui_world->get_renderer)(
          this->m_ui_world,
          &this->m_active_scene->m_render_scene_view);
  ((void (__thiscall *)(vostok::ui::window *, int))*p_draw)(this->m_text_wnd, v27);
  (*p_m_ui_world)->tick(*p_m_ui_world);
  if ( this->m_console->get_active(this->m_console) )
    this->m_console->tick(this->m_console, &this->m_active_scene->m_render_scene_view);
  survarium::game::update_stats(v28, (vostok::console_commands::execution_filter)p_m_ui_world, (unsigned int)this);
  if ( this->m_debug_window_type )
  {
    if ( !this->m_console->get_active(this->m_console) )
      survarium::game::draw_debug_window(v29, (int)this);
  }
  v30 = this->ui_world(this);
  v31 = this->m_active_scene;
  p_m_render_scene_view = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v31->m_render_scene_view;
  p_m_render_scene = (vostok::render::game::renderer *)&v31->m_render_scene;
  v34 = v30->__vftable;
  m_renderer = this->m_renderer;
  v35 = v34->default_font(v30);
  vostok::render::game::renderer::draw_scene(
    p_m_render_scene,
    m_renderer,
    p_m_render_scene_view,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_output_window,
    &this->m_viewport,
    v35);
  vostok::render::game::renderer::end_frame(v36, (int)this->m_renderer);
  return 1;
}
