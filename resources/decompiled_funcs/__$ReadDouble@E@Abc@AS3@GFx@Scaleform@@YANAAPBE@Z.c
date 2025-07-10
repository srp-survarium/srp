double __cdecl Scaleform::GFx::AS3::Abc::ReadDouble<unsigned char>(const unsigned __int8 **cp)
{
  double w; // [esp+4h] [ebp-8h]

  LODWORD(w) = **cp | (((*cp)[1] | (*((unsigned __int16 *)*cp + 1) << 8)) << 8);
  HIDWORD(w) = (*cp)[4] | (((*cp)[5] | (((*cp)[6] | ((*cp)[7] << 8)) << 8)) << 8);
  *cp += 8;
  return w;
}
