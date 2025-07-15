int __cdecl Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(const unsigned __int8 **cp)
{
  char v1; // dl
  int result; // eax
  unsigned int v3; // ecx
  char v4; // bl
  int v5; // edx

  v1 = *(*cp)++;
  result = v1 & 0x7F;
  v3 = 7;
  if ( v1 < 0 )
  {
    do
    {
      if ( v3 >= 0x20 )
        break;
      v4 = *(*cp)++;
      v5 = (v4 & 0x7F) << v3;
      v3 += 7;
      result |= v5;
    }
    while ( v4 < 0 );
  }
  return result;
}


int __cdecl Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(const unsigned __int8 *data, unsigned int *cp)
{
  char v2; // dl
  int result; // eax
  unsigned int v4; // ecx
  char v5; // bl
  int v6; // edx

  v2 = data[(*cp)++];
  result = v2 & 0x7F;
  v4 = 7;
  if ( v2 < 0 )
  {
    do
    {
      if ( v4 >= 0x20 )
        break;
      v5 = data[(*cp)++];
      v6 = (v5 & 0x7F) << v4;
      v4 += 7;
      result |= v6;
    }
    while ( v5 < 0 );
  }
  return result;
}
