unsigned __int8 __thiscall survarium::base_player::time_calculator_id_resolver(
        survarium::base_player *this,
        const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *time_calculator)
{
  int v2; // eax

  if ( time_calculator->m_Closure.m_pthis || time_calculator->m_Closure.m_pFunction )
    return ((int (__thiscall *)(survarium::interactive_object *, const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *))this->m_current_active_object->time_calculator_id)(
             this->m_current_active_object,
             time_calculator)
         + 1;
  else
    LOBYTE(v2) = 0;
  return v2;
}
