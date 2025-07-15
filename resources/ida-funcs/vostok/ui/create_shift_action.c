vostok::ui::base_edit_action *__usercall vostok::ui::create_shift_action@<eax>(
        vostok::ui::ui_text_edit *parent@<edi>,
        vostok::input::enum_keyboard key,
        vostok::ui::base_edit_action_vtbl *state)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v4; // eax
  vostok::ui::base_edit_action *result; // eax

  m_allocator = parent->m_allocator;
  v4 = type_info::raw_name(&vostok::ui::shift_state_action `RTTI Type Descriptor');
  result = (vostok::ui::base_edit_action *)m_allocator->call_malloc(
                                             m_allocator,
                                             24u,
                                             v4,
                                             "vostok::ui::create_shift_action",
                                             ".\\ui_text_edit_initialize.cpp",
                                             59u);
  if ( !result )
    return 0;
  result->m_key_action = kb_key_unknown;
  result->m_key = key;
  result->m_parent = parent;
  result->m_shift_state.m_data.dummy = -86;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::shift_state_action::`vftable';
  result[1].__vftable = state;
  return result;
}
