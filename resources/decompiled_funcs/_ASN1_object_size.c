int __cdecl ASN1_object_size(int constructed, int length, int tag)
{
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int result; // eax

  v3 = tag;
  v4 = length;
  v5 = length + 1;
  if ( tag >= 31 )
  {
    do
    {
      v3 >>= 7;
      ++v5;
    }
    while ( v3 > 0 );
  }
  if ( constructed == 2 )
    return v5 + 3;
  result = v5 + 1;
  if ( length > 127 )
  {
    do
    {
      v4 >>= 8;
      ++result;
    }
    while ( v4 > 0 );
  }
  return result;
}
