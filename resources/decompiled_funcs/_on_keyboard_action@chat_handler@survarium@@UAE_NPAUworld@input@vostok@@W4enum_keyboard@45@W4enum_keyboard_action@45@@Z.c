char __thiscall survarium::chat_handler::on_keyboard_action(
        survarium::chat_handler *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  survarium::game_action_id binded_action; // eax
  survarium::chat_handler *v6; // ecx
  survarium::flash_movie_resource *m_object; // eax
  survarium::toggle_action_enum action_type; // [esp+Ch] [ebp-4h] BYREF

  binded_action = survarium::key_binder::get_binded_action(this->m_game->m_key_binder, key, 8, &action_type);
  if ( action != kb_key_down )
    goto LABEL_9;
  if ( binded_action == kSEND_MESSAGE || key == key_numpadenter )
  {
    Scaleform::GFx::Movie::Invoke(this->m_chat_ui.m_object->movie->m_movie, "root.finish_typing_message", 0, 0, 0);
    goto LABEL_8;
  }
  if ( key == key_escape )
  {
LABEL_8:
    survarium::chat_handler::focus(v6, (int)this, 0);
    goto LABEL_9;
  }
  if ( binded_action == kSELECT_SEND_TO )
  {
    Scaleform::GFx::Movie::Invoke(this->m_chat_ui.m_object->movie->m_movie, "root.tab_channel", 0, 0, 0);
    return 1;
  }
LABEL_9:
  m_object = this->m_chat_ui.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      survarium::swf_input_translator::process_keyboard(
        &this->m_game->m_swf_input_translator,
        input_world,
        key,
        action,
        m_object->movie,
        this->m_game->m_current_time_in_ms);
  }
  return 1;
}
