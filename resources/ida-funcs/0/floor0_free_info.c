void __cdecl floor0_free_info(unsigned __int8 *i)
{
  if ( i )
  {
    memset((int)i, 0, 0x60u);
    ogg_free_impl(i);
  }
}
