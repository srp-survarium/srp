Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateConstStringNode(
        Scaleform::GFx::ASStringManager *this,
        char *pstr,
        unsigned int length,
        unsigned int stringFlags)
{
  unsigned int v5; // edi
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // eax
  unsigned int v7; // edi
  signed int v8; // eax
  Scaleform::GFx::ASStringNode *result; // eax
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // esi
  Scaleform::GFx::ASStringNode *pnode; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringKey key; // [esp+14h] [ebp-Ch] BYREF

  key.pStr = pstr;
  v5 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505u);
  pTable = this->StringSet.pTable;
  v7 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v5;
  key.HashValue = v7;
  key.Length = length;
  if ( pTable
    && (v8 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
               &this->StringSet,
               &key,
               v7 & pTable->SizeMask),
        v8 >= 0) )
  {
    result = (Scaleform::GFx::ASStringNode *)this->StringSet.pTable[v8 + 1].SizeMask;
    result->HashFlags |= stringFlags;
  }
  else
  {
    if ( !this->pFreeStringNodes )
      Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
    pFreeStringNodes = this->pFreeStringNodes;
    if ( pFreeStringNodes )
      this->pFreeStringNodes = pFreeStringNodes->pLower;
    pnode = pFreeStringNodes;
    if ( pFreeStringNodes )
    {
      pFreeStringNodes->RefCount = 0;
      pFreeStringNodes->Size = length;
      pFreeStringNodes->pData = pstr;
      pFreeStringNodes->HashFlags = stringFlags | v7 | 0x40000000;
      pFreeStringNodes->pLower = 0;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        &this->StringSet,
        &this->StringSet,
        &pnode,
        pFreeStringNodes->HashFlags);
      return pFreeStringNodes;
    }
    else
    {
      return &this->EmptyStringNode;
    }
  }
  return result;
}
