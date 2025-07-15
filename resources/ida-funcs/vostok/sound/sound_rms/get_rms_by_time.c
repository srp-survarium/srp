double __thiscall vostok::sound::sound_rms::get_rms_by_time(vostok::sound::sound_rms *this, unsigned __int64 msec)
{
  float value; // [esp+0h] [ebp-48h]

  value = (double)this->m_length_in_msec / (double)this->m_count;
  return this->m_data[msec / vostok::math::ceil(value)];
}
