void __thiscall survarium::game::on_configs_loaded(survarium::game *this, vostok::resources::queries_result *result)
{
  vostok::command_line::key *v3; // ecx
  const char *v4; // edi
  vostok::command_line::key *v5; // ecx
  vostok::journaling::journal_usage_enum v6; // esi
  bool is_set; // al
  vostok::input::input_world *v8; // esi
  vostok::journaling::journal_usage_enum v9; // eax
  vostok::engine_user::engine *m_engine; // ecx
  HWND__ *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  int v16; // ecx
  survarium::key_binder *v17; // eax
  survarium::game *v18; // ecx
  int v19; // ecx
  survarium::game *v20; // ecx
  survarium::text_translator *v21; // ecx
  HWND__ *v22; // eax
  vostok::engine_user::engine *v23; // ecx
  vostok::engine_user::engine_vtbl *v24; // eax
  vostok::console_commands::console_command *v25; // edi
  vostok::console_commands::console_command *v26; // eax
  vostok::journaling::journal *v27; // ecx
  float v28; // xmm0_4
  vostok::fs_new::device_file_system_no_watcher_proxy *v29; // ecx
  HWND__ *v30; // ecx
  bool v31; // al
  bool v32; // zf
  bool has_passed_filters; // al
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v34; // ecx
  vostok::variant<32> *v35; // ecx
  vostok::variant<32> *v36; // ecx
  _BYTE v37[20]; // [esp-4h] [ebp-404h] BYREF
  const char *v38; // [esp+10h] [ebp-3F0h]
  const char *v39; // [esp+14h] [ebp-3ECh]
  unsigned int v40; // [esp+18h] [ebp-3E8h]
  HWND__ *window_handle; // [esp+1Ch] [ebp-3E4h] BYREF
  int v42; // [esp+20h] [ebp-3E0h]
  int v43[2]; // [esp+24h] [ebp-3DCh] BYREF
  const vostok::variant<32> *v44; // [esp+2Ch] [ebp-3D4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > f[2]; // [esp+30h] [ebp-3D0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v46; // [esp+50h] [ebp-3B0h] BYREF
  vostok::resources::request v47; // [esp+70h] [ebp-390h] BYREF
  _DWORD v48[2]; // [esp+78h] [ebp-388h] BYREF
  _BYTE v49[20]; // [esp+80h] [ebp-380h] BYREF
  _DWORD *v50; // [esp+A0h] [ebp-360h]
  int v51; // [esp+A4h] [ebp-35Ch]
  _BYTE v52[40]; // [esp+A8h] [ebp-358h] BYREF
  int v53; // [esp+D0h] [ebp-330h]
  int v54; // [esp+D4h] [ebp-32Ch]
  vostok::buffer_string v55; // [esp+D8h] [ebp-328h] BYREF
  _BYTE v56[512]; // [esp+E4h] [ebp-31Ch] BYREF
  char v57; // [esp+2E4h] [ebp-11Ch] BYREF
  vostok::fs_new::native_path_string v58; // [esp+2E8h] [ebp-118h] BYREF

  v42 = 0;
  v55.m_begin = v56;
  v55.m_end = v56;
  v55.m_max_end = &v57;
  v56[0] = 0;
  if ( vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_replay_journal) )
    vostok::command_line::key::is_set_as_string(v3, &s_replay_journal.m_string_value, &v55);
  v4 = v55.m_begin != v55.m_end ? v55.m_begin : 0;
  if ( vostok::command_line::key::is_set(v3, (int)&s_replay_journal) )
  {
    v6 = replay_journal;
  }
  else
  {
    is_set = vostok::command_line::key::is_set(v5, (int)&s_no_journal);
    v6 = !is_set;
    if ( is_set )
      goto LABEL_7;
  }
  *(float *)&window_handle = COERCE_FLOAT(&s_hdd);
  vostok::fs_new::native_path_string::native_path_string(&v58);
  vostok::journaling::generate_journal_file_name(&v58, v4);
  vostok::journaling::journal::journal(
    v6,
    (const vostok::fs_new::device_file_system_no_watcher_proxy *)&window_handle,
    (int)&vostok::core::g_journal,
    v58.m_string.m_begin);
  _InterlockedExchange(&vostok::core::g_journal.m_initialized, 1);
