char *__cdecl setlocale(unsigned int _category, char *_locale)
{
  _tiddata *v3; // esi
  threadlocaleinfostruct *v4; // edi
  int v5; // eax
  char *retval; // [esp+14h] [ebp-20h]

  retval = 0;
  if ( _category <= 5 )
  {
    v3 = _getptd();
    __updatetlocinfo();
    v3->_ownlocale |= 0x10u;
    v4 = (threadlocaleinfostruct *)_calloc_crt(0xD8u, 1u);
    if ( v4 )
    {
      _lock(12);
      copytlocinfo_nolock(v4, v3->ptlocinfo);
      _unlock(12);
      retval = setlocale_nolock(_locale, v4, _category);
      if ( retval )
      {
        if ( _locale )
        {
          strcmp((unsigned __int8 *)_locale, (unsigned __int8 *)__clocalestr);
          if ( v5 )
            __locale_changed = 1;
        }
        _lock(12);
        updatetlocinfoEx_nolock(&v3->ptlocinfo, v4);
        __removelocaleref(v4);
        if ( (v3->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
        {
          updatetlocinfoEx_nolock(&__ptlocinfo, v3->ptlocinfo);
          memcpy((unsigned __int8 *)__lc_handle, (unsigned __int8 *)__ptlocinfo->lc_handle, sizeof(__lc_handle));
          sync_legacy_variables_lk();
        }
        _unlock(12);
      }
      else
      {
        __removelocaleref(v4);
        __freetlocinfo(v4);
      }
    }
    v3->_ownlocale &= ~0x10u;
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(0, 0, 0, 0, 0);
    return 0;
  }
}
