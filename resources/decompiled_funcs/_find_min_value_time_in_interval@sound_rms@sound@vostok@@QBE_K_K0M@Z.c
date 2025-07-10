unsigned __int64 __thiscall vostok::sound::sound_rms::find_min_value_time_in_interval(
        vostok::sound::sound_rms *this,
        unsigned __int64 start_time,
        unsigned __int64 end_time,
        float min_value)
{
  unsigned __int64 start_index; // [esp+68h] [ebp-18h]
  unsigned __int64 min_index; // [esp+70h] [ebp-10h]
  float min; // [esp+78h] [ebp-8h]
  float ratio; // [esp+7Ch] [ebp-4h]

  ratio = (double)this->m_length_in_msec / (double)this->m_count;
  start_index = (unsigned __int64)((double)start_time / ratio) + 1;
  min = this->m_data[start_index];
  min_index = start_index;
  while ( start_index <= (unsigned __int64)((double)end_time / ratio) )
  {
    if ( min_value > min || fabs(min - min_value) < 0.0000099999997 )
    {
      min_index = start_index;
      return (unsigned __int64)((double)min_index * ratio);
    }
    if ( min > this->m_data[start_index] )
    {
      min = this->m_data[start_index];
      min_index = start_index;
    }
    ++start_index;
  }
  return (unsigned __int64)((double)min_index * ratio);
}
