char __thiscall survarium::lobby_menu::on_keyboard_action(
        survarium::lobby_menu *this,
        survarium::swf_input_translator *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  int v6; // eax
  char v7; // bl
  int v8; // eax
  float m_level_loading_progress; // eax
  survarium::game_action_id binded_action; // eax
  survarium::game_options *v11; // ecx
  survarium::game *v12; // ecx
  bool BValue; // [esp+13h] [ebp-35h]
  survarium::toggle_action_enum actions_mask_type; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::Value v15; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::Value presult; // [esp+30h] [ebp-18h] BYREF

  if ( !survarium::lobby_menu::lobby_client(
          this,
          (int)this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[8].m_store)->m_net_client_connected
    || this->m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[2].m_store[2] )
  {
    return 1;
  }
  v6 = *(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4];
  presult.pObjectInterface = 0;
  presult.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v6 + 264) + 4),
    "root.has_active_window",
    &presult,
    0,
    0);
  BValue = presult.mValue.BValue;
  if ( key == key_escape
    && this->m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[2].m_store[3]
    && presult.mValue.BValue )
  {
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                            + 264)
                                + 4),
      "root.close_active_window",
      0,
      0,
      0);
    Scaleform::GFx::Value::~Value(&presult);
    return 0;
  }
  if ( action == kb_key_down )
  {
    v8 = *(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4];
    v15.pObjectInterface = 0;
    v15.Type = VT_Undefined;
    Scaleform::GFx::Movie::Invoke(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v8 + 264) + 4), "root.is_typing", &v15, 0, 0);
    m_level_loading_progress = this[-1].m_level_loading_progress;
    if ( v15.mValue.BValue )
    {
      survarium::swf_input_translator::process_keyboard(
        input_world,
        (survarium::swf_input_translator *)(LODWORD(m_level_loading_progress) + 13916),
        key,
        kb_key_down,
        *(survarium::flash_movie **)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                   + 264),
        *(_DWORD *)(LODWORD(m_level_loading_progress) + 13968));
LABEL_14:
      Scaleform::GFx::Value::~Value(&v15);
      v7 = 1;
      goto LABEL_11;
    }
    binded_action = survarium::key_binder::get_binded_action(
                      *(survarium::key_binder **)(LODWORD(m_level_loading_progress) + 144),
                      key,
                      &actions_mask_type,
                      2);
    switch ( binded_action )
    {
      case kCHARACTER:
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                                + 264)
                                    + 4),
          "root.show_character_toggle",
          0,
          0,
          0);
        break;
      case kSHOP:
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                                + 264)
                                    + 4),
          "root.show_shop_toggle",
          0,
          0,
          0);
        break;
      case kINVENTORY:
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                                + 264)
                                    + 4),
          "root.show_inventory_toggle",
          0,
          0,
          0);
        break;
      case kFRIENDS:
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                                + 264)
                                    + 4),
          "root.show_friends_toggle",
          0,
          0,
          0);
        break;
      case kOPTIONS:
        survarium::game_options::show_options(v11, LODWORD(this[-1].m_level_loading_progress) + 15072, 1);
        survarium::game::activate_main_menu(v12, LODWORD(this[-1].m_level_loading_progress));
        break;
    }
    if ( key == key_f5 )
      survarium::lobby_menu::request_status_from_server(
        (survarium::lobby_menu *)v11,
        (survarium::lobby_menu *)((char *)this - 240),
        0);
    if ( key == key_f6 )
    {
      survarium::lobby_menu::play_button_clicked(
        (survarium::lobby_menu *)v11,
        (int)this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[8].m_store);
    }
    else if ( key == key_escape )
    {
      if ( BValue )
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                                + 264)
                                    + 4),
          "root.close_active_window",
          0,
          0,
          0);
      else
        survarium::game::activate_main_menu((survarium::game *)v11, LODWORD(this[-1].m_level_loading_progress));
      goto LABEL_14;
    }
    survarium::swf_input_translator::process_keyboard(
      input_world,
      (survarium::swf_input_translator *)(LODWORD(this[-1].m_level_loading_progress) + 13916),
      key,
      kb_key_down,
      *(survarium::flash_movie **)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                                 + 264),
      *(_DWORD *)(LODWORD(this[-1].m_level_loading_progress) + 13968));
    Scaleform::GFx::Value::~Value(&v15);
    goto LABEL_10;
  }
  survarium::swf_input_translator::process_keyboard(
    input_world,
    (survarium::swf_input_translator *)(LODWORD(this[-1].m_level_loading_progress) + 13916),
    key,
    action,
    *(survarium::flash_movie **)(*(_DWORD *)&this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4]
                               + 264),
    *(_DWORD *)(LODWORD(this[-1].m_level_loading_progress) + 13968));
LABEL_10:
  v7 = 0;
LABEL_11:
  Scaleform::GFx::Value::~Value(&presult);
  return v7;
}
