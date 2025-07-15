void __thiscall Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::RootMH *this, Scaleform::HeapMH::PageMH *page)
{
  Scaleform::HeapMH::MagicHeader *Header1; // eax
  Scaleform::HeapMH::MagicHeader *Header2; // eax
  unsigned __int8 *Start; // eax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+8h] [ebp-1Ch] BYREF

  Scaleform::HeapMH::GetMagicHeaders((unsigned int)page->Start, &headers);
  Header1 = headers.Header1;
  if ( headers.Header1 )
  {
    headers.Header1->Magic = 0;
    Header1->UseCount = 0;
    Header1->Index = 0;
    Header1->DebugHeader = 0;
  }
  Header2 = headers.Header2;
  if ( headers.Header2 )
  {
    headers.Header2->Magic = 0;
    Header2->UseCount = 0;
    Header2->Index = 0;
    Header2->DebugHeader = 0;
  }
  Start = page->Start;
  page->Start = 0;
  page->pHeap = 0;
  this->pSysAlloc->Free(this->pSysAlloc, Start, 4096u, 4u);
  page->pPrev = this->FreePages.Root.pPrev;
  page->pNext = (Scaleform::HeapMH::PageMH *)&this->FreePages;
  this->FreePages.Root.pPrev->pNext = page;
  this->FreePages.Root.pPrev = page;
}
