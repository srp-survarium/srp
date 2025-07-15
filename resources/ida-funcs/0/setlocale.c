char *__usercall setlocale@<eax>(int a1@<edi>, int a2@<esi>, unsigned int _category, char *_locale)
{
  _tiddata *v5; // esi
  unsigned __int8 *v6; // edi
  int v7; // eax
  char *retval; // [esp+14h] [ebp-20h]

  retval = 0;
  if ( _category <= 5 )
  {
    v5 = _getptd();
    __updatetlocinfo();
    v5->_ownlocale |= 0x10u;
    v6 = _calloc_crt(0xD8u, 1u);
    if ( v6 )
    {
      _lock(12);
      copytlocinfo_nolock((threadlocaleinfostruct *)v6, v5->ptlocinfo);
      _unlock(12);
      retval = setlocale_nolock(_locale, (threadlocaleinfostruct *)v6, _category);
      if ( retval )
      {
        if ( _locale )
        {
          strcmp((unsigned __int8 *)_locale, (unsigned __int8 *)__clocalestr);
          if ( v7 )
            __locale_changed = 1;
        }
        _lock(12);
        updatetlocinfoEx_nolock(&v5->ptlocinfo, (threadlocaleinfostruct *)v6);
        __removelocaleref((threadlocaleinfostruct *)v6);
        if ( (v5->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
        {
          updatetlocinfoEx_nolock(&__ptlocinfo, v5->ptlocinfo);
          memcpy((int)__lc_handle, (const __m128i *)__ptlocinfo->lc_handle, sizeof(__lc_handle));
          sync_legacy_variables_lk();
        }
        _unlock(12);
      }
      else
      {
        __removelocaleref((threadlocaleinfostruct *)v6);
        __freetlocinfo((threadlocaleinfostruct *)v6);
      }
    }
    v5->_ownlocale &= ~0x10u;
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, a1, a2);
    return 0;
  }
}
