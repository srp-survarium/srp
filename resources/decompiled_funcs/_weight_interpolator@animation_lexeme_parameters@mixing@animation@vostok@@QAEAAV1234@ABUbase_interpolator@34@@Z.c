vostok::animation::mixing::animation_lexeme_parameters *__usercall vostok::animation::mixing::animation_lexeme_parameters::weight_interpolator@<eax>(
        vostok::animation::mixing::animation_lexeme_parameters *this@<ecx>,
        vostok::animation::mixing::animation_lexeme_parameters *result@<eax>)
{
  result->m_weight_interpolator = (const vostok::animation::base_interpolator *)this;
  return result;
}
