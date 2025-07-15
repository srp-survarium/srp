fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *__thiscall survarium::base_player::time_calculator_resolver(
        survarium::base_player *this,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *result,
        const unsigned __int8 time_calculator_id)
{
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *v3; // eax

  if ( time_calculator_id )
  {
    this->m_current_active_object->time_calculator(this->m_current_active_object, result, time_calculator_id - 1);
    return result;
  }
  else
  {
    v3 = result;
    result->m_Closure.m_pthis = 0;
    result->m_Closure.m_pFunction = 0;
  }
  return v3;
}
