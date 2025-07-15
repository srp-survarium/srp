vostok::animation::mixing::expression *__userpurge survarium::weapon_core::selected_animations@<eax>(
        survarium::weapon_core *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer)
{
  survarium::weapon_core *v4; // esi
  unsigned int m_size; // eax
  int m_portable_interactive_object; // eax
  survarium::weapon_core *v7; // ecx
  vostok::animation::mixing::expression *v8; // eax
  bool v9; // zf
  vostok::animation::mixing::animation_lexeme *m_object; // ecx
  vostok::animation::mixing::animation_lexeme *v12; // [esp-4h] [ebp-C4h]
  vostok::animation::mixing::animation_lexeme *v13; // [esp+0h] [ebp-C0h]
  vostok::animation::mixing::expression v14; // [esp+10h] [ebp-B0h] BYREF
  survarium::weapon_animation_parameters weapon_parameters; // [esp+18h] [ebp-A8h] BYREF
  vostok::animation::mixing::expression v16; // [esp+20h] [ebp-A0h] BYREF
  vostok::animation::mixing::expression v17; // [esp+28h] [ebp-98h] BYREF
  stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> resulta; // [esp+30h] [ebp-90h] BYREF

  v4 = this;
  m_size = this->m_logic->m_current_state[12].transitions.m_size;
  weapon_parameters.body_part_mask = body_part_whole_body;
  LOBYTE(this) = this->m_aimed;
  weapon_parameters.is_firing = m_size == 5;
  m_portable_interactive_object = (int)v4->m_portable_interactive_object;
  weapon_parameters.is_aimed = (char)this;
  survarium::portable_interactive_object_core::selected_user_animations(
    (survarium::portable_interactive_object_core *)this,
    m_portable_interactive_object,
    &resulta,
    buffer,
    &weapon_parameters);
  ((void (__thiscall *)(vostok::ai::fsm_state *, vostok::animation::mixing::expression *, vostok::mutable_buffer *, unsigned int, vostok::animation::mixing::animation_lexeme *))v4->m_logic->m_current_state->__vftable[1].initialize)(
    v4->m_logic->m_current_state,
    &v14,
    buffer,
    v4->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size,
    &resulta.second);
  if ( v4->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size > 1 )
  {
    vostok::animation::mixing::operator+(&resulta.first, &v14, result);
    m_object = v12;
  }
  else
  {
    survarium::weapon_core::get_recoil_expression(v7, (int)v4, a2, &v17, buffer, v13);
    v8 = vostok::animation::mixing::operator+(&resulta.first, &v14, &v16);
    vostok::animation::mixing::operator+(v8, &v17, result);
    if ( v16.m_node.m_object )
    {
      v9 = v16.m_node.m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v16.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v16.m_node.m_object,
          0);
    }
    m_object = (vostok::animation::mixing::animation_lexeme *)v17.m_node.m_object;
    if ( v17.m_node.m_object )
    {
      v9 = v17.m_node.m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::animation_lexeme *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
          m_object,
          0);
    }
  }
  if ( v14.m_node.m_object )
  {
    v9 = v14.m_node.m_object->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v14.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v14.m_node.m_object,
        0);
  }
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(m_object, (int)&resulta.second);
  if ( resulta.first.m_node.m_object )
  {
    v9 = resulta.first.m_node.m_object->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))resulta.first.m_node.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        resulta.first.m_node.m_object,
        0);
  }
  return result;
}
