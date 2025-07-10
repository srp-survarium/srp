Scaleform::StringDataPtr *__thiscall Scaleform::BoolFormatter::GetResult(
        Scaleform::BoolFormatter *this,
        Scaleform::StringDataPtr *result)
{
  const char *pStr; // edx
  Scaleform::StringDataPtr *v3; // eax
  unsigned int Size; // ecx

  pStr = this->result.pStr;
  v3 = result;
  Size = this->result.Size;
  result->pStr = pStr;
  result->Size = Size;
  return v3;
}
