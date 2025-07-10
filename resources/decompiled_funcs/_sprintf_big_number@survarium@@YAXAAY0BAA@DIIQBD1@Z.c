void __usercall survarium::sprintf_big_number(
        unsigned int value@<ecx>,
        unsigned int divider@<eax>,
        const char *complex_postfix@<edi>,
        char (*text)[256],
        const char *simple_postfix)
{
  if ( value >= divider )
  {
    if ( value >= divider * divider )
    {
      if ( value >= divider * divider * divider )
        vostok::sprintf<256>(
          text,
          "%5.1f G%s",
          (double)value / ((double)divider * ((double)divider * (double)divider)),
          complex_postfix);
      else
        vostok::sprintf<256>(text, "%5.1f M%s", (double)value / ((double)divider * (double)divider), complex_postfix);
    }
    else
    {
      vostok::sprintf<256>(text, "%5.1f K%s", (double)value / (double)divider, complex_postfix);
    }
  }
  else
  {
    survarium::sprintf_big_number(value, simple_postfix, text);
  }
}
