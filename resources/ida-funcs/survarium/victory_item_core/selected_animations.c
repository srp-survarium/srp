vostok::animation::mixing::expression *__thiscall survarium::victory_item_core::selected_animations(
        survarium::victory_item_core *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer)
{
  survarium::portable_interactive_object_core *m_portable_interactive_object; // eax
  vostok::animation::mixing::animation_lexeme *v5; // ecx
  bool v6; // zf
  vostok::animation::mixing::animation_lexeme *v8; // [esp+4h] [ebp-ACh]
  vostok::animation::mixing::expression v9; // [esp+10h] [ebp-A0h] BYREF
  survarium::weapon_animation_parameters v10; // [esp+18h] [ebp-98h] BYREF
  stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> v11; // [esp+20h] [ebp-90h] BYREF

  v10.body_part_mask = this->m_logic.m_current_state[1].transitions.m_size;
  m_portable_interactive_object = this->m_portable_interactive_object;
  v10.is_aimed = 0;
  v10.is_firing = 0;
  survarium::portable_interactive_object_core::selected_user_animations(
    (survarium::portable_interactive_object_core *)this,
    (int)m_portable_interactive_object,
    &v11,
    buffer,
    &v10);
  ((void (__thiscall *)(vostok::ai::fsm_state *, vostok::animation::mixing::expression *, vostok::mutable_buffer *, unsigned int, vostok::animation::mixing::animation_lexeme *))this->m_logic.m_current_state->__vftable[1].execute)(
    this->m_logic.m_current_state,
    &v9,
    buffer,
    this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size,
    &v11.second);
  vostok::animation::mixing::operator+(&v11.first, &v9, result);
  v5 = v8;
  if ( v9.m_node.m_object )
  {
    v6 = v9.m_node.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v9.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v9.m_node.m_object,
        0);
  }
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v5, (int)&v11.second);
  if ( v11.first.m_node.m_object )
  {
    v6 = v11.first.m_node.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v11.first.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v11.first.m_node.m_object,
        0);
  }
  return result;
}
