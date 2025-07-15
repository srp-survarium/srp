fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *__thiscall survarium::weapon_user_animations_selector::look_time_calculator(
        survarium::weapon_user_animations_selector *this,
        fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *result)
{
  fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
    (vostok::animation::mixing::expression *)this,
    result);
  result->m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::weapon_user_animations_selector::look_time_factor_calculator;
  result->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  return result;
}
