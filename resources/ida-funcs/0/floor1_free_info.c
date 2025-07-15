void __cdecl floor1_free_info(unsigned __int8 *i)
{
  if ( i )
  {
    memset((int)i, 0, 0x460u);
    ogg_free_impl(i);
  }
}
