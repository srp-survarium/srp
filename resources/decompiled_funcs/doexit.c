void __cdecl doexit(int code, int quick, int retcaller)
{
  void **v3; // edi
  void **v4; // esi
  void (*v5)(void); // edi
  void (__cdecl **v6)(); // edi
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-28h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-20h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-1Ch]

  _lock(8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( !quick )
    {
      v3 = (void **)_decode_pointer(__onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 )
      {
        v4 = (void **)_decode_pointer(__onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != (void *)_encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))_decode_pointer(*v4);
            *v4 = (void *)_encoded_null();
            v5();
            v6 = (void (__cdecl **)())_decode_pointer(__onexitbegin);
            v7 = (void (__cdecl **)())_decode_pointer(__onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (void **)v7;
            }
            v3 = (void **)onexitbegin;
          }
        }
      }
      initterm(__xp_a, __xp_z);
    }
    initterm(__xt_a, __xt_z);
  }
  if ( retcaller )
    _unlock(8);
  if ( !retcaller )
  {
    _C_Exit_Done = 1;
    _unlock(8);
    __crtExitProcess(code);
  }
}
