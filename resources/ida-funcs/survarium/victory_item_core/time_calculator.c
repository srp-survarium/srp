fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *__thiscall survarium::victory_item_core::time_calculator(
        survarium::victory_item_core *this,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *result,
        const unsigned __int8 time_calculator_id)
{
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *v3; // eax
  survarium::portable_interactive_object_core *m_portable_interactive_object; // ecx
  fastdelegate::detail::GenericClass *m_user; // ecx

  v3 = result;
  m_portable_interactive_object = this->m_portable_interactive_object;
  if ( time_calculator_id )
  {
    result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::hit_animations_selector::hit_body_part::hit_time_factor_calculator;
    m_user = (fastdelegate::detail::GenericClass *)&m_portable_interactive_object->m_user_hit_animations_selector.m_hit_body_parts[(unsigned __int8)(time_calculator_id - 1)];
  }
  else
  {
    m_user = (fastdelegate::detail::GenericClass *)m_portable_interactive_object->m_user_animations_selector.m_user;
    result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::base_player::look_time_factor_calculator;
  }
  result->m_Closure.m_pthis = m_user;
  return v3;
}
