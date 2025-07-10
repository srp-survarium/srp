double __thiscall vostok::sound::sound_world::get_time_scale_factor(vostok::sound::sound_world *this)
{
  float v2; // [esp+10h] [ebp-4h] BYREF

  _InterlockedExchange((volatile __int32 *)&v2, this->m_time_factor.m_data.m_atomic);
  return v2;
}
