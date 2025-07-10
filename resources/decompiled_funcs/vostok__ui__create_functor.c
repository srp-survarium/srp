vostok::ui::base_edit_action *__usercall vostok::ui::create_functor@<eax>(
        const fastdelegate::FastDelegate0<void> *functor@<edi>,
        vostok::ui::ui_text_edit *parent@<esi>,
        vostok::input::enum_keyboard key,
        const vostok::ui::shift_state *action)
{
  vostok::ui::base_edit_action *result; // eax

  result = (vostok::ui::base_edit_action *)parent->m_allocator->call_malloc(parent->m_allocator, 28);
  if ( !result )
    return 0;
  result->m_key = key;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::base_edit_action::`vftable';
  result->m_parent = parent;
  result->m_key_action = kb_key_down;
  result->m_shift_state = (vostok::ui::shift_state)action->m_data.d;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::functor_edit_action::`vftable';
  result[1].__vftable = 0;
  result[1].m_parent = 0;
  *(fastdelegate::FastDelegate0<void> *)&result[1].__vftable = *functor;
  return result;
}
