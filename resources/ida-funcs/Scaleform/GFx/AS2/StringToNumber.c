bool __usercall Scaleform::GFx::AS2::StringToNumber@<al>(char *str@<esi>, int a2@<edi>, long double *result)
{
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  char v6; // al
  int v7; // ebp
  char *v8; // edi
  int v9; // eax
  long double v10; // st7
  char *v12; // [esp+0h] [ebp-8h] BYREF
  signed int v13; // [esp+4h] [ebp-4h]

  v12 = 0;
  v3 = strlen(str);
  if ( *str != 48 )
    goto LABEL_6;
  v4 = str[1];
  if ( (unsigned int)(v4 - 65) <= 0x19 )
    v4 += 32;
  if ( v4 != 120 )
  {
LABEL_6:
    strcspn((unsigned __int8 *)str, ".Ee");
    if ( v5 != v3 )
    {
      *result = Scaleform::SFstrtod(a2, str, &v12);
      return v12 != str && !*v12;
    }
    v6 = *str;
    v7 = 1;
    v8 = str;
    v13 = 1;
    if ( v6 == 45 )
    {
      v7 = -1;
      v13 = -1;
    }
    else if ( v6 != 43 )
    {
LABEL_12:
      if ( *v8 == 48 && (strspn((unsigned __int8 *)v8, "01234567"), v9 == v3) )
      {
        v13 = v7 * strtoul(v3, v8, (const char **)&v12, 8);
        *result = (double)v13;
      }
      else
      {
        v10 = Scaleform::SFstrtod((int)v8, v8, &v12);
        *result = v10 * (double)v13;
      }
      return v12 != str && !*v12;
    }
    --v3;
    v8 = str + 1;
    goto LABEL_12;
  }
  v13 = strtoul(v3, str, (const char **)&v12, 0);
  *result = (double)v13;
  return v12 != str && !*v12;
}
