int __usercall ipv6_cb@<eax>(int a1@<ebx>, char *elem, int len, unsigned __int8 *usr)
{
  int v4; // eax
  int v6; // ecx

  v4 = *((_DWORD *)usr + 4);
  if ( v4 == 16 )
    return 0;
  if ( !len )
  {
    v6 = *((_DWORD *)usr + 5);
    if ( v6 == -1 )
    {
      ++*((_DWORD *)usr + 6);
      *((_DWORD *)usr + 5) = v4;
      return 1;
    }
    if ( v6 == v4 )
    {
      ++*((_DWORD *)usr + 6);
      return 1;
    }
    return 0;
  }
  if ( len <= 4 )
  {
    if ( !ipv6_hex(len, elem, &usr[v4]) )
      return 0;
    *((_DWORD *)usr + 4) += 2;
    return 1;
  }
  else
  {
    if ( v4 > 12 || elem[len] || !ipv4_from_asc(&usr[v4], a1, elem) )
      return 0;
    *((_DWORD *)usr + 4) += 4;
    return 1;
  }
}
