char __thiscall vostok::console_impl::on_keyboard_action(
        vostok::console_impl *this,
        vostok::console_impl *input_world,
        vostok::input::world *key,
        vostok::input::enum_keyboard action,
        vostok::input::enum_keyboard_action actiona)
{
  vostok::input::enum_keyboard_action v5; // esi
  int v7; // eax
  const char *v8; // eax
  char *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  vostok::input::world_vtbl *m_tips_mode; // eax
  unsigned int v17; // esi
  char *v18; // eax
  char *v19; // edi
  vostok::console_commands::console_command *v20; // eax
  char *next_tip; // esi
  int v22; // eax
  unsigned int v23; // kr04_4
  vostok::console_impl *v24; // ecx
  vostok::input::world_vtbl *m_ui_tips_view; // ecx
  int *v26; // esi
  int v27; // edi
  int v28; // eax
  int v29; // eax
  vostok::ui::window *v30; // eax
  vostok::input::handler *v31; // eax
  vostok::input::world_vtbl *v32; // [esp+Ch] [ebp-24h]
  const stlp_std::forward_iterator_tag *v33; // [esp+10h] [ebp-20h]
  int tip_index; // [esp+1Ch] [ebp-14h] BYREF
  vostok::math::float2 line_size; // [esp+20h] [ebp-10h] BYREF
  _DWORD v36[2]; // [esp+28h] [ebp-8h] BYREF

  v5 = action;
  if ( actiona != kb_key_down )
  {
LABEL_40:
    v31 = input_world->m_ui_dialog->input_handler(input_world->m_ui_dialog);
    v31->on_keyboard_action(v31, key, action, actiona);
    return 1;
  }
  if ( input_world->m_self_deactivate && (action == key_grave || action == key_escape) )
  {
    input_world->on_deactivate(input_world);
    return 1;
  }
  v7 = (int)input_world->m_text_edit->text(input_world->m_text_edit);
  v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 12))(v7);
  v9 = (char *)v8;
  tip_index = (int)v8;
  if ( action != key_up && action != key_down && action != key_tab )
  {
    input_world->m_tips_mode = tm_none;
    if ( action == key_capital )
    {
      v10 = (int)input_world->m_ui_view->w(input_world->m_ui_view);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 56))(v10) )
      {
        v11 = (int)input_world->m_ui_view->w(input_world->m_ui_view);
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v11 + 52))(v11, 0);
        v12 = (int)input_world->m_text_edit->w(input_world->m_text_edit);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 52))(v12, 1);
        return 1;
      }
      v13 = (int)input_world->m_text_edit->w(input_world->m_text_edit);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 56))(v13) )
      {
        v14 = (int)input_world->m_text_edit->w(input_world->m_text_edit);
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v14 + 52))(v14, 0);
        v15 = (int)input_world->m_ui_view->w(input_world->m_ui_view);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v15 + 52))(v15, 1);
        return 1;
      }
      return 1;
    }
    goto LABEL_40;
  }
  if ( input_world->m_tips_mode == tm_none
    && input_world->m_executed_history._M_impl._M_start != input_world->m_executed_history._M_impl._M_finish
    && !strlen(v8) )
  {
    input_world->m_tips_mode = tm_history;
  }
  m_tips_mode = (vostok::input::world_vtbl *)input_world->m_tips_mode;
  if ( m_tips_mode == (vostok::input::world_vtbl *)1 )
  {
    stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_assign_aux<char const * *>(
      &input_world->m_tips._M_impl,
      (const char **)input_world->m_executed_history._M_impl._M_start,
      (unsigned int)input_world->m_executed_history._M_impl._M_finish,
      v33);
  }
  else
  {
    if ( m_tips_mode )
      goto LABEL_34;
    v17 = strlen(v9);
    if ( v9[v17 - 1] == 32 )
    {
      v18 = vostok::strings::duplicate<vostok::memory::base_allocator>(v9);
      v19 = v18;
      if ( v17 )
      {
        while ( v18[--v17] == 32 )
        {
          v18[v17] = 0;
          if ( !v17 )
            goto LABEL_30;
        }
        if ( v17 )
        {
          v20 = vostok::console_commands::find(v18);
          if ( v20 )
          {
            v20->fill_command_args_list(v20, &input_world->m_tips);
            if ( input_world->m_tips._M_impl._M_start != input_world->m_tips._M_impl._M_finish )
              input_world->m_tips_mode = tm_arg_list;
          }
        }
      }
LABEL_30:
      if ( v19 )
        input_world->m_allocator->call_free(input_world->m_allocator, v19);
      v9 = (char *)tip_index;
    }
  }
  v5 = action;
LABEL_34:
  if ( input_world->m_tips_mode == tm_none )
    input_world->m_tips_mode = tm_commands_list;
  v32 = (vostok::input::world_vtbl *)input_world->m_tips_mode;
  tip_index = 255;
  next_tip = (char *)vostok::make_next_tip(
                       v9,
                       &input_world->m_tips,
                       (char *)&tip_index,
                       v5 != 200,
                       (vostok::enum_tips_mode)v32);
  if ( next_tip != input_world->m_current_command_info )
  {
    vostok::apply_new_tip(input_world->m_text_edit, input_world->m_tips_mode, next_tip);
    v22 = (int)input_world->m_text_edit->text(input_world->m_text_edit);
    v23 = strlen((const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v22 + 12))(v22));
    input_world->m_text_edit->set_caret_position(input_world->m_text_edit, v23, 0);
    vostok::console_impl::fill_tips_view(v24);
    if ( next_tip )
    {
      if ( (_WORD)tip_index != 255 )
      {
        m_ui_tips_view = (vostok::input::world_vtbl *)input_world->m_ui_tips_view;
        line_size = (vostok::math::float2)0x41A0000042C80000LL;
        v26 = (int *)(*((int (__thiscall **)(vostok::input::world_vtbl *))m_ui_tips_view->tick + 2))(m_ui_tips_view);
        v27 = *v26;
        v28 = ((int (__thiscall *)(vostok::ui::image *, _DWORD))input_world->m_ui_tips_view_hl->w)(
                input_world->m_ui_tips_view_hl,
                0);
        (*(void (__thiscall **)(int *, int))(v27 + 64))(v26, v28);
        v29 = (int)input_world->m_ui_tips_view_hl->w(input_world->m_ui_tips_view_hl);
        (*(void (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)v29 + 8))(v29, &line_size);
        v30 = input_world->m_ui_tips_view_hl->w(input_world->m_ui_tips_view_hl);
        v36[0] = 0;
        *(float *)&v36[1] = (float)(unsigned __int16)tip_index * line_size.y;
        v30->set_position(v30, (const vostok::math::float2 *)v36);
        return 1;
      }
    }
  }
  return 1;
}
