int __cdecl __getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        unsigned int localehandle,
        unsigned int fieldtype,
        char **address)
{
  unsigned __int8 *v5; // edi
  unsigned int LocaleInfoA; // esi
  unsigned int v7; // eax
  char *v8; // eax
  char *v9; // eax
  wchar_t *v11; // edi
  char v12; // bl
  int buffersize; // [esp+10h] [ebp-90h]
  int bufferused; // [esp+18h] [ebp-88h]
  unsigned __int8 cbuffer[128]; // [esp+1Ch] [ebp-84h] BYREF

  if ( lc_type == 1 )
  {
    v5 = cbuffer;
    bufferused = 0;
    LocaleInfoA = __crtGetLocaleInfoA(plocinfo, localehandle, fieldtype, (char *)cbuffer, 128, 0);
    if ( !LocaleInfoA )
    {
      if ( GetLastError() != 122 )
        return -1;
      v7 = __crtGetLocaleInfoA(plocinfo, localehandle, fieldtype, 0, 0, 0);
      buffersize = v7;
      if ( !v7 )
        return -1;
      v8 = (char *)_calloc_crt(v7, 1u);
      v5 = (unsigned __int8 *)v8;
      if ( !v8 )
        return -1;
      bufferused = 1;
      LocaleInfoA = __crtGetLocaleInfoA(plocinfo, localehandle, fieldtype, v8, buffersize, 0);
      if ( !LocaleInfoA )
        goto LABEL_9;
    }
    v9 = (char *)_calloc_crt(LocaleInfoA, 1u);
    *address = v9;
    if ( !v9 )
    {
      if ( !bufferused )
        return -1;
LABEL_9:
      free(v5);
      return -1;
    }
    if ( strncpy_s(v9, LocaleInfoA, (const char *)v5, LocaleInfoA - 1) )
      _invoke_watson(0, (unsigned int)v5, LocaleInfoA);
    if ( bufferused )
      free(v5);
  }
  else
  {
    if ( lc_type )
      return -1;
    v11 = wcbuffer;
    if ( !__crtGetLocaleInfoW(plocinfo, localehandle, fieldtype, wcbuffer, 4, 0) )
      return -1;
    *(_BYTE *)address = 0;
    do
    {
      v12 = *(_BYTE *)v11;
      if ( !isdigit(*(unsigned __int8 *)v11) )
        break;
      ++v11;
      *(_BYTE *)address = v12 + 10 * *(_BYTE *)address - 48;
    }
    while ( (int)v11 < (int)&__pPurecall );
  }
  return 0;
}
