int __usercall vostok::string_color@<eax>(char *str@<esi>)
{
  int v1; // eax
  int v3; // eax

  strstr((unsigned __int8 *)str, "<Warning>");
  if ( v1 )
    return -939458561;
  strstr((unsigned __int8 *)str, "<ERROR>");
  return v3 != 0 ? -939523841 : -922746881;
}
