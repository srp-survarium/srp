double __cdecl vostok::sound::pos_to_angle(unsigned int pos)
{
  float v2; // [esp+0h] [ebp-60h]
  float v3; // [esp+14h] [ebp-4Ch]
  float v4; // [esp+28h] [ebp-38h]

  if ( pos >= 0x80 )
  {
    if ( pos >= 0x100 )
    {
      if ( pos >= 0x180 )
      {
        v2 = atan((double)(pos - 384) / (double)(512 - pos));
        return v2 - 1.5707964;
      }
      else
      {
        v3 = atan((double)(pos - 256) / (double)(384 - pos));
        return v3 - 3.1415927;
      }
    }
    else
    {
      v4 = atan((double)(pos - 128) / (double)(256 - pos));
      return v4 + 1.5707964;
    }
  }
  else
  {
    return (float)atan((double)pos / (double)(128 - pos));
  }
}
