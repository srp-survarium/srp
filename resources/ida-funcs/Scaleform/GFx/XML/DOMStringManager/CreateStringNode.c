Scaleform::GFx::XML::DOMStringNode *__thiscall Scaleform::GFx::XML::DOMStringManager::CreateStringNode(
        Scaleform::GFx::XML::DOMStringManager *this,
        __m128i *pstr,
        Scaleform::GFx::XML::DOMStringNode *length)
{
  unsigned int v3; // ebp
  unsigned int v5; // ebx
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > >::TableType *pTable; // eax
  unsigned int v7; // ebx
  signed int v8; // eax
  Scaleform::GFx::XML::DOMStringNode *pFreeStringNodes; // edi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v11; // eax
  Scaleform::GFx::XML::DOMStringKey key; // [esp+Ch] [ebp-Ch] BYREF

  v3 = (unsigned int)length;
  key.pStr = (const char *)pstr;
  v5 = Scaleform::String::BernsteinHashFunction(pstr->m128i_i8, (unsigned int)length, 0x1505u);
  pTable = this->StringSet.pTable;
  v7 = v5 & 0xFFFFFF;
  key.HashValue = v7;
  key.Length = v3;
  if ( pTable )
  {
    v8 = Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::findIndexCore<Scaleform::GFx::XML::DOMStringKey>(
           &this->StringSet,
           &key,
           v7 & pTable->SizeMask);
    if ( v8 >= 0 )
      return (Scaleform::GFx::XML::DOMStringNode *)this->StringSet.pTable[v8 + 1].SizeMask;
  }
  if ( !v3 )
    return &this->EmptyStringNode;
  if ( !this->pFreeStringNodes )
    Scaleform::GFx::XML::DOMStringManager::AllocateStringNodes(this);
  pFreeStringNodes = this->pFreeStringNodes;
  if ( pFreeStringNodes )
    this->pFreeStringNodes = pFreeStringNodes->pNextAlloc;
  pFreeStringNodes->pManager = this;
  length = pFreeStringNodes;
  v11 = Scaleform::GFx::XML::DOMStringManager::AllocTextBuffer(this, pstr, v3);
  pFreeStringNodes->pData = (const char *)v11;
  if ( v11 )
  {
    pFreeStringNodes->RefCount = 0;
    pFreeStringNodes->Size = v3;
    pFreeStringNodes->HashFlags = v7;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::add<Scaleform::GFx::XML::DOMStringNode *>(
      &this->StringSet,
      this,
      &length,
      v7);
    return pFreeStringNodes;
  }
  else
  {
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(this, pFreeStringNodes);
    return &this->EmptyStringNode;
  }
}
