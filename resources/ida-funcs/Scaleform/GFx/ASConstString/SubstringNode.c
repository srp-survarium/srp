Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::SubstringNode(
        Scaleform::GFx::ASConstString *this,
        char *start,
        char *end)
{
  char *v3; // ebp
  char *pData; // ecx
  char *v6; // esi
  __m128i *v7; // ebx
  __m128i *v8; // edi
  unsigned int Char_Advance0; // eax

  v3 = end;
  if ( start == end )
    return &this->pNode->pManager->EmptyStringNode;
  pData = (char *)this->pNode->pData;
  v6 = 0;
  end = pData;
  v7 = (__m128i *)pData;
  v8 = (__m128i *)pData;
  while ( 1 )
  {
    if ( v6 == start )
      v7 = (__m128i *)pData;
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&end);
    pData = end;
    if ( !Char_Advance0 )
      pData = --end;
    if ( ++v6 == v3 )
      break;
    if ( !Char_Advance0 )
    {
      if ( (int)v6 >= (int)v3 )
        goto LABEL_12;
      break;
    }
  }
  v8 = (__m128i *)pData;
LABEL_12:
  if ( v8 < v7 )
    v8 = v7;
  return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, v7, (char *)v8 - (char *)v7);
}
