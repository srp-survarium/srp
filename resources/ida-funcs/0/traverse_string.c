int __usercall traverse_string@<eax>(
        const unsigned __int8 *p@<edx>,
        int len@<ecx>,
        int (__cdecl *rfunc)(unsigned int, void *)@<ebx>,
        int inform,
        void *arg)
{
  int v5; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  const unsigned __int8 *v9; // esi
  int v10; // edx
  const unsigned __int8 *v11; // esi
  int v12; // ecx
  int v13; // eax
  int result; // eax
  unsigned int val; // [esp+Ch] [ebp-4h] BYREF

  v5 = len;
  while ( v5 )
  {
    switch ( inform )
    {
      case 4097:
        v7 = *p++;
        val = v7;
        --v5;
        break;
      case 4098:
        v8 = *p << 8;
        v9 = p + 1;
        val = v8;
        v7 = *v9 | v8;
        p = v9 + 1;
        val = v7;
        v5 -= 2;
        break;
      case 4100:
        val = *p << 24;
        v10 = p[1];
        v11 = p + 1;
        val |= v10 << 16;
        v12 = v11[1] << 8;
        v11 += 2;
        val |= v12;
        v7 = *v11 | val;
        p = v11 + 1;
        val = v7;
        v5 -= 4;
        break;
      default:
        v13 = UTF8_getc(p, v5, &val);
        if ( v13 < 0 )
          return -1;
        v5 -= v13;
        p += v13;
        v7 = val;
        break;
    }
    if ( rfunc )
    {
      result = rfunc(v7, arg);
      if ( result <= 0 )
        return result;
    }
  }
  return 1;
}
