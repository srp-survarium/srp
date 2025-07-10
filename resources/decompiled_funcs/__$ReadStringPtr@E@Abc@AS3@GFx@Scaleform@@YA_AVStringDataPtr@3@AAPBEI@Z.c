Scaleform::StringDataPtr *__cdecl Scaleform::GFx::AS3::Abc::ReadStringPtr<unsigned char>(
        Scaleform::StringDataPtr *result,
        const char **cp,
        unsigned int size)
{
  const char *v3; // ecx
  Scaleform::StringDataPtr *v4; // eax

  v3 = *cp;
  v4 = result;
  result->pStr = *cp;
  result->Size = size;
  *cp = &v3[size];
  return v4;
}
