Scaleform::String::DataDesc *__thiscall Scaleform::String::AllocDataCopy2(
        Scaleform::String *this,
        Scaleform::MemoryHeap *pheap,
        unsigned int size,
        unsigned int lengthIsSize,
        const __m128i *pdata1,
        unsigned int copySize1,
        const __m128i *pdata2,
        unsigned int copySize2)
{
  Scaleform::String::DataDesc *v8; // esi
  unsigned int *v9; // eax

  if ( size )
  {
    v9 = (unsigned int *)pheap->Alloc(pheap, size + 12, 0);
    *((_BYTE *)v9 + size + 8) = 0;
    v9[1] = 1;
    *v9 = lengthIsSize | size;
    v8 = (Scaleform::String::DataDesc *)v9;
  }
  else
  {
    InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
    v8 = &Scaleform::String::NullData;
  }
  memcpy((int)v8->Data, pdata1, copySize1);
  memcpy((int)&v8->Data[copySize1], pdata2, copySize2);
  return v8;
}
