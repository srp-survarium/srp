const survarium::flash_text *__cdecl _wincmdln()
{
  BOOL v0; // edi
  const survarium::flash_text *v1; // esi
  unsigned __int8 text_impl; // al

  v0 = 0;
  if ( !__mbctype_initialized )
    __initmbctable();
  v1 = (const survarium::flash_text *)_acmdln;
  if ( !_acmdln )
    v1 = &buf;
  while ( 1 )
  {
    text_impl = (unsigned __int8)v1->text_impl;
    if ( LOBYTE(v1->text_impl) <= 0x20u )
    {
      if ( !text_impl )
        return v1;
      if ( !v0 )
        break;
    }
    if ( text_impl == 34 )
      v0 = !v0;
    if ( _ismbblead(text_impl) )
      v1 = (const survarium::flash_text *)((char *)v1 + 1);
    v1 = (const survarium::flash_text *)((char *)v1 + 1);
  }
  while ( LOBYTE(v1->text_impl) && LOBYTE(v1->text_impl) <= 0x20u )
    v1 = (const survarium::flash_text *)((char *)v1 + 1);
  return v1;
}
