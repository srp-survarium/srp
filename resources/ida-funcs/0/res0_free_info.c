void __cdecl res0_free_info(unsigned __int8 *i)
{
  if ( i )
  {
    memset((int)i, 0, 0xB18u);
    ogg_free_impl(i);
  }
}
