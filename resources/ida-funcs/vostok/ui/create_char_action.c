vostok::ui::base_edit_action *__usercall vostok::ui::create_char_action@<eax>(
        vostok::ui::ui_text_edit *parent@<edi>,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action,
        char c,
        char c_shift,
        vostok::ui::base_edit_action_vtbl *b_translate)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v7; // eax
  vostok::ui::base_edit_action *result; // eax

  st.m_data.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)32;
  m_allocator = parent->m_allocator;
  v7 = type_info::raw_name(&vostok::ui::insert_char_action `RTTI Type Descriptor');
  result = (vostok::ui::base_edit_action *)m_allocator->call_malloc(
                                             m_allocator,
                                             28u,
                                             v7,
                                             "vostok::ui::create_char_action",
                                             ".\\ui_text_edit_initialize.cpp",
                                             52u);
  if ( !result )
    return 0;
  result->m_key = key;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::base_edit_action::`vftable';
  result->m_parent = parent;
  result->m_key_action = kb_key_down;
  result->m_shift_state = st;
  result[1].__vftable = b_translate;
  LOBYTE(result[1].m_parent) = c_shift;
  BYTE1(result[1].m_parent) = action;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::insert_char_action::`vftable';
  BYTE2(result[1].m_parent) = c;
  return result;
}
