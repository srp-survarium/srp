Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        __m128i *pstr)
{
  if ( pstr )
    return Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr, strlen(pstr->m128i_i8));
  else
    return &this->EmptyStringNode;
}


Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const __m128i *pstr1,
        unsigned int l1,
        const __m128i *pstr2,
        Scaleform::GFx::ASStringNode *l2)
{
  char *v6; // esi
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
  Scaleform::GFx::ASStringKey v19; // [esp+14h] [ebp-Ch] BYREF
  unsigned int count; // [esp+28h] [ebp+8h]

  v6 = (char *)l2 + l1;
  v7 = this;
  count = (unsigned int)v6;
  if ( (unsigned int)v6 >= 0xC )
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
    memcpy((int)v9, pstr1, l1);
  if ( pstr2 && l2 )
    memcpy((int)v9 + l1, pstr2, (unsigned int)l2);
  v6[(_DWORD)v9] = 0;
  v19.pStr = (const char *)v9;
  p_StringSet = &v7->StringSet;
  v11 = Scaleform::String::BernsteinHashFunctionCIS((char *)v9, (unsigned int)v6, 0x1505u);
  v12.pTable = p_StringSet->pTable;
  v13 = v11 & 0xFFFFFF;
  v19.HashValue = v13;
  v19.Length = (unsigned int)v6;
  if ( !v12.pTable
    || (v14 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
                p_StringSet,
                &v19,
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
      pFreeStringNodes->Size = count;
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
    if ( count < 0xC )
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
  if ( (unsigned int)v6 >= 0xC )
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
        __m128i *pstr,
        unsigned int length)
{
  unsigned int v4; // ebx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // eax
  unsigned int v6; // ebx
  signed int v7; // eax
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // esi
  Scaleform::GFx::ASStringNode *v10; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringKey v11; // [esp+Ch] [ebp-Ch] BYREF

  if ( !pstr || !length )
    return &this->EmptyStringNode;
  v11.pStr = (const char *)pstr;
  v4 = Scaleform::String::BernsteinHashFunctionCIS(pstr->m128i_i8, length, 0x1505u);
  pTable = this->StringSet.pTable;
  v6 = v4 & 0xFFFFFF;
  v11.HashValue = v6;
  v11.Length = length;
  if ( pTable )
  {
    v7 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
           &this->StringSet,
           &v11,
           v6 & pTable->SizeMask);
    if ( v7 >= 0 )
      return (Scaleform::GFx::ASStringNode *)this->StringSet.pTable[v7 + 1].SizeMask;
  }
  if ( !this->pFreeStringNodes )
    Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
  pFreeStringNodes = this->pFreeStringNodes;
  if ( pFreeStringNodes )
    this->pFreeStringNodes = pFreeStringNodes->pLower;
  v10 = pFreeStringNodes;
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
        &v10,
        pFreeStringNodes->HashFlags);
      return pFreeStringNodes;
    }
    Scaleform::GFx::ASStringManager::FreeStringNode(this, pFreeStringNodes);
  }
  return &this->EmptyStringNode;
}


Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        wchar_t *pwstr,
        int len)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  void *v5; // esi
  Scaleform::String v7; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&v7);
  Scaleform::String::AppendString(&v7, pwstr, len);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this,
                 (__m128i *)((v7.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(v7.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  v5 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  return StringNode;
}
