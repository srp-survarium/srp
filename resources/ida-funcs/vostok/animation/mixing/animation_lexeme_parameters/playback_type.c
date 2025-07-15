vostok::animation::mixing::animation_lexeme_parameters *__usercall vostok::animation::mixing::animation_lexeme_parameters::playback_type@<eax>(
        vostok::animation::mixing::animation_lexeme_parameters *this@<ecx>,
        vostok::animation::mixing::animation_lexeme_parameters *result@<eax>)
{
  result->m_playback_type = (vostok::animation::mixing::playback_enum)this;
  return result;
}
