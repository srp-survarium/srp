unsigned int __thiscall Scaleform::GFx::ASConstString::GetLength(Scaleform::GFx::ASConstString *this)
{
  unsigned int Size; // esi
  unsigned int result; // eax

  Size = this->pNode->Size;
  if ( (this->pNode->HashFlags & 0x8000000) != 0 )
    return this->pNode->Size;
  result = Scaleform::UTF8Util::GetLength(this->pNode->pData, this->pNode->Size);
  if ( result == Size )
    this->pNode->HashFlags |= 0x8000000u;
  return result;
}
