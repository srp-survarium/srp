int __cdecl png_default_flush(int a1)
{
  int result; // eax

  if ( a1 )
    return fflush(*(_iobuf **)(a1 + 88));
  return result;
}
