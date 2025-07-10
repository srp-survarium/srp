bool __usercall Scaleform::GFx::AS2::StringToNumber@<al>(char *str@<esi>, long double *result)
{
  unsigned int v2; // ebx
  int v3; // eax
  int v4; // eax
  char v5; // al
  int v6; // ebp
  char *v7; // edi
  int v8; // eax
  long double v9; // st7
  char *tail; // [esp+0h] [ebp-8h] BYREF
  int sign; // [esp+4h] [ebp-4h]

  tail = 0;
  v2 = strlen(str);
  if ( *str != 48 )
    goto LABEL_6;
  v3 = str[1];
  if ( (unsigned int)(v3 - 65) <= 0x19 )
    v3 += 32;
  if ( v3 != 120 )
  {
LABEL_6:
    strcspn((unsigned __int8 *)str, ".Ee");
    if ( v4 != v2 )
    {
      *result = Scaleform::SFstrtod(str, &tail);
      return tail != str && !*tail;
    }
    v5 = *str;
    v6 = 1;
    v7 = str;
    sign = 1;
    if ( v5 == 45 )
    {
      v6 = -1;
      sign = -1;
    }
    else if ( v5 != 43 )
    {
LABEL_12:
      if ( *v7 == 48 && (strspn((unsigned __int8 *)v7, "01234567"), v8 == v2) )
      {
        sign = v6 * strtoul(v2, v7, &tail, 8u);
        *result = (double)sign;
      }
      else
      {
        v9 = Scaleform::SFstrtod(v7, &tail);
        *result = v9 * (double)sign;
      }
      return tail != str && !*tail;
    }
    --v2;
    v7 = str + 1;
    goto LABEL_12;
  }
  sign = strtoul(v2, str, &tail, 0);
  *result = (double)sign;
  return tail != str && !*tail;
}
