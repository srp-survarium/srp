bool __cdecl Scaleform::Render::Text::SGMLParser<wchar_t>::ParseFloat(
        float *pdestVal,
        const wchar_t *pstr,
        unsigned int len)
{
  bool result; // al
  const wchar_t *v4; // esi
  double v5; // st7
  const wchar_t *v6; // edi
  wchar_t v7; // ax
  double v8; // st6
  const wchar_t *v9; // esi
  double v10; // st7
  int v11; // [esp+Ch] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-1Ch]
  double v13; // [esp+10h] [ebp-18h]
  double v14; // [esp+18h] [ebp-10h]
  double v15; // [esp+20h] [ebp-8h]

  if ( !len )
    return 0;
  v4 = pstr;
  v5 = 0.0;
  v6 = &pstr[len];
  v13 = 0.0;
  v15 = 1.0;
  if ( *pstr == 45 )
  {
    v15 = -1.0;
LABEL_6:
    v4 = pstr + 1;
    goto LABEL_7;
  }
  if ( *pstr == 43 )
    goto LABEL_6;
LABEL_7:
  if ( v4 < v6 )
  {
    while ( 1 )
    {
      v7 = *v4;
      if ( *v4 == 46 || v7 == 44 )
        break;
      if ( !isdigit(v7) )
        return 0;
      v11 = *v4++ - 48;
      v5 = (double)v11 + v13 * 10.0;
      v13 = v5;
      if ( v4 >= v6 )
      {
        result = 1;
        *pdestVal = v5 * v15;
        return result;
      }
    }
    if ( v4 < v6 && (*v4 == 46 || *v4 == 44) )
    {
      v8 = 0.0;
      v9 = v4 + 1;
      v14 = 0.0;
      if ( v9 < v6 )
      {
        while ( isdigit(*v9) )
        {
          v12 = *v9++ - 48;
          v10 = ((double)v12 + v14) * 0.1;
          v14 = v10;
          if ( v9 >= v6 )
          {
            v8 = v10;
            v5 = v13;
            goto LABEL_20;
          }
        }
        return 0;
      }
LABEL_20:
      v5 = v5 + v8;
    }
  }
  result = 1;
  *pdestVal = v5 * v15;
  return result;
}
