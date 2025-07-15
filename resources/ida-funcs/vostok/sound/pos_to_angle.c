long double __usercall vostok::sound::pos_to_angle@<st0>(unsigned int pos@<eax>)
{
  if ( pos < 0x80 )
    return atan2((double)pos / (double)(128 - pos), 1.0);
  if ( pos < 0x100 )
    return atan2((double)(pos - 128) / (double)(256 - pos), 1.0) + 1.5707964;
  if ( pos >= 0x180 )
    return atan2((double)(pos - 384) / (double)(512 - pos), 1.0) - 1.5707964;
  return atan2((double)(pos - 256) / (double)(384 - pos), 1.0) - 3.1415927;
}
