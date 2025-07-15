Scaleform::StringDataPtr *__thiscall Scaleform::SwitchFormatter::GetResult(
        Scaleform::SwitchFormatter *this,
        Scaleform::StringDataPtr *result)
{
  const char *pStr; // edx
  Scaleform::StringDataPtr *v3; // eax
  unsigned int Size; // ecx

  pStr = this->StrValue.pStr;
  v3 = result;
  Size = this->StrValue.Size;
  result->pStr = pStr;
  result->Size = Size;
  return v3;
}
