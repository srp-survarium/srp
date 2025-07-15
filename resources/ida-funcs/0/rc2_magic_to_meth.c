int __cdecl rc2_magic_to_meth(int i)
{
  switch ( i )
  {
    case 58:
      return 128;
    case 120:
      return 64;
    case 160:
      return 40;
  }
  ERR_put_error(6u, 109, 108, ".\\crypto\\evp\\e_rc2.c", 163);
  return 0;
}
