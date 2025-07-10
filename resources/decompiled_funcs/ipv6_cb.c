int __cdecl ipv6_cb(char *elem, int len, unsigned __int8 *usr)
{
  int v3; // eax
  int v5; // ecx

  v3 = *((_DWORD *)usr + 4);
  if ( v3 == 16 )
    return 0;
  if ( !len )
  {
    v5 = *((_DWORD *)usr + 5);
    if ( v5 == -1 )
    {
      ++*((_DWORD *)usr + 6);
      *((_DWORD *)usr + 5) = v3;
      return 1;
    }
    if ( v5 == v3 )
    {
      ++*((_DWORD *)usr + 6);
      return 1;
    }
    return 0;
  }
  if ( len <= 4 )
  {
    if ( !ipv6_hex(len, elem, &usr[v3]) )
      return 0;
    *((_DWORD *)usr + 4) += 2;
    return 1;
  }
  else
  {
    if ( v3 > 12 || elem[len] || !ipv4_from_asc(&usr[v3], elem) )
      return 0;
    *((_DWORD *)usr + 4) += 4;
    return 1;
  }
}
