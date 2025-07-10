int __cdecl ssleay_rand_pseudo_bytes()
{
  int result; // eax
  unsigned int v1; // eax

  result = RAND_bytes();
  if ( !result )
  {
    v1 = ERR_peek_error();
    if ( (v1 & 0xFF000000) == 0x24000000 && (v1 & 0xFFF) == 0x64 )
      ERR_clear_error();
    return 0;
  }
  return result;
}
