vostok::animation::mixing::animation_lexeme_parameters *__usercall vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator@<eax>(
        vostok::animation::mixing::animation_lexeme_parameters *this@<ecx>,
        vostok::animation::mixing::animation_lexeme_parameters *result@<eax>)
{
  result->m_time_scale_interpolator = (const vostok::animation::base_interpolator *)this;
  return result;
}
