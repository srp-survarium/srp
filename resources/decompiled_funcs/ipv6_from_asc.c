int __cdecl ipv6_from_asc(char *in)
{
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v2; // esi
  int result; // eax
  unsigned int v4; // edi
  int v5; // ebx
  int edx19; // edx
  int v7; // eax
  int v8; // ecx
  _DWORD arg[4]; // [esp+4h] [ebp-20h] BYREF
  int v10; // [esp+14h] [ebp-10h]
  unsigned int count; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]

  v2 = v6;
  v10 = 0;
  count = -1;
  v12 = 0;
  result = CONF_parse_list(in, 0x3Au, 0, (int (__cdecl *)(const char *, int, void *))ipv6_cb, arg);
  if ( result )
  {
    v4 = count;
    if ( count == -1 )
    {
      if ( v10 != 16 )
        return 0;
      goto LABEL_19;
    }
    v5 = v10;
    if ( v10 == 16 || v12 > 3 )
      return 0;
    if ( v12 == 3 )
    {
      if ( v10 > 0 )
        return 0;
    }
    else if ( v12 == 2 )
    {
      if ( !count )
        goto LABEL_17;
      if ( count != v10 )
        return 0;
    }
    else if ( !count || count == v10 )
    {
      return 0;
    }
    if ( (count & 0x80000000) != 0 )
    {
LABEL_19:
      edx19 = arg[1];
      v7 = arg[2];
      *(_DWORD *)v2 = arg[0];
      v8 = arg[3];
      *((_DWORD *)v2 + 1) = edx19;
      *((_DWORD *)v2 + 2) = v7;
      *((_DWORD *)v2 + 3) = v8;
      return 1;
    }
LABEL_17:
    memcpy(v2, (unsigned __int8 *)arg, count);
    memset((int)&v2[v4], 0, 16 - v5);
    if ( v10 != count )
    {
      memcpy(&v2[count - v10 + 16], (unsigned __int8 *)arg + count, v10 - count);
      return 1;
    }
    return 1;
  }
  return result;
}
