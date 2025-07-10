vostok::ui::base_edit_action *__usercall vostok::ui::create_shift_action@<eax>(
        vostok::ui::ui_text_edit *parent@<esi>,
        vostok::input::enum_keyboard key,
        vostok::ui::base_edit_action_vtbl *state)
{
  vostok::ui::base_edit_action *result; // eax

  result = (vostok::ui::base_edit_action *)parent->m_allocator->call_malloc(parent->m_allocator, 24);
  if ( !result )
    return 0;
  result->m_parent = parent;
  result->m_key = key;
  result->m_key_action = kb_key_unknown;
  result->m_shift_state.m_data.dummy = -86;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::shift_state_action::`vftable';
  result[1].__vftable = state;
  return result;
}
