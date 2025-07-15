BOOL __cdecl Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::IsUTF8BOM(const char *str)
{
  return *str == -17 && str[1] == -69 && str[2] == -65;
}
