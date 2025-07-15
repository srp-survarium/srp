void __thiscall survarium::game_options::callback(
        survarium::game_options *this,
        survarium::flash_movie *pmovieView,
        const char *methodName,
        const survarium::flash_value *args,
        unsigned int argCount)
{
  const char *v6; // esi
  char *v7; // ecx
  const char *v8; // eax
  bool v9; // cf
  unsigned __int8 v10; // dl
  int v11; // eax
  char *v12; // ecx
  const char *v13; // eax
  bool v14; // cf
  unsigned __int8 v15; // dl
  int v16; // eax
  int v17; // esi
  survarium::options_tab *v18; // ecx
  const char *v19; // eax
  bool v20; // cf
  unsigned __int8 v21; // dl
  int v22; // eax
  int v23; // edi
  survarium::game_options *v24; // ecx
  survarium::game_options *v25; // ecx
  survarium::game_options *v26; // ecx
  int v27; // ecx
  survarium::base_game_scene *impl; // edx
  survarium::game_action_id *i; // esi

  if ( !strcmp(methodName, "menu_button") )
  {
    if ( (*(_DWORD *)&args->body[4] & 0x40) != 0 )
      v6 = **(const char ***)&args->body[8];
    else
      v6 = *(const char **)&args->body[8];
    v7 = "back";
    v8 = v6;
    while ( 1 )
    {
      v9 = (unsigned int)*v8 < (unsigned __int8)*v7;
      if ( *v8 != *v7 )
        break;
      if ( !*v8 )
        goto LABEL_10;
      v10 = v8[1];
      v9 = v10 < (unsigned __int8)v7[1];
      if ( v10 != v7[1] )
        break;
      v8 += 2;
      v7 += 2;
      if ( !v10 )
      {
LABEL_10:
        v11 = 0;
        goto LABEL_12;
      }
    }
    v11 = -v9 - (v9 - 1);
LABEL_12:
    if ( v11 )
    {
      if ( !strcmp(v6, "exit_to_os") )
      {
        survarium::game::exit((survarium::game *)this->m_options[3], "quit");
      }
      else if ( vostok::strings::equal(v6, "settings") )
      {
        survarium::game_options::show_options((survarium::game_options *)((char *)this - 4));
      }
      else if ( vostok::strings::equal(v6, "leave_match") )
      {
        this->m_options[3][47].m_game->__vftable[1].on_fullscreen_alttab(this->m_options[3][47].m_game, 1);
      }
    }
    else
    {
      survarium::game::deactivate_main_menu((survarium::game *)v7, (int)this->m_options[3]);
    }
  }
  else
  {
    v12 = "accept_changes";
    v13 = methodName;
    while ( 1 )
    {
      v14 = (unsigned int)*v13 < (unsigned __int8)*v12;
      if ( *v13 != *v12 )
        break;
      if ( !*v13 )
        goto LABEL_25;
      v15 = v13[1];
      v14 = v15 < (unsigned __int8)v12[1];
      if ( v15 != v12[1] )
        break;
      v13 += 2;
      v12 += 2;
      if ( !v15 )
      {
LABEL_25:
        v16 = 0;
        goto LABEL_27;
      }
    }
    v16 = -v14 - (v14 - 1);
LABEL_27:
    if ( v16 )
    {
      v18 = (survarium::options_tab *)&stru_96AC08;
      v19 = methodName;
      while ( 1 )
      {
        v20 = (unsigned int)*v19 < LOBYTE(v18->m_options);
        if ( *v19 != LOBYTE(v18->m_options) )
          break;
        if ( !*v19 )
          goto LABEL_36;
        v21 = v19[1];
        v20 = v21 < BYTE1(v18->m_options);
        if ( v21 != BYTE1(v18->m_options) )
          break;
        v19 += 2;
        v18 = (survarium::options_tab *)((char *)v18 + 2);
        if ( !v21 )
        {
LABEL_36:
          v22 = 0;
          goto LABEL_38;
        }
      }
      v22 = -v20 - (v20 - 1);
LABEL_38:
      if ( v22 )
      {
        if ( !vostok::strings::equal(methodName, (const char *)&stru_96AC08.m_movie) )
        {
          if ( vostok::strings::equal(methodName, "button_default_video") )
          {
            survarium::game_options::apply_default_graphic(v25, (survarium::game_options *)((char *)this - 4));
          }
          else if ( vostok::strings::equal(methodName, "button_default_controls") )
          {
            survarium::game_options::reset_bindings_to_defaults(v26, (survarium::game_options *)((char *)this - 4));
          }
          else if ( vostok::strings::equal(methodName, "start_bind_key") )
          {
            v27 = *(_DWORD *)&args->body[8];
            impl = (survarium::base_game_scene *)this->impl;
            *(_DWORD *)&this->m_is_active = v27;
            survarium::base_game_scene::hide_movie(impl, &this->m_options_ui, v27);
          }
          else if ( vostok::strings::equal(methodName, "reassign_ok_clicked") )
          {
            survarium::game_options::assign_binding(
              (const char *)this->m_waiting_for_bind_action,
              (survarium::game_options *)((char *)this - 4),
              (survarium::game_action_id)this->m_conflicted_key_name);
            for ( i = (survarium::game_action_id *)this->m_conflicted_action_to_bind;
                  i != this->m_conflicted_action_ids._M_impl._M_start;
                  ++i )
            {
              survarium::game_options::assign_binding(
                (const char *)&buf,
                (survarium::game_options *)((char *)this - 4),
                *i);
            }
          }
        }
      }
      else
      {
        v23 = *(_DWORD *)&args->body[8];
        survarium::options_tab::revert(v18, *((_DWORD *)&this->m_cursor_ui.m_object + v23));
        if ( v23 == 1 )
          survarium::game_options::reset_bindings(v24, (survarium::game_options *)((char *)this - 4), 1);
      }
    }
    else
    {
      v17 = *(_DWORD *)&args->body[8];
      if ( v17 == 1 )
        survarium::game_options::apply_key_bindings((survarium::game_options *)v12);
      survarium::options_tab::apply(
        (survarium::options_tab *)&this->m_parent_scene,
        *((_DWORD *)&this->m_cursor_ui.m_object + v17),
        (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&this->m_parent_scene);
    }
  }
}
