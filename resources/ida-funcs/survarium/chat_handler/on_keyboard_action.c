char __thiscall survarium::chat_handler::on_keyboard_action(
        survarium::chat_handler *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  survarium::game_action_id binded_action; // eax
  survarium::chat_handler *v6; // ecx
  vostok::input::keyboard *v7; // eax
  vostok::input::keyboard *v8; // eax
  survarium::toggle_action_enum actions_mask_type; // [esp+Ch] [ebp-4h] BYREF

  binded_action = survarium::key_binder::get_binded_action(this->m_game->m_key_binder, key, &actions_mask_type, 8);
  if ( action != kb_key_down )
    goto LABEL_13;
  if ( binded_action == kSEND_MESSAGE || key == key_numpadenter )
  {
    Scaleform::GFx::Movie::Invoke(
      this->m_current_chat_ui.m_object->movie->m_movie,
      "root.finish_typing_message",
      0,
      0,
      0);
    if ( !this->m_game_ui_mode )
      goto LABEL_13;
LABEL_12:
    survarium::chat_handler::focus(v6, (int)this, 0);
    goto LABEL_13;
  }
  if ( key == key_escape )
    goto LABEL_12;
  if ( binded_action == kSELECT_SEND_TO )
  {
    v7 = input_world->get_keyboard(input_world);
    if ( v7->is_key_down(v7, key_lshift) )
    {
      Scaleform::GFx::Movie::Invoke(this->m_current_chat_ui.m_object->movie->m_movie, "root.previous_tab", 0, 0, 0);
    }
    else
    {
      v8 = input_world->get_keyboard(input_world);
      if ( !v8->is_key_down(v8, key_lmenu) )
        Scaleform::GFx::Movie::Invoke(this->m_current_chat_ui.m_object->movie->m_movie, "root.next_tab", 0, 0, 0);
    }
    return 1;
  }
LABEL_13:
  if ( this->m_current_chat_ui.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && vostok::core::journal_usage() != replay_journal )
  {
    survarium::swf_input_translator::process_keyboard(
      (survarium::swf_input_translator *)input_world,
      &this->m_game->m_swf_input_translator,
      key,
      action,
      this->m_current_chat_ui.m_object->movie,
      this->m_game->m_current_time_in_ms);
  }
  return 1;
}
