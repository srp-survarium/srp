unsigned __int8 *__thiscall Scaleform::HeapMH::AllocEngineMH::ReallocInPage(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned __int8 *oldPtr,
        unsigned int newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo,
        bool __formal)
{
  unsigned __int8 *result; // eax
  unsigned int v8; // esi
  Scaleform::HeapMH::PageInfoMH *v9; // ecx
  Scaleform::HeapMH::PageMH *v10; // edx
  int v11; // esi
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+4h] [ebp-1Ch] BYREF

  result = 0;
  if ( newSize < 0x800 )
  {
    v8 = (newSize + 15) & 0xFFFFFFF0;
    result = Scaleform::HeapMH::AllocBitSet2MH::ReallocInPlace(&this->Allocator, page, oldPtr, v8, &newSize, &headers);
    if ( result )
    {
      v9 = newInfo;
      v10 = headers.Page;
      newInfo->UsableSize = v8;
      v11 = v8 - newSize;
      v9->Page = v10;
      v9->Node = 0;
      this->UsedSpace += v11;
    }
  }
  return result;
}
