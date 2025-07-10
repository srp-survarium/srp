char *__cdecl _expandlocale(char *expr, char *output, unsigned int sizeInChars, tagLC_ID *id, unsigned __int8 *cp)
{
  const char *v5; // esi
  setloc_struct *p_setloc_data; // eax
  tagLC_ID *p_cacheid; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int charactersInExpression; // [esp+10h] [ebp-B0h]
  unsigned __int8 *pcachecp; // [esp+14h] [ebp-ACh]
  char *cachein; // [esp+18h] [ebp-A8h]
  char *cacheout; // [esp+28h] [ebp-98h]
  tagLC_STRINGS names; // [esp+2Ch] [ebp-94h] BYREF

  v5 = expr;
  p_setloc_data = &_getptd()->_setloc_data;
  pcachecp = (unsigned __int8 *)&p_setloc_data->_cachecp;
  p_cacheid = &p_setloc_data->_cacheid;
  cachein = p_setloc_data->_cachein;
  cacheout = p_setloc_data->_cacheout;
  if ( !expr || !output || !sizeInChars )
    return 0;
  if ( *expr == 67 && !expr[1] )
  {
    if ( strcpy_s(output, sizeInChars, "C") )
      _invoke_watson(0, 0, 0, 0, 0);
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
  charactersInExpression = v9;
  if ( v9 >= 0x83
    || (strcmp((unsigned __int8 *)cacheout, (unsigned __int8 *)expr), v10)
    && (strcmp((unsigned __int8 *)cachein, (unsigned __int8 *)expr), v11) )
  {
    if ( !__lc_strtolc(&names, expr) && __get_qualified_locale(&names, p_cacheid, &names) )
    {
      *(_DWORD *)pcachecp = p_cacheid->wCodePage;
      __lc_lctostr(cacheout, 0x83u, &names);
      if ( !*expr || (v12 = charactersInExpression, charactersInExpression >= 0x83) )
      {
        v12 = 0;
        v5 = (const char *)&buf;
      }
      if ( strncpy_s(cachein, 0x83u, v5, v12 + 1) )
        _invoke_watson(0, 0, 0, 0, 0);
      goto LABEL_23;
    }
    return 0;
  }
LABEL_23:
  if ( id )
    memcpy((unsigned __int8 *)id, (unsigned __int8 *)p_cacheid, sizeof(tagLC_ID));
  if ( cp )
    memcpy(cp, pcachecp, 4u);
  if ( strcpy_s(output, sizeInChars, cacheout) )
    _invoke_watson(0, 0, 0, 0, 0);
  return cacheout;
}
