int __cdecl Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(const unsigned __int8 *data, unsigned int *cp)
{
  int v2; // esi
  unsigned int v3; // eax
  int v4; // edi
  int v5; // ecx
  int result; // eax

  v2 = data[*cp];
  v3 = *cp + 3;
  v4 = data[v3 - 2];
  v5 = data[v3 - 1];
  *cp = v3;
  result = v2 | ((v4 | (v5 << 8)) << 8);
  if ( (v5 & 0x80u) != 0 )
    return -1 - (result ^ 0xFFFFFF);
  return result;
}
