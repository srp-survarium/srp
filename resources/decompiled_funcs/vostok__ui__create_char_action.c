vostok::ui::base_edit_action *__usercall vostok::ui::create_char_action@<eax>(
        vostok::ui::ui_text_edit *parent@<esi>,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action,
        char c,
        char c_shift,
        vostok::input::world *b_translate)
{
  vostok::ui::base_edit_action *result; // eax

  st.m_data.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)32;
  result = (vostok::ui::base_edit_action *)parent->m_allocator->call_malloc(parent->m_allocator, 28);
  if ( !result )
    return 0;
  result->m_key = key;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::base_edit_action::`vftable';
  result->m_parent = parent;
  result->m_key_action = kb_key_down;
  result->m_shift_state = st;
  result[1].__vftable = (vostok::ui::base_edit_action_vtbl *)b_translate;
  LOBYTE(result[1].m_parent) = c_shift;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::insert_char_action::`vftable';
  BYTE1(result[1].m_parent) = action;
  BYTE2(result[1].m_parent) = c;
  return result;
}
