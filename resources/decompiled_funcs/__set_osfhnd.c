int __cdecl _set_osfhnd(int fh, void *value)
{
  stlp_std::ioinfo **v2; // edi
  int v3; // esi

  if ( fh >= 0
    && fh < _nhandle
    && (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, *(int *)((char *)&(*v2)->osfhnd + v3) == -1) )
  {
    if ( __app_type == 1 )
    {
      if ( fh )
      {
        if ( fh == 1 )
        {
          SetStdHandle(0xFFFFFFF5, value);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(0xFFFFFFF4, value);
        }
      }
      else
      {
        SetStdHandle(0xFFFFFFF6, value);
      }
    }
    *(int *)((char *)&(*v2)->osfhnd + v3) = (int)value;
    return 0;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}
