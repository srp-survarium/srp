int __cdecl a2i_ipadd(unsigned __int8 *ipout, char *ipasc)
{
  int v2; // eax

  strchr(ipasc, 0x3Au);
  if ( v2 )
    return ipv6_from_asc(ipasc) != 0 ? 0x10 : 0;
  else
    return ipv4_from_asc(ipout, ipasc) != 0 ? 4 : 0;
}
