int __cdecl _fcloseall()
{
  int i; // edi
  int v1; // esi
  void **v2; // eax
  _iobuf *v3; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    v1 = i;
    v2 = &__piob[i];
    if ( *v2 )
    {
      v3 = (_iobuf *)*v2;
      if ( (v3->_flag & 0x83) != 0 && fclose(v3) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection((LPCRITICAL_SECTION)((char *)__piob[v1] + 32));
        free(__piob[v1]);
        __piob[v1] = 0;
      }
    }
  }
  _unlock(1);
  return count;
}
