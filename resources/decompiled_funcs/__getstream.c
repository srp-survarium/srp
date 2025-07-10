_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  int v4; // esi

  v0 = 0;
  _lock(1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( !*v2 )
    {
      v4 = i;
      __piob[v4] = _malloc_crt(0x38u);
      if ( __piob[v4] )
      {
        if ( __crtInitCritSecAndSpinCount((_RTL_CRITICAL_SECTION *)((char *)__piob[v4] + 32), 0xFA0u) )
        {
          EnterCriticalSection((LPCRITICAL_SECTION)((char *)__piob[v4] + 32));
          v0 = __piob[v4];
          v0[3] = 0;
        }
        else
        {
          free(__piob[v4]);
          __piob[v4] = 0;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && !_mtinitlocknum(i + 16) )
        break;
      _lock_file2(i, (char *)__piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, (char *)__piob[i]);
    }
  }
  if ( v0 )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(1);
  return (_iobuf *)v0;
}
