void __thiscall Scaleform::GFx::XML::DOMStringManager::AllocateTextBuffers(Scaleform::GFx::XML::DOMStringManager *this)
{
  void *v2; // eax
  Scaleform::GFx::XML::DOMStringManager::TextPage *v3; // ecx
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v4; // eax
  int v5; // edi
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v6; // edx
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v7; // ecx

  v2 = this->pHeap->Alloc(this->pHeap, 2032, 0);
  v3 = (Scaleform::GFx::XML::DOMStringManager::TextPage *)(((unsigned int)v2 + 7) & 0xFFFFFFF8);
  if ( v3 )
  {
    v3->pMem = v2;
    v3->pNext = this->pTextBufferPages;
    this->pTextBufferPages = v3;
    v4 = &v3->Entries[2];
    v5 = 28;
    do
    {
      v4[-2].pNextAlloc = this->pFreeTextBuffers;
      v4[-1].pNextAlloc = v4 - 2;
      v4->pNextAlloc = v4 - 1;
      v4[1].pNextAlloc = v4;
      v6 = v4 + 2;
      v4[2].pNextAlloc = v4 + 1;
      v7 = v4 + 3;
      v4 += 6;
      --v5;
      v7->pNextAlloc = v6;
      this->pFreeTextBuffers = v7;
    }
    while ( v5 );
  }
}
