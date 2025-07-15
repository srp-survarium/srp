int __usercall ssleay_rand_pseudo_bytes@<eax>(int a1@<ebx>, int a2@<edi>)
{
  int result; // eax
  unsigned int v3; // eax

  result = RAND_bytes(a2);
  if ( !result )
  {
    v3 = ERR_peek_error();
    if ( (v3 & 0xFF000000) == 0x24000000 && (v3 & 0xFFF) == 0x64 )
      ERR_clear_error(a1);
    return 0;
  }
  return result;
}
