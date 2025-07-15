double __thiscall vostok::sound::ogg_encoded_sound_interface::get_rms_by_time(
        vostok::sound::ogg_encoded_sound_interface *this,
        unsigned __int64 msec)
{
  float v3; // [esp+0h] [ebp-18h]

  v3 = (double)this->m_length_in_msec / (double)this->m_rms_count;
  return this->m_rms_data[msec / vostok::math::ceil(v3)];
}
