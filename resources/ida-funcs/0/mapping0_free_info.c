void __cdecl mapping0_free_info(unsigned __int8 *i)
{
  if ( i )
  {
    memset((int)i, 0, 0xC88u);
    ogg_free_impl(i);
  }
}
