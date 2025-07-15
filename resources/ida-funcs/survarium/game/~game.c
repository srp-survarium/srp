void __thiscall survarium::game::~game(survarium::game *this)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  vostok::memory::doug_lea_allocator *v3; // ecx
  char *v4; // edi
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // edi
  vostok::memory::doug_lea_allocator *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // esi
  char *v10; // edi
  vostok::memory::doug_lea_allocator *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // esi
  char *m_stats; // edi
  vostok::memory::doug_lea_allocator *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // esi
  survarium::stats_graph *m_fps_graph; // edi
  vostok::memory::doug_lea_allocator *v17; // ecx
  vostok::sound::sound_debug_stats *m_sound_stats; // eax
  vostok::memory::doug_lea_allocator *v19; // esi
  survarium::flash_text_manager *m_flash_text_manager; // esi
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // edi
  vostok::memory::doug_lea_allocator *v23; // ecx
  survarium::game *p_m_ui_sounds; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v25; // eax
  char *v26; // esi
  vostok::memory::doug_lea_allocator *v27; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v28; // edi
  vostok::journaling::journal *m_variable; // esi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *v30; // ecx
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *v31; // ecx
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *v32; // ecx
  survarium::flash_factory *v33; // ecx
  vostok::memory::doug_lea_allocator *v34; // [esp-4h] [ebp-28h]
  vostok::memory::doug_lea_allocator *v35; // [esp-4h] [ebp-28h]
  const char *v36; // [esp+0h] [ebp-24h]
  char *v37; // [esp+0h] [ebp-24h]
  const char *v38; // [esp+0h] [ebp-24h]
  const char *v39; // [esp+4h] [ebp-20h]
  const char *v40; // [esp+4h] [ebp-20h]
  unsigned int v41; // [esp+8h] [ebp-1Ch]
  unsigned int v42; // [esp+8h] [ebp-1Ch]
  vostok::memory::doug_lea_allocator *v43; // [esp+Ch] [ebp-18h]
  vostok::particle::particle_system_instance_impl *m_object; // [esp+10h] [ebp-14h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v45; // [esp+14h] [ebp-10h]

  this->vostok::engine_user::world::__vftable = (survarium::game_vtbl *)&survarium::game::`vftable'{for `vostok::engine_user::world'};
  this->survarium::scaleform_game_engine::__vftable = (survarium::scaleform_game_engine_vtbl *)&survarium::game::`vftable'{for `survarium::scaleform_game_engine'};
  cfg_save_user(this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::base_network_client>(
    survarium::g_allocator,
    (survarium::game_effect **)&this->m_network_client,
    v36,
    v39,
    v41);
  v2 = survarium::g_allocator;
  v3 = v34;
  if ( this->m_lobby_menu )
  {
    v4 = __RTCastToVoid((void **)&this->m_lobby_menu->__vftable);
    ((void (__thiscall *)(survarium::lobby_menu *, _DWORD))this->m_lobby_menu->~survarium::base_game_scene)(
      this->m_lobby_menu,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v5, (int)v2, v4, v37, v40, v42);
    this->m_lobby_menu = 0;
  }
  v6 = survarium::g_allocator;
  if ( this->m_login_menu )
  {
    v7 = __RTCastToVoid((void **)&this->m_login_menu->__vftable);
    ((void (__thiscall *)(survarium::login_menu *, _DWORD))this->m_login_menu->~survarium::base_game_scene)(
      this->m_login_menu,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v8, (int)v6, v7, v37, v40, v42);
    this->m_login_menu = 0;
  }
  v9 = survarium::g_allocator;
  if ( this->m_console )
  {
    v10 = __RTCastToVoid((void **)&this->m_console->__vftable);
    ((void (__thiscall *)(vostok::engine::console *, _DWORD))this->m_console->~vostok::engine::console)(
      this->m_console,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v11, (int)v9, v10, v37, v40, v42);
    this->m_console = 0;
  }
  v12 = survarium::g_allocator;
  m_stats = (char *)this->m_stats;
  if ( m_stats )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)m_stats + 36))(*(_DWORD *)m_stats, *((_DWORD *)m_stats + 1));
    vostok::memory::doug_lea_allocator::free_impl(v14, (int)v12, m_stats, v37, v40, v42);
    this->m_stats = 0;
  }
  v15 = survarium::g_allocator;
  m_fps_graph = this->m_fps_graph;
  if ( m_fps_graph )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::stats_graph>(
      m_fps_graph,
      (vostok::memory::detail::call_destructor_predicate *)v37);
    vostok::memory::doug_lea_allocator::free_impl(v17, (int)v15, (char *)m_fps_graph, v38, v40, v42);
    this->m_fps_graph = 0;
  }
  m_sound_stats = this->m_sound_stats;
  if ( m_sound_stats )
  {
    v19 = survarium::g_allocator;
    m_sound_stats->m_scene = 0;
    vostok::memory::doug_lea_allocator::free_impl(v3, (int)v19, (char *)m_sound_stats, v37, v40, v42);
    this->m_sound_stats = 0;
  }
  m_flash_text_manager = this->m_flash_text_manager;
  if ( m_flash_text_manager )
  {
    if ( m_flash_text_manager->text_manager_impl )
      ((void (__thiscall *)(Scaleform::GFx::DrawTextManager *, int))m_flash_text_manager->text_manager_impl->~Scaleform::GFx::DrawTextManager)(
        m_flash_text_manager->text_manager_impl,
        1);
    operator delete(m_flash_text_manager);
    v3 = v35;
  }
  if ( this->m_key_binder )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      v3,
      (int)survarium::g_allocator,
      (char *)this->m_key_binder,
      v37,
      v40,
      v42);
    this->m_key_binder = 0;
  }
  v21 = survarium::g_allocator;
  if ( this->m_chat_handler )
  {
    v22 = __RTCastToVoid((void **)&this->m_chat_handler->__vftable);
    ((void (__thiscall *)(survarium::chat_handler *, _DWORD))this->m_chat_handler->~survarium::chat_handler)(
      this->m_chat_handler,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v23, (int)v21, v22, v37, v40, v42);
    this->m_chat_handler = 0;
  }
  p_m_ui_sounds = (survarium::game *)&this->m_ui_sounds;
  if ( this->m_ui_sounds )
  {
    v43 = survarium::g_allocator;
    v25 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_ui_sounds->vostok::engine_user::world::__vftable;
    v26 = (char *)&v25[-2];
    v27 = (vostok::memory::doug_lea_allocator *)p_m_ui_sounds->vostok::engine_user::world::__vftable[-1].~survarium::game;
    m_object = v25[-1].m_object;
    v28 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)v25 + (_DWORD)v27 * (int)v25[-2].m_object);
    while ( 1 )
    {
      v45 = v25;
      if ( v25 == v28 )
        break;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v25);
      v25 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)v45 + (_DWORD)m_object);
    }
    vostok::memory::doug_lea_allocator::free_impl(v27, (int)v43, v26, v37, v40, v42);
  }
  survarium::game::deinitialize_modules(p_m_ui_sounds, (int)this);
  s_initialized_1 = 0;
  if ( vostok::core::g_journal.m_initialized )
  {
    m_variable = vostok::core::g_journal.m_variable;
    if ( vostok::core::g_journal.m_variable->m_usage == record_journal )
      vostok::core::g_journal.m_variable->m_device.m_device_file_system->flush(
        vostok::core::g_journal.m_variable->m_device.m_device_file_system,
        vostok::core::g_journal.m_variable->m_file);
    m_variable->m_device.m_device_file_system->close(m_variable->m_device.m_device_file_system, m_variable->m_file);
    vostok::core::g_journal.m_initialized = 0;
  }
  survarium::game_options::~game_options(&this->m_game_options);
  if ( this->m_replay_match_reader.m_file )
    this->m_replay_match_reader.m_device.m_device_file_system->close(
      this->m_replay_match_reader.m_device.m_device_file_system,
      this->m_replay_match_reader.m_file);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_text_translator);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::~_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>(
    v30,
    (stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260> >,stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *)&this->m_swf_input_translator);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_items_dictionary);
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::~_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>(v31);
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::~_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>(v32);
  survarium::game_world::~game_world(&this->m_game_world);
  survarium::flash_factory::~flash_factory(v33, &this->m_flash_factory.m_gfx_loader);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_output_window);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_application_activation);
}
