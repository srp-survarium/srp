void __thiscall Scaleform::GFx::ASString::operator=<Scaleform::String>(
        Scaleform::GFx::ASString *this,
        const Scaleform::String *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(str->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->pNode = StringNode;
}


void __thiscall Scaleform::GFx::ASString::operator=(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = src->pNode;
  ++src->pNode->RefCount;
  v4 = this->pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->pNode = pNode;
}


void __thiscall Scaleform::GFx::ASString::operator=(Scaleform::GFx::ASString *this, char *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pstr, strlen(pstr));
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    pLower = pNode->pLower;
    if ( pLower != pNode && pLower )
      Scaleform::GFx::ASStringNode::Release(pLower);
    p_StringSet = &pNode->pManager->StringSet;
    pstr = (char *)pNode;
    Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
      p_StringSet,
      (Scaleform::GFx::ASStringNode *const *)&pstr);
    Scaleform::GFx::ASStringManager::FreeStringNode(pNode->pManager, pNode);
  }
  this->pNode = StringNode;
}


bool __thiscall Scaleform::GFx::ASString::operator==(Scaleform::GFx::ASString *this, const char *str)
{
  return strcmp(this->pNode->pData, str) == 0;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::operator+(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)this->pNode->pData,
                 this->pNode->Size,
                 (char *)str->pNode->pData,
                 (Scaleform::GFx::ASStringNode *)str->pNode->Size);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::operator+(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        char *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)this->pNode->pData,
                 this->pNode->Size,
                 pstr,
                 (Scaleform::GFx::ASStringNode *)strlen(pstr));
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


bool __thiscall Scaleform::GFx::ASString::operator<(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v3; // ecx
  int v4; // eax
  unsigned int Size; // ebx
  unsigned int v6; // edi
  unsigned int v7; // esi
  const char *pData; // ecx
  const char *v9; // edx
  int v10; // eax

  pNode = this->pNode;
  v3 = str->pNode;
  if ( pNode == str->pNode )
  {
    LOBYTE(v4) = 0;
    return v4;
  }
  Size = pNode->Size;
  v6 = v3->Size;
  v7 = Size;
  if ( Size >= v6 )
    v7 = v3->Size;
  pData = v3->pData;
  v9 = pNode->pData;
  if ( v7 < 4 )
  {
LABEL_8:
    if ( !v7 )
      goto LABEL_17;
  }
  else
  {
    while ( *(_DWORD *)v9 == *(_DWORD *)pData )
    {
      v7 -= 4;
      pData += 4;
      v9 += 4;
      if ( v7 < 4 )
        goto LABEL_8;
    }
  }
  v10 = *(unsigned __int8 *)v9 - *(unsigned __int8 *)pData;
  if ( v10 )
    goto LABEL_16;
  if ( v7 <= 1 )
    goto LABEL_17;
  v10 = *((unsigned __int8 *)v9 + 1) - *((unsigned __int8 *)pData + 1);
  if ( v10 )
    goto LABEL_16;
  if ( v7 <= 2 )
    goto LABEL_17;
  v10 = *((unsigned __int8 *)v9 + 2) - *((unsigned __int8 *)pData + 2);
  if ( v10 )
  {
LABEL_16:
    v4 = (v10 >> 31) | 1;
    goto LABEL_18;
  }
  if ( v7 > 3 )
  {
    v10 = *((unsigned __int8 *)v9 + 3) - *((unsigned __int8 *)pData + 3);
    goto LABEL_16;
  }
LABEL_17:
  v4 = 0;
LABEL_18:
  if ( v4 )
    LOBYTE(v4) = v4 < 0;
  else
    return Size < v6;
  return v4;
}


bool __thiscall Scaleform::GFx::ASString::operator>(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str)
{
  return this->pNode != str->pNode && !Scaleform::GFx::ASString::operator<(this, str);
}


void __thiscall Scaleform::GFx::ASString::operator+=(Scaleform::GFx::ASString *this, char *str)
{
  Scaleform::GFx::ASString::Append(this, str, (Scaleform::GFx::ASStringNode *)strlen(str));
}
