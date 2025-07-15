void __usercall OPENSSL_showfatal(unsigned int a1@<edi>, unsigned int a2@<esi>, char *fmta, ...)
{
  HANDLE StdHandle; // eax
  _iobuf *v4; // eax
  HANDLE v5; // esi
  LPCSTR Strings; // [esp+0h] [ebp-108h] BYREF
  char string[256]; // [esp+4h] [ebp-104h] BYREF
  va_list ap; // [esp+110h] [ebp+8h] BYREF

  va_start(ap, fmta);
  StdHandle = GetStdHandle(0xFFFFFFF4);
  if ( StdHandle && GetFileType(StdHandle) )
  {
    v4 = __iob_func();
    vfprintf(v4 + 2, fmta, ap);
  }
  else
  {
    _vsnprintf(a1, a2, string, 0xFFu, fmta, ap);
    string[255] = 0;
    if ( GetVersion() >= 0x80000000 || OPENSSL_isservice() <= 0 )
    {
      MessageBoxA(0, string, "OpenSSL: FATAL", 0x10u);
    }
    else
    {
      v5 = RegisterEventSourceA(0, "OPENSSL");
      Strings = string;
      ReportEventA(v5, 1u, 0, 0, 0, 1u, 0, &Strings, 0);
      DeregisterEventSource(v5);
    }
  }
}
