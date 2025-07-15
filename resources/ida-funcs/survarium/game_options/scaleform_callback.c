void __thiscall survarium::game_options::scaleform_callback(
        survarium::game_options *this,
        survarium::flash_movie *pmovieView,
        char *methodName,
        const survarium::flash_value *args,
        unsigned int argCount)
{
  survarium::flash_value *v6; // ecx
  const char *String; // edi
  survarium::game *v8; // ecx
  survarium::game_options *v9; // ecx
  survarium::game *v10; // ecx
  survarium::game_options *v11; // ecx
  int v12; // edi
  survarium::game_options *v13; // ecx
  int v14; // ebx
  int v15; // edi
  int v16; // ecx
  survarium::game_options *v17; // ecx
  survarium::key_binder *v18; // ecx
  survarium::game_options *v19; // ecx
  survarium::game_options *v20; // ecx
  vostok::particle::particle_system_instance_impl *v21; // ecx
  unsigned int *i; // edi
  survarium::game *v23; // ecx
  vostok::render::scene_renderer *v24; // ecx
  survarium::game_action_id *M_data; // [esp-8h] [ebp-10h]
  unsigned __int8 j; // [esp+1Bh] [ebp+13h]

  if ( vostok::strings::compare(methodName, "menu_button") )
  {
    if ( vostok::strings::compare(methodName, "accept_changes") )
    {
      if ( vostok::strings::compare(methodName, "cancel_changes") )
      {
        if ( vostok::strings::compare(methodName, "button_optimal_video") )
        {
          if ( vostok::strings::compare(methodName, "button_default_video") )
          {
            if ( vostok::strings::compare(methodName, "button_default_controls") )
            {
              if ( vostok::strings::compare(methodName, "start_bind_key") )
              {
                if ( vostok::strings::compare(methodName, "reassign_ok_clicked") )
                {
                  if ( vostok::strings::compare(methodName, "reassign_cancel_clicked") )
                  {
                    if ( vostok::strings::compare(methodName, "sound_play") )
                    {
                      if ( !vostok::strings::compare(methodName, "options_tab_changed")
                        && *(_DWORD *)&args->body[8] == 2 )
                      {
                        vostok::render::scene_renderer::begin_render_options_changing(
                          v24,
                          *(volatile int **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(this->m_parent_scene[57].m_block_btn_time + 160)
                                                       + 172)));
                      }
                    }
                    else
                    {
                      survarium::game::play_ui_sound(v23, (int)this->m_parent_scene, args->body[8]);
                    }
                  }
                }
                else
                {
                  survarium::game_options::assign_binding(
                    this->m_waiting_for_bind_action,
                    (survarium::game_options *)((char *)this - 4),
                    (char *)this->m_game);
                  for ( i = (unsigned int *)this->m_options[3];
                        i != (unsigned int *)this->m_conflicted_action_ids._M_impl._M_start;
                        ++i )
                  {
                    survarium::game_options::assign_binding(
                      *i,
                      (survarium::game_options *)((char *)this - 4),
                      (char *)uri);
                  }
                }
              }
              else
              {
                M_data = this->m_conflicted_action_ids._M_impl._M_end_of_storage._M_data;
                this->m_conflicted_key_name = *(const char **)&args->body[8];
                survarium::base_game_scene::hide_movie(
                  (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_options_ui,
                  v21,
                  (survarium::base_game_scene *)M_data);
              }
            }
            else
            {
              survarium::key_binder::set_default_controls(v18, (survarium::key_binder *)this->m_parent_scene->m_mouse_y);
              survarium::game_options::reset_bindings(v19, (int)&this[-1].m_is_active, 0);
              survarium::game_options::apply_key_bindings(v20);
            }
          }
          else
          {
            survarium::game_options::apply_default_graphic(v17, (int)&this[-1].m_is_active);
          }
        }
      }
      else
      {
        v14 = *(_DWORD *)&args->body[8];
        v15 = *((_DWORD *)&this->m_cursor_ui.m_object + v14);
        for ( j = 0; j < *(_BYTE *)(v15 + 4); ++j )
        {
          v16 = *(_DWORD *)(*(_DWORD *)v15 + 4 * j);
          (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 20))(v16);
        }
        if ( v14 == 1 )
          survarium::game_options::reset_bindings(v13, (int)&this[-1].m_is_active, 1);
      }
    }
    else
    {
      v12 = *(_DWORD *)&args->body[8];
      if ( v12 == 1 )
        survarium::game_options::apply_key_bindings(v11);
      survarium::options_tab::apply(
        (survarium::options_tab *)v11,
        *((vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **)&this->m_cursor_ui.m_object
        + v12),
        (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&this->impl);
    }
  }
  else
  {
    String = survarium::flash_value::GetString(v6, (int)args);
    if ( vostok::strings::compare(String, "back") )
    {
      if ( vostok::strings::compare(String, "exit_to_os") )
      {
        if ( vostok::strings::compare(String, "settings") )
        {
          if ( vostok::strings::compare(String, "leave_match") )
          {
            if ( !vostok::strings::compare(String, "logoff") )
            {
              this->m_parent_scene[57].m_drawable_objects.m_last->__vftable[4].draw(this->m_parent_scene[57].m_drawable_objects.m_last);
              survarium::game::switch_to_login(
                v10,
                (survarium::game *)this->m_parent_scene,
                login_menu_status_disconnected);
            }
          }
          else
          {
            ((void (__thiscall *)(survarium::drawable_object *, int))this->m_parent_scene[57].m_drawable_objects.m_last->__vftable[21].draw)(
              this->m_parent_scene[57].m_drawable_objects.m_last,
              2);
          }
        }
        else
        {
          survarium::game_options::show_options(v9, (int)&this[-1].m_is_active, 1);
        }
      }
      else
      {
        survarium::game::exit((survarium::game *)this->m_parent_scene, "quit");
      }
    }
    else
    {
      survarium::game::deactivate_main_menu(v8, (int)this->m_parent_scene);
    }
  }
}
