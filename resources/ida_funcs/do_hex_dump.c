int __usercall do_hex_dump@<eax>(
        void *arg@<edi>,
        unsigned __int8 *buf@<ecx>,
        int (__cdecl *io_ch)(void *, const void *, int),
        int buflen)
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebx
  char v6; // al
  _BYTE v8[4]; // [esp+Ch] [ebp-4h] BYREF

  v4 = buf;
  if ( !arg )
    return 2 * buflen;
  v5 = &buf[buflen];
  if ( buf == &buf[buflen] )
    return 2 * buflen;
  while ( 1 )
  {
    v6 = hexdig_0[*v4 & 0xF];
    v8[0] = hexdig_0[*v4 >> 4];
    v8[1] = v6;
    if ( !io_ch(arg, v8, 2) )
      break;
    if ( ++v4 == v5 )
      return 2 * buflen;
  }
  return -1;
}
