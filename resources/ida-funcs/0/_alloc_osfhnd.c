int __cdecl _alloc_osfhnd()
{
  int v0; // edi
  stlp_std::ioinfo *v2; // esi
  unsigned __int8 *v3; // eax
  stlp_std::ioinfo **v4; // ecx
  int failed; // [esp+14h] [ebp-24h]
  int fh; // [esp+1Ch] [ebp-1Ch]

  fh = -1;
  v0 = 0;
  failed = 0;
  if ( !_mtinitlocknum(11) )
    return -1;
  _lock(11);
  while ( v0 < 64 )
  {
    v2 = __pioinfo[v0];
    if ( !v2 )
    {
      v3 = _calloc_crt(0x20u, 0x40u);
      if ( v3 )
      {
        v4 = &__pioinfo[v0];
        *v4 = (stlp_std::ioinfo *)v3;
        _nhandle += 32;
        while ( v3 < (unsigned __int8 *)&(*v4)[56].lock.SpinCount )
        {
          v3[4] = 0;
          *(_DWORD *)v3 = -1;
          v3[5] = 10;
          *((_DWORD *)v3 + 2) = 0;
          v3 += 64;
        }
        fh = 32 * v0;
        __pioinfo[(32 * v0) >> 5]->osfile = 1;
        if ( !__lock_fhandle(32 * v0) )
          fh = -1;
      }
      break;
    }
    while ( v2 < (stlp_std::ioinfo *)&__pioinfo[v0][56].lock.SpinCount )
    {
      if ( (v2->osfile & 1) == 0 )
      {
        if ( !v2->lockinitflag )
        {
          _lock(10);
          if ( !v2->lockinitflag )
          {
            if ( __crtInitCritSecAndSpinCount(&v2->lock, 0xFA0u) )
              ++v2->lockinitflag;
            else
              failed = 1;
          }
          _unlock(10);
        }
        if ( !failed )
        {
          EnterCriticalSection(&v2->lock);
          if ( (v2->osfile & 1) == 0 )
          {
            v2->osfile = 1;
            v2->osfhnd = -1;
            fh = 32 * v0 + (((char *)v2 - (char *)__pioinfo[v0]) >> 6);
            break;
          }
          LeaveCriticalSection(&v2->lock);
        }
      }
      v2 = (stlp_std::ioinfo *)((char *)v2 + 64);
    }
    if ( fh != -1 )
      break;
    ++v0;
  }
  _unlock(11);
  return fh;
}
