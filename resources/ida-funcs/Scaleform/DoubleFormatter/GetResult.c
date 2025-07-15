Scaleform::StringDataPtr *__thiscall Scaleform::DoubleFormatter::GetResult(
        Scaleform::DoubleFormatter *this,
        Scaleform::StringDataPtr *result)
{
  unsigned int v3; // ecx
  Scaleform::StringDataPtr *v4; // eax

  v3 = this->GetSize(this);
  v4 = result;
  result->pStr = this->ValueStr;
  result->Size = v3;
  return v4;
}
