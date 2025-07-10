void __userpurge survarium::lobby_menu::on_client_status_received(
        lobby::query_info_types type@<eax>,
        survarium::lobby_menu *a2@<ecx>,
        survarium::lobby_menu *this)
{
  __int16 v4; // bx
  survarium::game *v5; // ecx
  survarium::lobby_menu *v6; // ecx
  survarium::game *m_game; // eax
  survarium::lobby_menu *m_lobby_menu; // edi
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  survarium::lobby_client *v10; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  unsigned __int8 m_profiles_count; // al
  survarium::lobby_menu *v14; // ecx
  int v15; // esi
  survarium::lobby_client *v16; // edi
  survarium::lobby_client *v17; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v18; // ecx
  void (__cdecl *v19)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v20; // ecx
  void (__cdecl *v21)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  survarium::lobby_menu *v22; // ecx
  survarium::lobby_client *v23; // eax
  survarium::lobby_client *v24; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v25; // ecx
  void (__cdecl *v26)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v27; // ecx
  void (__cdecl *v28)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v29; // ecx
  void (__cdecl *v30)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v31; // ecx
  void (__cdecl *v32)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v33; // ecx
  void (__cdecl *v34)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v35; // ecx
  void (__cdecl *v36)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v37; // ecx
  void (__cdecl *v38)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v39; // ecx
  void (__cdecl *v40)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v41)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v42)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v43; // [esp+Ch] [ebp-1A4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+10h] [ebp-1A0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v45; // [esp+30h] [ebp-180h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v46; // [esp+50h] [ebp-160h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v47; // [esp+70h] [ebp-140h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v48; // [esp+90h] [ebp-120h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v49; // [esp+B0h] [ebp-100h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v50; // [esp+D0h] [ebp-E0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v51; // [esp+F0h] [ebp-C0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v52; // [esp+110h] [ebp-A0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+130h] [ebp-80h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v54; // [esp+150h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v55; // [esp+170h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v56; // [esp+190h] [ebp-20h] BYREF

  v4 = 0;
  switch ( type )
  {
    case q_client_state:
      switch ( survarium::lobby_menu::lobby_client(a2, (int)this)->m_status )
      {
        case surf_lobby_menu:
          if ( !this->m_is_active )
            survarium::game::switch_to_lobby(v5, (int)this->m_game);
          if ( !survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v5, (int)this)->m_profiles_count )
            survarium::lobby_menu::query_account_data(v6, (int)this);
          m_game = this->m_game;
          if ( m_game->m_game_world.m_is_loading )
            goto $LN59_8;
          m_lobby_menu = m_game->m_lobby_menu;
          if ( !m_lobby_menu->m_is_in_match_making )
            goto $LN59_8;
          survarium::base_game_scene::hide_movie(m_lobby_menu, &m_lobby_menu->m_match_making_ui, (int)this);
          m_lobby_menu->m_is_in_match_making = 0;
          survarium::lobby_menu::update_status(this, this);
          return;
        case in_match_making_order:
          goto $LN20_58;
        case in_match_making:
          survarium::lobby_menu::show_match_making((survarium::lobby_menu *)v5, this->m_game->m_lobby_menu, 1);
$LN20_58:
          survarium::lobby_menu::request_status_from_server((survarium::lobby_menu *)v5, (int)this, 0x3E8u);
          survarium::lobby_menu::update_status(this, this);
          return;
        case in_match:
          goto $LN59_8;
        default:
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
          {
            v9 = vostok::core::g_log_callback;
            log_callback.vtable = 0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                &log_callback.functor,
                &log_callback.functor,
                destroy_functor_tag);
            if ( v9 )
            {
              log_callback.functor.obj_ptr = v9;
              log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                           + 1);
            }
            else
            {
              log_callback.vtable = 0;
            }
            LOBYTE(v4) = 1;
            v10 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v5, (int)this);
            vostok::logging::append(
              &log_callback,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\lobby_menu.cpp",
              0xE4u,
              "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
              "game:",
              error,
              "Unknown client state %d",
              v10->m_status);
          }
          if ( (v4 & 1) != 0 )
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
              (int *)&log_callback);
