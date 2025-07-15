void __fastcall vostok::memory::reader::skip_string(vostok::memory::reader *this, _DWORD *a2)
{
  int v2; // ecx
  _BYTE *i; // eax

  v2 = *a2 + a2[2];
  for ( i = (_BYTE *)a2[1]; i != (_BYTE *)v2; ++i )
  {
    if ( !*i )
      break;
  }
  a2[1] = i + 1;
}
