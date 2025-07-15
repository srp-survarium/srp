void __thiscall vostok::sound::sound_voice::set_low_pass_filter_params(vostok::sound::sound_voice *this, float coeff)
{
  vostok::sound::voice_bridge::set_low_pass_filter_params(this->m_voice, coeff);
}
