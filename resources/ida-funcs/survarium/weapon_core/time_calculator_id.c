unsigned __int8 __thiscall survarium::weapon_core::time_calculator_id(
        survarium::weapon_core *this,
        const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *time_calculator)
{
  fastdelegate::detail::GenericClass *m_pthis; // eax

  m_pthis = time_calculator->m_Closure.m_pthis;
  if ( time_calculator->m_Closure.m_pthis == (fastdelegate::detail::GenericClass *)this->m_portable_interactive_object->m_user_animations_selector.m_user
    && (double (__thiscall *)(survarium::base_player *, const float, const float, const unsigned int, const unsigned int, const unsigned int, const float))time_calculator->m_Closure.m_pFunction == survarium::base_player::look_time_factor_calculator )
  {
    return 0;
  }
  if ( m_pthis != (fastdelegate::detail::GenericClass *)this )
    return survarium::portable_interactive_object_core::hit_time_calculator_id(
             time_calculator,
             this->m_portable_interactive_object)
         + 4;
  if ( (double (__userpurge *)@<st0>(survarium::weapon_core *@<ecx>, float@<xmm4>, const float, const float, const unsigned int, const unsigned int, unsigned int, const float))time_calculator->m_Closure.m_pFunction == survarium::weapon_core::computed_backward_recoil_time )
    return 1;
  if ( m_pthis != (fastdelegate::detail::GenericClass *)this )
    return survarium::portable_interactive_object_core::hit_time_calculator_id(
             time_calculator,
             this->m_portable_interactive_object)
         + 4;
  if ( (double (__thiscall *)(survarium::weapon_core *, const float, const float, const unsigned int, const unsigned int, unsigned int, const float))time_calculator->m_Closure.m_pFunction == survarium::weapon_core::computed_horizontal_recoil_time )
    return 2;
  if ( m_pthis == (fastdelegate::detail::GenericClass *)this
    && (double (__thiscall *)(survarium::weapon_core *, const float, const float, const unsigned int, const unsigned int, unsigned int, const float))time_calculator->m_Closure.m_pFunction == survarium::weapon_core::computed_vertical_recoil_time )
  {
    return 3;
  }
  else
  {
    return survarium::portable_interactive_object_core::hit_time_calculator_id(
             time_calculator,
             this->m_portable_interactive_object)
         + 4;
  }
}
