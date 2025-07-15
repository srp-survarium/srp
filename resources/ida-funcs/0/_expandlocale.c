char *__cdecl _expandlocale(char *expr, char *output, unsigned int sizeInChars, tagLC_ID *id, unsigned __int8 *cp)
{
  const char *v5; // esi
  setloc_struct *p_setloc_data; // eax
  tagLC_ID *p_cacheid; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-B0h]
  __m128i *src; // [esp+14h] [ebp-ACh]
  char *cachein; // [esp+18h] [ebp-A8h]
  unsigned __int8 *str1; // [esp+28h] [ebp-98h]
  tagLC_STRINGS InStr; // [esp+2Ch] [ebp-94h] BYREF

  v5 = expr;
  p_setloc_data = &_getptd()->_setloc_data;
  src = (__m128i *)&p_setloc_data->_cachecp;
  p_cacheid = &p_setloc_data->_cacheid;
  cachein = p_setloc_data->_cachein;
  str1 = (unsigned __int8 *)p_setloc_data->_cacheout;
  if ( !expr || !output || !sizeInChars )
    return 0;
  if ( *expr == 67 && !expr[1] )
  {
    if ( strcpy_s((int)id, output, sizeInChars, "C") )
      _invoke_watson((int)p_cacheid, (int)id, 0);
    if ( id )
    {
      id->wLanguage = 0;
      id->wCountry = 0;
      id->wCodePage = 0;
    }
    if ( cp )
      *(_DWORD *)cp = 0;
    return output;
  }
  strlen((unsigned __int8 *)expr);
  v13 = v9;
  if ( v9 >= 0x83
    || (strcmp(str1, (unsigned __int8 *)expr), v10)
    && (strcmp((unsigned __int8 *)cachein, (unsigned __int8 *)expr), v11) )
  {
    if ( !__lc_strtolc(&InStr, expr) && __get_qualified_locale(&InStr, p_cacheid, &InStr) )
    {
      src->m128i_i32[0] = p_cacheid->wCodePage;
      __lc_lctostr(131, (char *)str1, 0x83u, &InStr);
      if ( !*expr || (v12 = v13, v13 >= 0x83) )
      {
        v12 = 0;
        v5 = uri;
      }
      if ( strncpy_s(131, cachein, 131, v5, v12 + 1) )
        _invoke_watson((int)p_cacheid, 131, 0);
      goto LABEL_23;
    }
    return 0;
  }
LABEL_23:
  if ( id )
    memcpy((int)id, (const __m128i *)p_cacheid, sizeof(tagLC_ID));
  if ( cp )
    memcpy((int)cp, src, 4u);
  if ( strcpy_s(131, output, sizeInChars, (const char *)str1) )
    _invoke_watson((int)p_cacheid, 131, 0);
  return (char *)str1;
}
