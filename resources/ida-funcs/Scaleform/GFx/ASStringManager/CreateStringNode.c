Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        char *pstr)
{
  if ( pstr )
    return Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr, strlen(pstr));
  else
    return &this->EmptyStringNode;
}


Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        char *pstr1,
        unsigned int l1,
        char *pstr2,
        Scaleform::GFx::ASStringNode *l2)
{
  unsigned int v6; // esi
  Scaleform::GFx::ASStringManager *v7; // ebx
  Scaleform::GFx::ASStringManager::TextPage::Entry *pFreeTextBuffers; // eax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v9; // edi
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ebx
  unsigned int v11; // ebp
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > v12; // eax
  unsigned int v13; // ebp
  signed int v14; // eax
  unsigned int SizeMask; // ebx
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // esi
  Scaleform::GFx::ASStringKey key; // [esp+14h] [ebp-Ch] BYREF
  unsigned int length; // [esp+28h] [ebp+8h]

  v6 = (unsigned int)l2 + l1;
  v7 = this;
  length = v6;
  if ( v6 >= 0xC )
  {
    pFreeTextBuffers = (Scaleform::GFx::ASStringManager::TextPage::Entry *)this->pHeap->Alloc(this->pHeap, v6 + 1, 0);
    goto LABEL_7;
  }
  if ( !this->pFreeTextBuffers )
    Scaleform::GFx::ASStringManager::AllocateTextBuffers(this);
  pFreeTextBuffers = v7->pFreeTextBuffers;
  v9 = 0;
  if ( pFreeTextBuffers )
  {
    v7->pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
LABEL_7:
    v9 = pFreeTextBuffers;
  }
  if ( !v9 )
    return &v7->EmptyStringNode;
  if ( pstr1 && l1 )
    memcpy((unsigned __int8 *)v9, (unsigned __int8 *)pstr1, l1);
  if ( pstr2 && l2 )
    memcpy((unsigned __int8 *)v9 + l1, (unsigned __int8 *)pstr2, (unsigned int)l2);
  v9->Buff[v6] = 0;
  key.pStr = (const char *)v9;
  p_StringSet = &v7->StringSet;
  v11 = Scaleform::String::BernsteinHashFunctionCIS((char *)v9, v6, 0x1505u);
  v12.pTable = p_StringSet->pTable;
  v13 = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v11;
  key.HashValue = v13;
  key.Length = v6;
  if ( !v12.pTable
    || (v14 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
                p_StringSet,
                &key,
                v13 & v12.pTable->SizeMask),
        v14 < 0) )
  {
    if ( !this->pFreeStringNodes )
      Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
    pFreeStringNodes = this->pFreeStringNodes;
    if ( pFreeStringNodes )
      this->pFreeStringNodes = pFreeStringNodes->pLower;
    l2 = pFreeStringNodes;
    if ( pFreeStringNodes )
    {
      pFreeStringNodes->RefCount = 0;
      pFreeStringNodes->Size = length;
      pFreeStringNodes->pData = (const char *)v9;
      pFreeStringNodes->HashFlags = v13;
      pFreeStringNodes->pLower = 0;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        p_StringSet,
        p_StringSet,
        &l2,
        pFreeStringNodes->HashFlags);
      return pFreeStringNodes;
    }
    if ( length < 0xC )
    {
      v9->pNextAlloc = this->pFreeTextBuffers;
      this->pFreeTextBuffers = v9;
      return (Scaleform::GFx::ASStringNode *)&p_StringSet[8];
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    v7 = this;
    return &v7->EmptyStringNode;
  }
  SizeMask = p_StringSet->pTable[v14 + 1].SizeMask;
  if ( v6 >= 0xC )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  else
  {
    v9->pNextAlloc = this->pFreeTextBuffers;
    this->pFreeTextBuffers = v9;
  }
  return (Scaleform::GFx::ASStringNode *)SizeMask;
}


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


Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const wchar_t *pwstr,
        int len)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  void *v5; // esi
  Scaleform::String strBuff; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&strBuff);
  Scaleform::String::AppendString(&strBuff, pwstr, len);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this,
                 (char *)((strBuff.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(strBuff.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  v5 = (void *)(strBuff.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((strBuff.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  return StringNode;
}
