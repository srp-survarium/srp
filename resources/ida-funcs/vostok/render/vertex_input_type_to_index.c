unsigned int __fastcall vostok::render::vertex_input_type_to_index(int type)
{
  int v1; // ecx
  int v2; // ecx
  unsigned int result; // eax
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx

  if ( type <= 128 )
  {
    if ( type == 128 )
      return 7;
    v1 = type - 1;
    if ( !v1 )
      return 0;
    v2 = v1 - 1;
    if ( !v2 )
      return 1;
    result = 2;
    v4 = v2 - 2;
    if ( !v4 )
      return result;
    result = 4;
    v5 = v4 - 4;
    if ( !v5 )
      return 3;
    v6 = v5 - 8;
    if ( !v6 )
      return result;
    v7 = v6 - 16;
    if ( !v7 )
      return 5;
    if ( v7 == 32 )
      return 6;
    return 0x4000;
  }
  switch ( type )
  {
    case 0x100:
      return 8;
    case 0x200:
      return 9;
    case 0x400:
      return 10;
    case 0x800:
      return 11;
    case 0x1000:
      return 12;
    case 0x2000:
      return 13;
  }
  if ( type != 0x4000 )
    return 0x4000;
  return 14;
}
