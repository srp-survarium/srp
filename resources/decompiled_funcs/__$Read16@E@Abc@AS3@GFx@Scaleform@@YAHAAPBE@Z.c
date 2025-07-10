int __cdecl Scaleform::GFx::AS3::Abc::Read16<unsigned char>(const unsigned __int8 **cp)
{
  int result; // eax

  result = *(unsigned __int16 *)*cp;
  *cp += 2;
  return result;
}
