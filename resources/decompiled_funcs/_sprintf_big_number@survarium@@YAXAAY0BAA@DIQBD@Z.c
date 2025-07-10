void __usercall survarium::sprintf_big_number(unsigned int value@<ecx>, const char *postfix@<eax>, char (*text)[256])
{
  if ( value >= 0x3E8 )
  {
    if ( value >= (unsigned int)&off_F4240 )
    {
      if ( value >= 0x3B9ACA00 )
        vostok::sprintf<256>(
          text,
          "%3d %3d %3d %3d %s",
          value / 0x3B9ACA00,
          value % 0x3B9ACA00 / 0xF4240,
          value % 0xF4240 / 0x3E8,
          value % 0x3E8,
          postfix);
      else
        vostok::sprintf<256>(text, "%3d %3d %3d %s", value / 0xF4240, value % 0xF4240 / 0x3E8, value % 0x3E8, postfix);
    }
    else
    {
      vostok::sprintf<256>(text, "%3d %3d %s", value / 0x3E8, value % 0x3E8, postfix);
    }
  }
  else
  {
    vostok::sprintf<256>(text, "%3d %s", value, postfix);
  }
}
