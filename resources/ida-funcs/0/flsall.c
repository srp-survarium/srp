int __usercall flsall@<eax>(int a1@<ebx>, int flushflag)
{
  int i; // esi
  char **v3; // eax
  char *v4; // eax
  int v5; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(1);
  for ( i = 0; i < _nstream; ++i )
  {
    v3 = (char **)&__piob[i];
    if ( *v3 )
    {
      v4 = *v3;
      if ( (v4[12] & 0x83) != 0 )
      {
        _lock_file2(i, v4);
        v5 = *((_DWORD *)__piob[i] + 3);
        if ( (v5 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(a1, 0, (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( !flushflag && (v5 & 2) != 0 && _fflush_nolock(a1, 0, (_iobuf *)__piob[i]) == -1 )
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
