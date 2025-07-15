void __usercall OPENSSL_showfatal(int a1@<edi>, int a2@<esi>, int a3@<ebx>, char *fmta, ...)
{
  HANDLE StdHandle; // eax
  _iobuf *v5; // eax
  HANDLE v6; // esi
  LPCSTR Strings; // [esp+0h] [ebp-108h] BYREF
  char Text[256]; // [esp+4h] [ebp-104h] BYREF
  va_list va; // [esp+110h] [ebp+8h] BYREF

  va_start(va, fmta);
  StdHandle = GetStdHandle(0xFFFFFFF4);
  if ( StdHandle && GetFileType(StdHandle) )
  {
    v5 = __iob_func();
    vfprintf(a3, v5 + 2, fmta, va);
  }
  else
  {
    _vsnprintf(a1, a2, Text, 0xFFu, fmta, va);
    Text[255] = 0;
    if ( GetVersion() >= 0x80000000 || OPENSSL_isservice() <= 0 )
    {
      MessageBoxA(0, Text, "OpenSSL: FATAL", 0x10u);
    }
    else
    {
      v6 = RegisterEventSourceA(0, "OPENSSL");
      Strings = Text;
      ReportEventA(v6, 1u, 0, 0, 0, 1u, 0, &Strings, 0);
      DeregisterEventSource(v6);
    }
  }
}
