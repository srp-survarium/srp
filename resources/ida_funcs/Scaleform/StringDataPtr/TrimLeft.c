Scaleform::StringDataPtr *__thiscall Scaleform::StringDataPtr::TrimLeft(
        Scaleform::StringDataPtr *this,
        unsigned int size)
{
  unsigned int v2; // edx
  Scaleform::StringDataPtr *result; // eax
  unsigned int v4; // ecx

  v2 = size;
  result = this;
  v4 = this->Size;
  if ( v4 < size )
    v2 = v4;
  result->pStr += v2;
  result->Size = v4 - v2;
  return result;
}
