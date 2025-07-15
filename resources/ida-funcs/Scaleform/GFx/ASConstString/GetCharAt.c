unsigned int __thiscall Scaleform::GFx::ASConstString::GetCharAt(Scaleform::GFx::ASConstString *this, char *index)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int result; // eax
  char *v4; // esi

  pNode = this->pNode;
  if ( (this->pNode->HashFlags & 0x8000000) != 0 )
    return pNode->pData[(unsigned int)index];
  v4 = index;
  index = (char *)pNode->pData;
  do
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&index);
    --v4;
  }
  while ( (int)v4 >= 0 );
  return result;
}
