unsigned int __thiscall Scaleform::GFx::ASConstString::GetFirstCharAt(
        Scaleform::GFx::ASConstString *this,
        char *index,
        char **offset)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *v4; // edi
  char *v5; // esi
  unsigned int result; // eax

  pNode = this->pNode;
  v4 = index;
  index = (char *)this->pNode->pData;
  v5 = &index[pNode->Size];
  while ( 1 )
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&index);
    --v4;
    if ( index >= v5 )
      break;
    if ( (int)v4 < 0 )
    {
      *offset = index;
      return result;
    }
  }
  return result;
}
