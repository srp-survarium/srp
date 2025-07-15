void __cdecl floor1_free_look(unsigned __int8 *i)
{
  if ( i )
  {
    memset((int)i, 0, 0x520u);
    ogg_free_impl(i);
  }
}
