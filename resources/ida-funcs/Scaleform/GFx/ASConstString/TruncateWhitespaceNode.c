Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::TruncateWhitespaceNode(
        Scaleform::GFx::ASConstString *this)
{
  const char *pData; // eax
  __m128i *pStr; // eax
  Scaleform::StringDataPtr v5; // [esp+4h] [ebp-10h] BYREF
  Scaleform::StringDataPtr result; // [esp+Ch] [ebp-8h] BYREF

  pData = this->pNode->pData;
  v5.Size = this->pNode->Size;
  v5.pStr = pData;
  Scaleform::StringDataPtr::GetTruncateWhitespace(&v5, &result);
  pStr = (__m128i *)result.pStr;
  if ( v5.pStr == result.pStr && v5.Size == result.Size )
    return this->pNode;
  if ( result.pStr && v5.pStr )
  {
    if ( !strncmp(result.pStr, v5.pStr, v5.Size) )
      return this->pNode;
    pStr = (__m128i *)result.pStr;
  }
  return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pStr, result.Size);
}
