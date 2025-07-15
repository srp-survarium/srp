void __thiscall Scaleform::GFx::XML::DOMStringManager::~DOMStringManager(Scaleform::GFx::XML::DOMStringManager *this)
{
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *pStringNodePages; // ebx
  Scaleform::GFx::XML::DOMStringManager::StringNodePage *v3; // edi
  int v4; // ebp
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *pData; // eax
  Scaleform::GFx::XML::DOMStringManager::TextPage *pTextBufferPages; // eax
  void *pMem; // edx
  unsigned int SizeMask; // edx
  unsigned int v9; // eax

  while ( this->pStringNodePages )
  {
    pStringNodePages = this->pStringNodePages;
    this->pStringNodePages = pStringNodePages->pNext;
    v3 = pStringNodePages;
    v4 = 127;
    do
    {
      pData = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)v3->Nodes[0].pData;
      if ( v3->Nodes[0].pData )
      {
        if ( v3->Nodes[0].Size >= 0xC )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3->Nodes[0].pData);
        }
        else
        {
          pData->pNextAlloc = this->pFreeTextBuffers;
          this->pFreeTextBuffers = pData;
        }
      }
      v3 = (Scaleform::GFx::XML::DOMStringManager::StringNodePage *)((char *)v3 + 20);
      --v4;
    }
    while ( v4 );
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pStringNodePages);
  }
  while ( this->pTextBufferPages )
  {
    pTextBufferPages = this->pTextBufferPages;
    pMem = pTextBufferPages->pMem;
    this->pTextBufferPages = pTextBufferPages->pNext;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pMem);
  }
  if ( this->StringSet.pTable )
  {
    SizeMask = this->StringSet.pTable->SizeMask;
    v9 = 0;
    do
    {
      if ( this->StringSet.pTable[v9 + 1].EntryCount != -2 )
        this->StringSet.pTable[v9 + 1].EntryCount = -2;
      ++v9;
    }
    while ( v9 <= SizeMask );
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->StringSet.pTable);
    this->StringSet.pTable = 0;
  }
}
