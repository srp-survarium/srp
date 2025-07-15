vostok::ui::base_edit_action *__usercall vostok::ui::create_functor@<eax>(
        vostok::ui::ui_text_edit *parent@<edi>,
        const fastdelegate::FastDelegate0<void> *functor,
        vostok::input::enum_keyboard key,
        vostok::ui::shift_state::data_storage *action)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v5; // eax
  vostok::ui::base_edit_action *result; // eax

  m_allocator = parent->m_allocator;
  v5 = type_info::raw_name(&vostok::ui::functor_edit_action `RTTI Type Descriptor');
  result = (vostok::ui::base_edit_action *)m_allocator->call_malloc(
                                             m_allocator,
                                             28u,
                                             v5,
                                             "vostok::ui::create_functor",
                                             ".\\ui_text_edit_initialize.cpp",
                                             37u);
  if ( !result )
    return 0;
  result->m_key = key;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::base_edit_action::`vftable';
  result->m_parent = parent;
  result->m_key_action = kb_key_down;
  result->m_shift_state.m_data = (vostok::ui::shift_state::data_storage)action->d;
  result->__vftable = (vostok::ui::base_edit_action_vtbl *)&vostok::ui::functor_edit_action::`vftable';
  result[1].__vftable = 0;
  result[1].m_parent = 0;
  *(fastdelegate::FastDelegate0<void> *)&result[1].__vftable = *functor;
  return result;
}
