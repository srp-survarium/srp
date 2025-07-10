void __thiscall Scaleform::HeapMH::AllocEngineMH::Free(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned int ptr,
        bool globalLocked)
{
  int v5; // eax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+8h] [ebp-1Ch] BYREF

  Scaleform::HeapMH::AllocBitSet2MH::Free(&this->Allocator, page, (void *)ptr, &headers, &ptr);
  this->UsedSpace -= ptr;
  v5 = 0;
  if ( headers.Header1 )
    v5 = --headers.Header1->UseCount;
  if ( headers.Header2 )
    v5 = --headers.Header2->UseCount;
  if ( !v5 )
    Scaleform::HeapMH::AllocEngineMH::freePage(this, page, globalLocked);
  --this->UseCount;
}