$LN59_8:
          survarium::lobby_menu::update_status(this, this);
          break;
      }
      break;
    case q_enumerate_profiles:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v12 = vostok::core::g_log_callback;
        v47.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v47.functor,
            &v47.functor,
            destroy_functor_tag);
        if ( v12 )
        {
          v47.functor.obj_ptr = v12;
          v47.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v47.vtable = 0;
        }
        LOBYTE(v4) = 2;
        vostok::logging::append(
          &v47,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0xEBu,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] enumerate_profiles");
      }
      if ( (v4 & 2) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v11,
          (int *)&v47);
      m_profiles_count = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v11, (int)this)->m_profiles_count;
      if ( m_profiles_count )
      {
        v15 = 0;
        v43 = m_profiles_count;
        do
        {
          v16 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
          v17 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
          survarium::lobby_client::query_profile_contents(
            (survarium::lobby_client *)v16->m_profiles[v15].profile_id,
            v17,
            v16->m_profiles[v15].profile_id);
          ++v15;
          --v43;
        }
        while ( v43 );
      }
      survarium::lobby_menu::fill_profiles(v14, this);
      break;
    case q_profile_contents:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v19 = vostok::core::g_log_callback;
        v55.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v55.functor,
            &v55.functor,
            destroy_functor_tag);
        if ( v19 )
        {
          v55.functor.obj_ptr = v19;
          v55.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v55.vtable = 0;
        }
        LOBYTE(v4) = 4;
        vostok::logging::append(
          &v55,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0xF8u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] porfile_contents");
      }
      if ( (v4 & 4) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v18,
          (int *)&v55);
      break;
    case q_enumerate_inventory:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v21 = vostok::core::g_log_callback;
        v49.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v49.functor,
            &v49.functor,
            destroy_functor_tag);
        if ( v21 )
        {
          v49.functor.obj_ptr = v21;
          v49.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v49.vtable = 0;
        }
        LOBYTE(v4) = 8;
        vostok::logging::append(
          &v49,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0xFCu,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] enumerate_inventory");
      }
      if ( (v4 & 8) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v20,
          (int *)&v49);
      survarium::lobby_menu::fill_inventory_contents((survarium::lobby_menu *)v20, this);
      v23 = survarium::lobby_menu::lobby_client(v22, (int)this);
      survarium::lobby_client::query_client_status(v24, v23, q_enumerate_profiles);
      break;
    case q_profile_slots_restrictions:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v26 = vostok::core::g_log_callback;
        v45.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v45.functor,
            &v45.functor,
            destroy_functor_tag);
        if ( v26 )
        {
          v45.functor.obj_ptr = v26;
          v45.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v45.vtable = 0;
        }
        LOBYTE(v4) = 16;
        vostok::logging::append(
          &v45,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x102u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] profile_slots_restrictions");
      }
      if ( (v4 & 0x10) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v25,
          (int *)&v45);
      survarium::lobby_menu::on_slot_restrictions_arrived((survarium::lobby_menu *)v25, this);
      break;
    case q_items_compatibility:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v28 = vostok::core::g_log_callback;
        v51.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v51.functor,
            &v51.functor,
            destroy_functor_tag);
        if ( v28 )
        {
          v51.functor.obj_ptr = v28;
          v51.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v51.vtable = 0;
        }
        LOBYTE(v4) = 32;
        vostok::logging::append(
          &v51,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x107u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] items_compatibility");
      }
      if ( (v4 & 0x20) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v27,
          (int *)&v51);
      survarium::lobby_menu::on_items_compatibility_arrived((survarium::lobby_menu *)v27, this);
      break;
    case q_price_items:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v30 = vostok::core::g_log_callback;
        v46.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v46.functor,
            &v46.functor,
            destroy_functor_tag);
        if ( v30 )
        {
          v46.functor.obj_ptr = v30;
          v46.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v46.vtable = 0;
        }
        LOBYTE(v4) = 64;
        vostok::logging::append(
          &v46,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x10Cu,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] price_items");
      }
      if ( (v4 & 0x40) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v29,
          (int *)&v46);
      break;
    case q_account_money:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v32 = vostok::core::g_log_callback;
        v48.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v48.functor,
            &v48.functor,
            destroy_functor_tag);
        if ( v32 )
        {
          v48.functor.obj_ptr = v32;
          v48.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v48.vtable = 0;
        }
        LOBYTE(v4) = 0x80;
        vostok::logging::append(
          &v48,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x111u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] account_money");
      }
      if ( (v4 & 0x80u) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v31,
          (int *)&v48);
      survarium::lobby_menu::reset_account_money((survarium::lobby_menu *)v31, this);
      break;
    case q_player_skills:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v34 = vostok::core::g_log_callback;
        v50.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v50.functor,
            &v50.functor,
            destroy_functor_tag);
        if ( v34 )
        {
          v50.functor.obj_ptr = v34;
          v50.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v50.vtable = 0;
        }
        v4 = 256;
        vostok::logging::append(
          &v50,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x116u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] player_skills");
      }
      if ( (v4 & 0x100) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v33,
          (int *)&v50);
      survarium::lobby_menu::fill_character_data((survarium::lobby_menu *)v33, this);
      break;
    case q_player_skills_tree:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v36 = vostok::core::g_log_callback;
        v52.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v52.functor,
            &v52.functor,
            destroy_functor_tag);
        if ( v36 )
        {
          v52.functor.obj_ptr = v36;
          v52.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v52.vtable = 0;
        }
        v4 = 512;
        vostok::logging::append(
          &v52,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x11Bu,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] player_skills_tree");
      }
      if ( (v4 & 0x200) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v35,
          (int *)&v52);
      survarium::lobby_menu::fill_skills_tree((survarium::lobby_menu *)v35, (int)this);
      break;
    case q_service_prices:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v38 = vostok::core::g_log_callback;
        v54.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v54.functor,
            &v54.functor,
            destroy_functor_tag);
        if ( v38 )
        {
          v54.functor.obj_ptr = v38;
          v54.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v54.vtable = 0;
        }
        v4 = 1024;
        vostok::logging::append(
          &v54,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x120u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] service_prices");
      }
      if ( (v4 & 0x400) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v37,
          (int *)&v54);
      survarium::lobby_menu::fill_service_prices((survarium::lobby_menu *)v37, (int)this);
      break;
    case q_player_reputations:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v40 = vostok::core::g_log_callback;
        v56.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v56.functor,
            &v56.functor,
            destroy_functor_tag);
        if ( v40 )
        {
          v56.functor.obj_ptr = v40;
          v56.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v56.vtable = 0;
        }
        v4 = 2048;
        vostok::logging::append(
          &v56,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x125u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          info,
          "[R] player_reputations");
      }
      if ( (v4 & 0x800) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v39,
          (int *)&v56);
      survarium::lobby_menu::on_player_reputations_arrived((survarium::lobby_menu *)v39, this);
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v41 = vostok::core::g_log_callback;
        v44.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v44.functor,
            &v44.functor,
            destroy_functor_tag);
        if ( v41 )
        {
          v44.functor.obj_ptr = v41;
          v44.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v44.vtable = 0;
        }
        v4 = 4096;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x129u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum lobby::query_info_types)",
          "game:",
          error,
          "Unknown Client status received. type = %d",
          type);
      }
      if ( (v4 & 0x1000) != 0 )
      {
        if ( v44.vtable )
        {
          if ( ((int)v44.vtable & 1) == 0 )
          {
            v42 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v44.vtable & 0xFFFFFFFE);
            if ( v42 )
              v42(&v44.functor, &v44.functor, 2);
          }
        }
      }
      break;
  }
}
