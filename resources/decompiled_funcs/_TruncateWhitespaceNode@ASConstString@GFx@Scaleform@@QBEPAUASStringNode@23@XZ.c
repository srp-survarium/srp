Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::TruncateWhitespaceNode(
        Scaleform::GFx::ASConstString *this)
{
  const char *pData; // eax
  char *pStr; // eax
  Scaleform::StringDataPtr s; // [esp+4h] [ebp-10h] BYREF
  Scaleform::StringDataPtr ts; // [esp+Ch] [ebp-8h] BYREF

  pData = this->pNode->pData;
  s.Size = this->pNode->Size;
  s.pStr = pData;
  Scaleform::StringDataPtr::GetTruncateWhitespace(&s, &ts);
  pStr = (char *)ts.pStr;
  if ( s.pStr == ts.pStr && s.Size == ts.Size )
    return this->pNode;
  if ( ts.pStr && s.pStr )
  {
    if ( !strncmp(ts.pStr, s.pStr, s.Size) )
      return this->pNode;
    pStr = (char *)ts.pStr;
  }
  return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pStr, ts.Size);
}
