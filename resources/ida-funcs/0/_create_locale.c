threadmbcinfostruct **__cdecl _create_locale(unsigned int _category, char *_locale)
{
  threadmbcinfostruct **v2; // esi
  threadmbcinfostruct *v4; // eax
  threadmbcinfostruct *v5; // eax

  if ( _category > 5 || !_locale )
    return 0;
  v2 = (threadmbcinfostruct **)_calloc_crt(8u, 1u);
  if ( !v2 )
  {
LABEL_4:
    *_errno() = 12;
    return 0;
  }
  v4 = (threadmbcinfostruct *)_calloc_crt(0xD8u, 1u);
  *v2 = v4;
  if ( !v4 )
  {
    free(v2);
    goto LABEL_4;
  }
  v5 = (threadmbcinfostruct *)_calloc_crt(0x220u, 1u);
  v2[1] = v5;
  if ( !v5 )
  {
    free(*v2);
    free(v2);
    goto LABEL_4;
  }
  copytlocinfo_nolock((threadlocaleinfostruct *)*v2, &__initiallocinfo);
  if ( setlocale_nolock(_locale, (threadlocaleinfostruct *)*v2, _category) )
  {
    if ( !_setmbcp_nolock((*v2)->mbcodepage, v2[1]) )
    {
      v2[1]->refcount = 1;
      v2[1]->refcount = 1;
      return v2;
    }
    free(v2[1]);
    __removelocaleref((threadlocaleinfostruct *)*v2);
    __freetlocinfo((threadlocaleinfostruct *)*v2);
    free(v2);
  }
  else
  {
    __removelocaleref((threadlocaleinfostruct *)*v2);
    __freetlocinfo((threadlocaleinfostruct *)*v2);
    free(v2);
  }
  return 0;
}
