unsigned __int8 __thiscall survarium::victory_item_core::time_calculator_id(
        survarium::victory_item_core *this,
        const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *time_calculator)
{
  survarium::portable_interactive_object_core *m_portable_interactive_object; // eax

  m_portable_interactive_object = this->m_portable_interactive_object;
  if ( time_calculator->m_Closure.m_pthis == (fastdelegate::detail::GenericClass *)m_portable_interactive_object->m_user_animations_selector.m_user
    && (double (__thiscall *)(survarium::base_player *, const float, const float, const unsigned int, const unsigned int, const unsigned int, const float))time_calculator->m_Closure.m_pFunction == survarium::base_player::look_time_factor_calculator )
  {
    return 0;
  }
  else
  {
    return survarium::portable_interactive_object_core::hit_time_calculator_id(
             time_calculator,
             m_portable_interactive_object)
         + 1;
  }
}
