unsigned __int8 __userpurge survarium::portable_interactive_object_core::hit_time_calculator_id@<al>(
        const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *time_calculator@<esi>,
        survarium::portable_interactive_object_core *this)
{
  unsigned __int8 result; // al

  for ( result = 0;
        (survarium::hit_animations_selector::hit_body_part *)time_calculator->m_Closure.m_pthis != &this->m_user_hit_animations_selector.m_hit_body_parts[result]
     || (double (__thiscall *)(survarium::hit_animations_selector::hit_body_part *, const float, const float, const unsigned int, const unsigned int, unsigned int, const float))time_calculator->m_Closure.m_pFunction != survarium::hit_animations_selector::hit_body_part::hit_time_factor_calculator;
        ++result )
  {
    ;
  }
  return result;
}
