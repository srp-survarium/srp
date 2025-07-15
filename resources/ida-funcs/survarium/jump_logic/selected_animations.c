stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> *__thiscall survarium::jump_logic::selected_animations(
        survarium::jump_logic *this,
        stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> *result,
        vostok::mutable_buffer *buffer,
        const survarium::weapon_animation_parameters *weapon_parameters,
        bool is_third_view)
{
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *v5; // eax
  vostok::ai::fsm_state *m_current_state; // [esp+0h] [ebp-14h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v8; // [esp+Ch] [ebp-8h] BYREF

  m_current_state = this->m_logic->m_current_state;
  v5 = survarium::weapon_user_animations_selector::look_time_calculator(this->m_owner, &v8);
  ((void (__thiscall *)(vostok::ai::fsm_state *, stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> *, vostok::mutable_buffer *, bool, fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *, const survarium::weapon_animation_parameters *))m_current_state->__vftable[1].initialize)(
    m_current_state,
    result,
    buffer,
    is_third_view,
    v5,
    weapon_parameters);
  return result;
}
