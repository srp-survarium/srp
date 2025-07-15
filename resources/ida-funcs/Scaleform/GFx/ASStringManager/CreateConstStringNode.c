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
  Scaleform::GFx::ASStringNode *v11; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringKey v12; // [esp+14h] [ebp-Ch] BYREF

  v12.pStr = pstr;
  v5 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505u);
  pTable = this->StringSet.pTable;
  v7 = v5 & 0xFFFFFF;
  v12.HashValue = v7;
  v12.Length = length;
  if ( pTable
    && (v8 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
               &this->StringSet,
               &v12,
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
    v11 = pFreeStringNodes;
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
        &v11,
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
