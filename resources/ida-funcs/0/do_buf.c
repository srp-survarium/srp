int __fastcall do_buf(
        char *quotes,
        int (__cdecl *io_ch)(void *, const void *, int),
        unsigned __int8 *buf,
        int buflen,
        char type,
        unsigned __int8 flags,
        void *arg)
{
  int v7; // eax
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // ebx
  int v10; // ebp
  int v11; // ecx
  unsigned __int8 *v12; // ebx
  int v13; // edx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // ebp
  unsigned __int8 v17; // dl
  int v18; // eax
  int v19; // eax
  char v21; // [esp+13h] [ebp-31h]
  unsigned __int8 i; // [esp+13h] [ebp-31h]
  unsigned int val; // [esp+14h] [ebp-30h] BYREF
  int v24; // [esp+18h] [ebp-2Ch]
  unsigned __int8 *v25; // [esp+1Ch] [ebp-28h]
  char *v26; // [esp+20h] [ebp-24h]
  int (__cdecl *v27)(void *, const void *, int); // [esp+24h] [ebp-20h]
  unsigned __int8 *v28; // [esp+28h] [ebp-1Ch]
  int v29; // [esp+2Ch] [ebp-18h]
  int v30; // [esp+30h] [ebp-14h]
  int v31; // [esp+34h] [ebp-10h]
  unsigned __int8 v32[8]; // [esp+38h] [ebp-Ch] BYREF

  v7 = buflen;
  v8 = buf;
  v26 = quotes;
  v25 = buf;
  v31 = buflen;
  v27 = io_ch;
  v9 = buf;
  v28 = &buf[buflen];
  v24 = 0;
  if ( buf == &buf[buflen] )
    return v24;
  v10 = type & 7;
  v29 = v10;
  while ( 2 )
  {
    if ( v9 != v8 || (v21 = 32, (flags & 1) == 0) )
      v21 = 0;
    switch ( v10 )
    {
      case 0:
        v15 = UTF8_getc(v9, v7, &val);
        if ( v15 < 0 )
          return -1;
        v9 += v15;
        v14 = val;
        goto LABEL_13;
      case 1:
        v14 = *v9;
        val = v14;
        ++v9;
        goto LABEL_13;
      case 2:
        val = *v9 << 8;
        v14 = v9[1] | val;
        val = v14;
        v9 += 2;
        goto LABEL_13;
      case 4:
        val = *v9 << 24;
        v11 = v9[1];
        v12 = v9 + 1;
        val |= v11 << 16;
        v13 = *++v12;
        val |= v13 << 8;
        v14 = v12[1] | val;
        val = v14;
        v9 = v12 + 2;
LABEL_13:
        if ( v9 == v28 && (flags & 1) != 0 )
          v21 = 64;
        if ( (type & 8) == 0 )
        {
          v19 = do_esc_char(flags | v21, v27, arg, v14, v26);
          if ( v19 < 0 )
            return -1;
          v24 += v19;
LABEL_25:
          v8 = v25;
LABEL_26:
          if ( v9 == v28 )
            return v24;
          v10 = v29;
          v7 = v31;
          continue;
        }
        v16 = 0;
        v30 = UTF8_putc(v32, 6, v14);
        if ( v30 <= 0 )
          goto LABEL_26;
        v17 = flags | v21;
        for ( i = flags | v21; ; v17 = i )
        {
          v18 = do_esc_char(v17, v27, arg, v32[v16], v26);
          if ( v18 < 0 )
            break;
          v24 += v18;
          if ( ++v16 >= v30 )
            goto LABEL_25;
        }
        return -1;
      default:
        return -1;
    }
  }
}
