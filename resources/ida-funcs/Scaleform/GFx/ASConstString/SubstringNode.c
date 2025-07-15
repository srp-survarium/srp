Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::SubstringNode(
        Scaleform::GFx::ASConstString *this,
        const char *start,
        const char *end)
{
  int v3; // ebp
  const char *pData; // ecx
  int v6; // esi
  char *v7; // ebx
  char *v8; // edi
  unsigned int v9; // eax

  v3 = (int)end;
  if ( start == end )
    return &this->pNode->pManager->EmptyStringNode;
  pData = this->pNode->pData;
  v6 = 0;
  end = pData;
  v7 = (char *)pData;
  v8 = (char *)pData;
  while ( 1 )
  {
    if ( (const char *)v6 == start )
      v7 = (char *)pData;
    v9 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&end);
    pData = end;
    if ( !v9 )
      pData = --end;
    if ( ++v6 == v3 )
      break;
    if ( !v9 )
    {
      if ( v6 >= v3 )
        goto LABEL_12;
      break;
    }
  }
  v8 = (char *)pData;
LABEL_12:
  if ( v8 < v7 )
    v8 = v7;
  return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, v7, v8 - v7);
}
