vostok::animation::mixing::animation_lexeme_parameters *__usercall vostok::animation::mixing::animation_lexeme_parameters::time_calculator@<eax>(
        vostok::animation::mixing::animation_lexeme_parameters *this@<ecx>,
        vostok::animation::mixing::animation_lexeme_parameters *result@<eax>)
{
  result->m_time_calculator.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))this->m_time_calculator.m_Closure.m_pthis;
  result->m_time_calculator.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this->m_buffer;
  return result;
}
