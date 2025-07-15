double __thiscall vostok::math::half_pod::operator float(vostok::math::half_pod *this)
{
  unsigned int m; // [esp+4h] [ebp-Ch]
  unsigned int e; // [esp+8h] [ebp-8h]
  unsigned int s; // [esp+Ch] [ebp-4h]

  s = (this->data & 0x8000) << 16;
  e = ((int)this->data >> 10) & 0x1F;
  m = this->data & 0x3FF;
  if ( e )
  {
    if ( e == 31 )
      return COERCE_FLOAT(s | (m << 13) | 0x7F800000);
  }
  else
  {
    if ( (this->data & 0x3FF) == 0 )
      return *(float *)&s;
    while ( (m & 0x400) == 0 )
    {
      m *= 2;
      --e;
    }
    ++e;
    m &= ~0x400u;
  }
  return COERCE_FLOAT(s | (m << 13) | ((e + 112) << 23));
}