LABEL_7:
  s_initialized_1 = 1;
  if ( this )
    v8 = (vostok::input::input_world *)&this->gap8;
  else
    v8 = 0;
  v9 = vostok::core::journal_usage();
  m_engine = this->m_engine;
  LOBYTE(window_handle) = v9 == replay_journal;
  v11 = m_engine->get_main_window_handle(m_engine);
  vostok::input::input_world::input_world(v8, (int)&s_world_4, v11, window_handle, (bool)v38);
  _InterlockedExchange(&s_world_4.m_initialized, 1);
  *(_DWORD *)&v37[16] = this;
  this->m_input_world = s_world_4.m_variable;
  survarium::game::initialize_ui((survarium::game *)&s_world_4.m_initialized, *(vostok::ui::engine **)&v37[16]);
  v12 = survarium::g_allocator;
  v13 = type_info::raw_name(&survarium::key_binder `RTTI Type Descriptor');
  v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v12, 0x364u, v13, v38, v39, v40);
  if ( v15 )
    survarium::key_binder::key_binder(this, (survarium::key_binder *)v15);
  else
    v17 = 0;
  *(_QWORD *)&v37[12] = 0x100000000LL;
  *(_DWORD *)&v37[8] = v16;
  this->m_key_binder = v17;
  vostok::resources::query_result_for_user::get_managed_resource(
    &result->m_queries[0],
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v37[8]);
  survarium::game::load_cc_script(
    v18,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)this,
    *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v37[8],
    v37[12],
    *(int *)&v37[16]);
  *(_QWORD *)&v37[12] = 0x200000001LL;
  *(_DWORD *)&v37[8] = v19;
  vostok::resources::query_result_for_user::get_managed_resource(
    &result->m_queries[1],
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v37[8]);
  survarium::game::load_cc_script(
    v20,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)this,
    *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v37[8],
    v37[12],
    *(int *)&v37[16]);
  survarium::text_translator::load_text_localization(v21, (int)&this->m_text_translator);
  v22 = this->m_engine->get_render_window_handle(this->m_engine);
  v23 = this->m_engine;
  LODWORD(f[0].f_.f_) = v22;
  HIDWORD(f[0].f_.f_) = this->m_flash_factory.m_render_thread_queue;
  v24 = v23->__vftable;
  LOWORD(f[1].f_.f_) = 257;
  f[0].l_.a1_.t_ = (survarium::game *)1280;
  *((_DWORD *)&f[0].l_ + 1) = 720;
  if ( !v24->command_line_editor(v23) )
  {
    v25 = vostok::console_commands::find("r_fullscreen");
    v26 = vostok::console_commands::find("r_resolution");
    survarium::parse_resolution((char *)v26[1].__vftable, v43);
    f[0].l_.a1_.t_ = (survarium::game *)v43[0];
    *((_DWORD *)&f[0].l_ + 1) = v43[1];
    BYTE1(f[1].f_.f_) = v25[1].~vostok::console_commands::console_command == 0;
  }
  if ( vostok::core::journal_usage() == record_journal )
  {
    if ( survarium::g_mouse_invert )
      v28 = FLOAT_N1_0;
    else
      v28 = s_bm_current_air_resistance;
    v42 = LODWORD(v28);
    *(float *)&window_handle = survarium::g_mouse_sensitivity * 0.1;
    *(float *)&v46.vtable = survarium::g_mouse_sensitivity * 0.1;
    *(float *)&(&v46.vtable)[1] = (double)*((unsigned int *)&f[0].l_ + 1)
                                / (double)(unsigned int)f[0].l_.a1_.t_
                                * (float)(survarium::g_mouse_sensitivity * 0.1)
                                * v28
                                * 0.95492965;
    vostok::journaling::journal::start_writing(
      v27,
      (int)vostok::core::g_journal.m_variable,
      &window_handle,
      (vostok::journaling::writer_ptr *)8,
      (const vostok::journaling::data_chunk_type_enum)v38);
    vostok::fs_new::device_file_system_no_watcher_proxy::write(
      v29,
      *((_DWORD **)window_handle + 1),
      *(void ***)window_handle,
      &v46,
      8u);
  }
  else if ( vostok::core::journal_usage() == replay_journal )
  {
    vostok::journaling::journal::try_start_reading(
      (vostok::journaling::journal *)v30,
      (int)vostok::core::g_journal.m_variable,
      &window_handle,
      (vostok::journaling::reader_ptr *)8,
      (const vostok::journaling::data_chunk_type_enum)v38);
    v30 = window_handle;
    if ( *(float *)&window_handle == 0.0 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)2),
            v30 = *(HWND__ **)&v37[16],
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v30,
          &v46);
        v42 = 2;
        vostok::logging::append(
          &v46,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game.cpp",
          0x1C4u,
          "void __thiscall survarium::game::on_configs_loaded(class vostok::resources::queries_result &)",
          "game",
          error,
          "Journal has no mouse sensitivity chunk");
      }
      v32 = (v42 & 2) == 0;
    }
    else
    {
      vostok::fs_new::device_file_system_proxy_base::read(
        (vostok::fs_new::device_file_system_proxy_base *)window_handle,
        *((_DWORD **)window_handle + 1),
        *(void ***)window_handle,
        &g_journaling_mouse_sensitivity,
        8u);
      if ( !vostok::core::g_log_filter_tree
        || (v31 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)4),
            v30 = *(HWND__ **)&v37[16],
            v31) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v30,
          &v46);
        v42 = 1;
        vostok::logging::append(
          &v46,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game.cpp",
          0x1C2u,
          "void __thiscall survarium::game::on_configs_loaded(class vostok::resources::queries_result &)",
          "game",
          info,
          "Replay journal settings: h:%f v:%f",
          g_journaling_mouse_sensitivity.x,
          g_journaling_mouse_sensitivity.y);
      }
      v32 = (v42 & 1) == 0;
    }
    if ( !v32 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v30,
        (int *)&v46);
  }
  v50 = 0;
  v51 = 0;
  vostok::variant<32>::destroy_previous_variable_if_needed((vostok::variant<32> *)v30, (int)v48);
  v51 = vostok::detail::type_to_int<vostok::render::output_window_configuration>::get();
  qmemcpy(v49, f, sizeof(v49));
  v50 = v48;
  v44 = (const vostok::variant<32> *)v48;
  (&v46.vtable)[1] = 0;
  v46.vtable = (boost::detail::function::vtable_base *)survarium::game::on_render_output_window_created;
  v46.functor.obj_ptr = this;
  *(_DWORD *)&v37[4] = survarium::game::on_render_output_window_created;
  *(_DWORD *)&v37[8] = 0;
  *(_DWORD *)&v37[12] = this;
  *(_DWORD *)v37 = f;
  v48[0] = &vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::`vftable';
  v53 = 0;
  v54 = 0;
  v47.path = "game_render_output_window";
  v47.id = render_output_window_class;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > *)v37,
    (int)v46.functor.vostok_pointer_size_alignment[1]);
  vostok::resources::query_resources(&v47, 1u, survarium::g_allocator, &v44, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v34, (int *)f);
  vostok::variant<32>::destroy_previous_variable_if_needed(v35, (int)v52);
  vostok::variant<32>::destroy_previous_variable_if_needed(v36, (int)v48);
}
