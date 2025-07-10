double __usercall _convertTOStoQNaN@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (((unsigned int)&loc_7FFFE + 2) & a1) == 0 )
    return result + 1.0;
  return result;
}
