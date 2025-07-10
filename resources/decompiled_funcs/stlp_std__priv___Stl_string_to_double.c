void __thiscall stlp_std::priv::_Stl_string_to_double(const char *s)
{
  int v1; // eax
  const char *v2; // ecx
  int v3; // edx
  char *v4; // edi
  int v5; // ebx
  unsigned int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // edx
  char *v10; // ecx
  unsigned int v11; // eax
  int v12; // edi
  int v13; // ecx
  char digits[17]; // [esp+10h] [ebp-18h] BYREF
  char v15; // [esp+21h] [ebp-7h] BYREF

  v1 = *s;
  v2 = s + 1;
  if ( v1 == 43 || v1 == 45 )
    v1 = *v2++;
  v3 = 0;
  v4 = digits;
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = v1 - 48;
      if ( v6 >= 0xA )
        break;
      if ( v4 == &v15 )
      {
        v5 += v3 ^ 1;
        v1 = *v2++;
      }
      else
      {
        if ( v6 || v4 != digits )
          *v4++ = v6;
        v1 = *v2;
        v5 -= v3;
        ++v2;
      }
    }
    if ( v6 != -2 || v3 )
      break;
    v1 = *v2;
    v3 = 1;
    ++v2;
  }
  if ( v4 != digits )
  {
    if ( v6 != 53 && v6 != 21 )
    {
LABEL_28:
      v12 = v4 - digits;
      v13 = v12 + v5 - 1;
      if ( v13 >= -307 )
      {
        if ( v13 <= 308 )
        {
          stlp_std::priv::_Stl_atod(v12, v5);
        }
        else
        {
          *(_WORD *)digits = 0;
          *(_WORD *)&digits[2] = 0;
          *(_WORD *)&digits[4] = 0;
          *(_WORD *)&digits[6] = 32752;
        }
      }
      return;
    }
    v7 = *v2;
    v8 = 0;
    v9 = 0;
    v10 = (char *)(v2 + 1);
    if ( v7 != 43 && v7 != 32 )
    {
      if ( v7 != 45 )
        goto LABEL_23;
      v8 = 1;
    }
    v7 = *v10++;
LABEL_23:
    v11 = v7 - 48;
    if ( v11 < 0xA )
    {
      do
      {
        v9 = v11 + 10 * v9;
        v11 = *v10++ - 48;
      }
      while ( v11 < 0xA );
      if ( v8 )
        v9 = -v9;
      v5 += v9;
    }
    goto LABEL_28;
  }
}
