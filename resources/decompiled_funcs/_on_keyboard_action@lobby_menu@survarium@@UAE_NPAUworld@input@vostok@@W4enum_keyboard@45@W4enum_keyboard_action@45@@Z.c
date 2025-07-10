char __thiscall survarium::lobby_menu::on_keyboard_action(
        survarium::lobby_menu *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  unsigned int last_match_r2_delta; // eax
  survarium::game_action_id binded_action; // eax
  survarium::lobby_menu *v8; // ecx
  survarium::lobby_client *v9; // eax
  survarium::lobby_client *v10; // ecx
  Scaleform::GFx::Value *v11; // ecx
  survarium::game *v12; // ecx
  const char *v13; // [esp-10h] [ebp-50h]
  survarium::toggle_action_enum action_type; // [esp+Ch] [ebp-34h] BYREF
  survarium::flash_value is_typing_text; // [esp+10h] [ebp-30h] BYREF
  survarium::flash_value has_active_window; // [esp+28h] [ebp-18h] BYREF

  if ( !BYTE2(this->m_inverted_view_matrix.lines[2].elements[1])
    || BYTE1(this->m_inverted_view_matrix.lines[2].elements[1]) )
  {
    return 1;
  }
  if ( action != kb_key_down )
  {
    survarium::swf_input_translator::process_keyboard(
      key,
      (survarium::swf_input_translator *)input_world,
      (survarium::swf_input_translator *)(this[-1].m_match_stats.last_match_r2_delta + 960),
      input_world,
      action,
      *(survarium::flash_movie **)(LODWORD(this->m_inverted_view_matrix.i.y) + 264),
      *(_DWORD *)(this[-1].m_match_stats.last_match_r2_delta + 1012));
    return 0;
  }
  *(_DWORD *)is_typing_text.body = 0;
  *(_DWORD *)&is_typing_text.body[4] = 0;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264) + 4),
    "root.is_typing",
    (Scaleform::GFx::Value *)&is_typing_text,
    0,
    0);
  last_match_r2_delta = this[-1].m_match_stats.last_match_r2_delta;
  if ( is_typing_text.body[8] )
  {
    survarium::swf_input_translator::process_keyboard(
      key,
      (survarium::swf_input_translator *)input_world,
      (survarium::swf_input_translator *)(last_match_r2_delta + 960),
      input_world,
      kb_key_down,
      *(survarium::flash_movie **)(LODWORD(this->m_inverted_view_matrix.i.y) + 264),
      *(_DWORD *)(last_match_r2_delta + 1012));
    survarium::flash_value::~flash_value(&is_typing_text);
    return 1;
  }
  binded_action = survarium::key_binder::get_binded_action(
                    *(survarium::key_binder **)(last_match_r2_delta + 120),
                    key,
                    2,
                    &action_type);
  switch ( binded_action )
  {
    case kCHARACTER:
      v13 = "root.show_character_toggle";
LABEL_16:
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264) + 4),
        v13,
        0,
        0,
        0);
      break;
    case kSHOP:
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264) + 4),
        "root.show_shop_toggle",
        0,
        0,
        0);
      break;
    case kINVENTORY:
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264) + 4),
        "root.show_inventory_toggle",
        0,
        0,
        0);
      break;
    case kFRIENDS:
      v13 = "root.show_friends_toggle";
      goto LABEL_16;
  }
  if ( key == key_f5 )
  {
    v9 = survarium::lobby_menu::lobby_client(v8, (int)&this[-1].m_projection_matrix.j.w);
    survarium::lobby_client::query_client_status(v10, v9, q_client_state);
LABEL_19:
    survarium::swf_input_translator::process_keyboard(
      key,
      (survarium::swf_input_translator *)input_world,
      (survarium::swf_input_translator *)(this[-1].m_match_stats.last_match_r2_delta + 960),
      input_world,
      kb_key_down,
      *(survarium::flash_movie **)(LODWORD(this->m_inverted_view_matrix.i.y) + 264),
      *(_DWORD *)(this[-1].m_match_stats.last_match_r2_delta + 1012));
    survarium::flash_value::~flash_value(&is_typing_text);
    return 0;
  }
  if ( key != key_escape )
    goto LABEL_19;
  survarium::flash_value::flash_value(&has_active_window);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264) + 4),
    "root.has_active_window",
    v11,
    0,
    0);
  if ( has_active_window.body[8] )
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264) + 4),
      "root.close_active_window",
      0,
      0,
      0);
  else
    survarium::game::activate_main_menu(v12, this[-1].m_match_stats.last_match_r2_delta);
  survarium::flash_value::~flash_value(&has_active_window);
  survarium::flash_value::~flash_value(&is_typing_text);
  return 1;
}
