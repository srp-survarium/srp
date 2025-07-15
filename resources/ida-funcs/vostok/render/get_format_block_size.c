unsigned int __usercall vostok::render::get_format_block_size@<eax>(int format@<eax>)
{
  int v1; // eax
  int v3; // eax
  int v4; // eax

  if ( format > 34 )
  {
    v3 = format - 44;
    if ( !v3 )
      return 4;
    v4 = v3 - 5;
    if ( v4 && (unsigned int)(v4 - 4) >= 2 )
      return 1;
    else
      return 2;
  }
  else
  {
    if ( format == 34 )
      return 4;
    v1 = format - 2;
    if ( v1 )
    {
      if ( v1 != 8 )
        return 4;
      return 8;
    }
    else
    {
      return 16;
    }
  }
}
