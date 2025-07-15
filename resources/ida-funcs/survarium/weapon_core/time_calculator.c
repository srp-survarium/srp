fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *__thiscall survarium::weapon_core::time_calculator(
        survarium::weapon_core *this,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *result,
        const unsigned __int8 time_calculator_id)
{
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *v3; // eax
  survarium::portable_interactive_object_core *m_portable_interactive_object; // ecx

  if ( time_calculator_id )
  {
    if ( time_calculator_id == 1 )
    {
      v3 = result;
      result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::weapon_core::computed_backward_recoil_time;
    }
    else if ( time_calculator_id == 2 )
    {
      v3 = result;
      result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::weapon_core::computed_horizontal_recoil_time;
    }
    else
    {
      v3 = result;
      if ( time_calculator_id == 3 )
      {
        result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::weapon_core::computed_vertical_recoil_time;
      }
      else
      {
        m_portable_interactive_object = this->m_portable_interactive_object;
        result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::hit_animations_selector::hit_body_part::hit_time_factor_calculator;
        this = (survarium::weapon_core *)&m_portable_interactive_object->m_user_hit_animations_selector.m_hit_body_parts[(unsigned __int8)(time_calculator_id - 4)];
      }
    }
  }
  else
  {
    v3 = result;
    this = (survarium::weapon_core *)this->m_portable_interactive_object->m_user_animations_selector.m_user;
    result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::base_player::look_time_factor_calculator;
  }
  v3->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  return v3;
}
