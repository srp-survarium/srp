int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock((_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( !flushflag && (v4 & 2) != 0 && _fflush_nolock((_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, (char *)__piob[i]);
      }
    }
  }
  _unlock(1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}
