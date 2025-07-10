Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        char *pstr,
        unsigned int length)
{
  unsigned int v4; // ebx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // eax
  unsigned int v6; // ebx
  signed int v7; // eax
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // esi
  Scaleform::GFx::ASStringNode *pnode; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringKey key; // [esp+Ch] [ebp-Ch] BYREF

  if ( !pstr || !length )
    return &this->EmptyStringNode;
  key.pStr = pstr;
  v4 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505u);
  pTable = this->StringSet.pTable;
  v6 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v4;
  key.HashValue = v6;
  key.Length = length;
  if ( pTable )
  {
    v7 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
           &this->StringSet,
           &key,
           v6 & pTable->SizeMask);
    if ( v7 >= 0 )
      return (Scaleform::GFx::ASStringNode *)this->StringSet.pTable[v7 + 1].SizeMask;
  }
  if ( !this->pFreeStringNodes )
    Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
  pFreeStringNodes = this->pFreeStringNodes;
  if ( pFreeStringNodes )
    this->pFreeStringNodes = pFreeStringNodes->pLower;
  pnode = pFreeStringNodes;
  if ( pFreeStringNodes )
  {
    pFreeStringNodes->pData = (const char *)Scaleform::GFx::ASStringManager::AllocTextBuffer(this, pstr, length);
    if ( pFreeStringNodes->pData )
    {
      pFreeStringNodes->RefCount = 0;
      pFreeStringNodes->Size = length;
      pFreeStringNodes->HashFlags = v6;
      pFreeStringNodes->pLower = 0;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        &this->StringSet,
        &this->StringSet,
        &pnode,
        pFreeStringNodes->HashFlags);
      return pFreeStringNodes;
    }
    Scaleform::GFx::ASStringManager::FreeStringNode(this, pFreeStringNodes);
  }
  return &this->EmptyStringNode;
}
