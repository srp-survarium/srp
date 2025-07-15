unsigned int __thiscall Scaleform::HeapMH::AllocBitSet2MH::GetUsableSize(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        const Scaleform::HeapMH::PageMH *page,
        const void *ptr)
{
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+0h] [ebp-1Ch] BYREF

  Scaleform::HeapMH::GetMagicHeaders((unsigned int)page->Start, &headers);
  return 16
       * Scaleform::Heap::BitSet2::GetBlockSize(
           headers.BitSet,
           (signed int)((int)ptr - (unsigned int)headers.AlignedStart) >> 4);
}
