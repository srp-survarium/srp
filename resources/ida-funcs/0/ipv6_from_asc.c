int __usercall ipv6_from_asc@<eax>(int a1@<ecx>, int a2@<ebx>, char *in)
{
  int result; // eax
  unsigned int v5; // edi
  int v6; // ebx
  __int64 v7; // kr00_8
  int v8; // ecx
  __m128i src; // [esp+4h] [ebp-20h] BYREF
  int v10; // [esp+14h] [ebp-10h]
  unsigned int count; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]

  v10 = 0;
  count = -1;
  v12 = 0;
  result = CONF_parse_list(a2, in, 0x3Au, 0, (int (__cdecl *)(const char *, int, void *))ipv6_cb, &src);
  if ( result )
  {
    v5 = count;
    if ( count == -1 )
    {
      if ( v10 != 16 )
        return 0;
      goto LABEL_19;
    }
    v6 = v10;
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
      v7 = *(__int64 *)((char *)src.m128i_i64 + 4);
      *(_DWORD *)a1 = src.m128i_i32[0];
      v8 = src.m128i_i32[3];
      *(_QWORD *)(a1 + 4) = v7;
      *(_DWORD *)(a1 + 12) = v8;
      return 1;
    }
LABEL_17:
    memcpy(a1, &src, count);
    memset(a1 + v5, 0, 16 - v6);
    if ( v10 != count )
    {
      memcpy(a1 - v10 + count + 16, (__m128i *)((char *)&src + count), v10 - count);
      return 1;
    }
    return 1;
  }
  return result;
}
