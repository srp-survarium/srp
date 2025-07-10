void __thiscall survarium::game::~game(survarium::game *this)
{
  vostok::core::engine *v2; // ecx
  const char *v3; // eax
  survarium::stats_graph *v4; // ecx
  int f; // edi
  _BYTE *v6; // esi
  void *v7; // eax
  void *v8; // esi
  int v9; // edi
  _BYTE *v10; // esi
  void *v11; // eax
  void *v12; // esi
  int v13; // edi
  _BYTE *v14; // esi
  void *v15; // eax
  void *v16; // esi
  int v17; // edi
  _BYTE *v18; // esi
  void *v19; // eax
  void *v20; // esi
  int v21; // edi
  _BYTE *v22; // esi
  void *v23; // eax
  void *v24; // esi
  survarium::stats *m_stats; // esi
  int v26; // edi
  survarium::stats *v27; // eax
  void *v28; // esi
  survarium::stats_graph *m_fps_graph; // edi
  int v30; // esi
  survarium::game *v31; // ecx
  survarium::key_binder *m_key_binder; // eax
  void *v33; // esi
  int v34; // edi
  _BYTE *v35; // esi
  void *v36; // eax
  void *v37; // esi
  survarium::game_options *v38; // ecx
  survarium::scheduler *v39; // ecx
  vostok::configs::binary_config *m_object; // eax
  survarium::items_dictionary *v41; // eax
  vostok::render::base_output_window *v42; // eax
  vostok::console_commands::command_type v43; // [esp+0h] [ebp-10h]
  vostok::memory::base_allocator *v44; // [esp+4h] [ebp-Ch]

  v2 = s_engine_0;
  this->vostok::engine_user::world::__vftable = (survarium::game_vtbl *)&survarium::game::`vftable'{for `vostok::engine_user::world'};
  this->survarium::scaleform_game_engine::__vftable = (survarium::scaleform_game_engine_vtbl *)&survarium::game::`vftable'{for `survarium::scaleform_game_engine'};
  v3 = v2->get_user_data_directory(v2);
  vostok::console_commands::save("user.cfg", v3, v43, v44);
  f = (int)survarium::g_allocator.f_.f_;
  if ( this->m_network_client )
  {
    v6 = __RTCastToVoid((void **)&this->m_network_client->__vftable);
    ((void (__thiscall *)(survarium::base_network_client *, _DWORD))this->m_network_client->~survarium::base_network_client)(
      this->m_network_client,
      0);
    if ( v6 )
    {
      v7 = v6;
      v8 = *(void **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v8, v7);
    }
    this->m_network_client = 0;
  }
  v9 = (int)survarium::g_allocator.f_.f_;
  if ( this->m_main_menu )
  {
    v10 = __RTCastToVoid((void **)&this->m_main_menu->__vftable);
    ((void (__thiscall *)(survarium::main_menu *, _DWORD))this->m_main_menu->~survarium::base_game_scene)(
      this->m_main_menu,
      0);
    if ( v10 )
    {
      v11 = v10;
      v12 = *(void **)(v9 + 20);
      *(_BYTE *)(v9 + 42) = 0;
      vostok_mspace_free(v12, v11);
    }
    this->m_main_menu = 0;
  }
  v13 = (int)survarium::g_allocator.f_.f_;
  if ( this->m_lobby_menu )
  {
    v14 = __RTCastToVoid((void **)&this->m_lobby_menu->__vftable);
    ((void (__thiscall *)(survarium::lobby_menu *, _DWORD))this->m_lobby_menu->~survarium::base_game_scene)(
      this->m_lobby_menu,
      0);
    if ( v14 )
    {
      v15 = v14;
      v16 = *(void **)(v13 + 20);
      *(_BYTE *)(v13 + 42) = 0;
      vostok_mspace_free(v16, v15);
    }
    this->m_lobby_menu = 0;
  }
  v17 = (int)survarium::g_allocator.f_.f_;
  if ( this->m_login_menu )
  {
    v18 = __RTCastToVoid((void **)&this->m_login_menu->__vftable);
    ((void (__thiscall *)(survarium::login_menu *, _DWORD))this->m_login_menu->~survarium::base_game_scene)(
      this->m_login_menu,
      0);
    if ( v18 )
    {
      v19 = v18;
      v20 = *(void **)(v17 + 20);
      *(_BYTE *)(v17 + 42) = 0;
      vostok_mspace_free(v20, v19);
    }
    this->m_login_menu = 0;
  }
  v21 = (int)survarium::g_allocator.f_.f_;
  if ( this->m_console )
  {
    v22 = __RTCastToVoid((void **)&this->m_console->__vftable);
    ((void (__thiscall *)(vostok::engine::console *, _DWORD))this->m_console->~vostok::engine::console)(
      this->m_console,
      0);
    if ( v22 )
    {
      v23 = v22;
      v24 = *(void **)(v21 + 20);
      *(_BYTE *)(v21 + 42) = 0;
      vostok_mspace_free(v24, v23);
    }
    this->m_console = 0;
  }
  m_stats = this->m_stats;
  v26 = (int)survarium::g_allocator.f_.f_;
  if ( m_stats )
  {
    m_stats->m_ui_world->destroy_window(m_stats->m_ui_world, m_stats->m_main_window);
    v27 = m_stats;
    v28 = *(void **)(v26 + 20);
    *(_BYTE *)(v26 + 42) = 0;
    vostok_mspace_free(v28, v27);
    this->m_stats = 0;
  }
  m_fps_graph = this->m_fps_graph;
  v30 = (int)survarium::g_allocator.f_.f_;
  if ( m_fps_graph )
  {
    survarium::stats_graph::~stats_graph(v4, (int)m_fps_graph);
    *(_BYTE *)(v30 + 42) = 0;
    vostok_mspace_free(*(void **)(v30 + 20), m_fps_graph);
    this->m_fps_graph = 0;
  }
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::flash_factory,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    &this->m_flash_factory);
  m_key_binder = this->m_key_binder;
  if ( m_key_binder )
  {
    v33 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v33, m_key_binder);
    this->m_key_binder = 0;
  }
  v34 = (int)survarium::g_allocator.f_.f_;
  if ( this->m_chat_handler )
  {
    v35 = __RTCastToVoid((void **)&this->m_chat_handler->__vftable);
    ((void (__thiscall *)(survarium::chat_handler *, _DWORD))this->m_chat_handler->~survarium::chat_handler)(
      this->m_chat_handler,
      0);
    if ( v35 )
    {
      v36 = v35;
      v37 = *(void **)(v34 + 20);
      *(_BYTE *)(v34 + 42) = 0;
      vostok_mspace_free(v37, v36);
    }
    this->m_chat_handler = 0;
  }
  survarium::game::deinitialize_modules(v31);
  survarium::game_options::~game_options(v38);
  m_object = this->m_text_translator.m_text_data.m_object;
  if ( m_object )
  {
    v39 = (survarium::scheduler *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v39 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_text_translator.m_text_data.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_text_translator.m_text_data.m_object);
  }
  if ( this->m_swf_input_translator.char_map._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)&this->m_swf_input_translator,
      this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_parent);
    this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_left = &this->m_swf_input_translator.char_map._M_t._M_header._M_data;
    this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_parent = 0;
    this->m_swf_input_translator.char_map._M_t._M_header._M_data._M_right = &this->m_swf_input_translator.char_map._M_t._M_header._M_data;
    this->m_swf_input_translator.char_map._M_t._M_node_count = 0;
  }
  v41 = this->m_items_dictionary.m_object;
  if ( v41 )
  {
    v39 = (survarium::scheduler *)_InterlockedExchangeAdd(&v41->m_reference_count, 0xFFFFFFFF);
    if ( !v39 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_items_dictionary.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_items_dictionary.m_object);
  }
  survarium::scheduler::~scheduler(v39);
  survarium::game_world::~game_world(&this->m_game_world);
  v42 = this->m_render_output_window.m_object;
  if ( v42 && !_InterlockedExchangeAdd(&v42->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_render_output_window.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_render_output_window.m_object);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_application_activation);
}
