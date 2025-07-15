int __cdecl _free_osfhnd(int fh)
{
  stlp_std::ioinfo **v1; // edi
  int v2; // esi
  char *v3; // eax

  if ( fh < 0
    || fh >= _nhandle
    || (v1 = &__pioinfo[fh >> 5], v2 = (fh & 0x1F) << 6, v3 = (char *)*v1 + v2, (v3[4] & 1) == 0)
    || *(_DWORD *)v3 == -1 )
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
  else
  {
    if ( __app_type == 1 )
    {
      if ( fh )
      {
        if ( fh == 1 )
        {
          SetStdHandle(0xFFFFFFF5, 0);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(0xFFFFFFF4, 0);
        }
      }
      else
      {
        SetStdHandle(0xFFFFFFF6, 0);
      }
    }
    *(int *)((char *)&(*v1)->osfhnd + v2) = -1;
    return 0;
  }
}
