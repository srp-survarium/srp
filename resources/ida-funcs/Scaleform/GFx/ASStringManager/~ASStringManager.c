void __thiscall Scaleform::GFx::ASStringManager::~ASStringManager(Scaleform::GFx::ASStringManager *this)
{
  unsigned int v2; // ebx
  Scaleform::GFx::ASStringManager::StringNodePage *pStringNodePages; // ebp
  Scaleform::GFx::ASStringManager::StringNodePage *v4; // esi
  char *v5; // eax
  Scaleform::GFx::ASStringManager::TextPage::Entry *pData; // eax
  Scaleform::GFx::ASStringManager::TextPage *pTextBufferPages; // eax
  void *pMem; // edx
  Scaleform::GFx::LogState *pObject; // eax
  char *v10; // eax
  volatile LONG *v11; // esi
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // ecx
  unsigned int SizeMask; // edx
  unsigned int v15; // eax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *v16; // ecx
  bool v17; // zf
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *v18; // ecx
  int v19; // [esp+Ch] [ebp-1Ch]
  Scaleform::StringBuffer leakReport; // [esp+10h] [ebp-18h] BYREF

  this->__vftable = (Scaleform::GFx::ASStringManager_vtbl *)&Scaleform::GFx::ASStringManager::`vftable';
  Scaleform::StringBuffer::StringBuffer(&leakReport, Scaleform::Memory::pGlobalHeap);
  v2 = 0;
  while ( this->pStringNodePages )
  {
    pStringNodePages = this->pStringNodePages;
    this->pStringNodePages = pStringNodePages->pNext;
    v4 = pStringNodePages;
    v19 = 127;
    do
    {
      if ( v4->Nodes[0].pData )
      {
        if ( v2 < 0x10 )
        {
          v5 = ", '";
          if ( !v2 )
            v5 = "'";
          Scaleform::StringBuffer::AppendString(&leakReport, v5, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(&leakReport, (char *)v4->Nodes[0].pData, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(&leakReport, "'", 0xFFFFFFFF);
        }
        ++v2;
        if ( (v4->Nodes[0].HashFlags & 0x40000000) == 0 )
        {
          pData = (Scaleform::GFx::ASStringManager::TextPage::Entry *)v4->Nodes[0].pData;
          if ( v4->Nodes[0].Size >= 0xC )
          {
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4->Nodes[0].pData);
          }
          else
          {
            pData->pNextAlloc = this->pFreeTextBuffers;
            this->pFreeTextBuffers = pData;
          }
        }
      }
      v4 = (Scaleform::GFx::ASStringManager::StringNodePage *)((char *)v4 + 24);
      --v19;
    }
    while ( v19 );
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pStringNodePages);
  }
  while ( this->pTextBufferPages )
  {
    pTextBufferPages = this->pTextBufferPages;
    pMem = pTextBufferPages->pMem;
    this->pTextBufferPages = pTextBufferPages->pNext;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pMem);
  }
  if ( v2 )
  {
    pObject = this->pLog.pObject;
    if ( pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "ActionScript Memory leaks in movie '%s', including %d string nodes",
        (const char *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 8),
        v2);
      v10 = leakReport.pData;
      if ( !leakReport.pData )
        v10 = (char *)&buf;
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &this->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Leaked string content: %s\n",
        v10);
    }
  }
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&leakReport);
  v11 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v11 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v11);
  v12 = (Scaleform::RefCountVImpl *)this->pLog.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  pTable = this->StringSet.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v15 = 0;
    do
    {
      v16 = this->StringSet.pTable;
      v17 = v16[v15 + 1].EntryCount == -2;
      v18 = &v16[v15 + 1];
      if ( !v17 )
        v18->EntryCount = -2;
      ++v15;
    }
    while ( v15 <= SizeMask );
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->StringSet.pTable);
    this->StringSet.pTable = 0;
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
