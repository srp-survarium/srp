int __usercall a2i_ipadd@<eax>(int a1@<ebx>, unsigned __int8 *ipout, char *ipasc)
{
  int v3; // eax

  strchr(ipasc, 0x3Au);
  if ( v3 )
    return ipv6_from_asc((int)ipout, a1, ipasc) != 0 ? 0x10 : 0;
  else
    return ipv4_from_asc(ipout, a1, ipasc) != 0 ? 4 : 0;
}
