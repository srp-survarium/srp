Scaleform::String::DataDesc *__thiscall Scaleform::String::AllocDataCopy1(
        Scaleform::String *this,
        Scaleform::MemoryHeap *pheap,
        unsigned int size,
        unsigned int lengthIsSize,
        char *pdata,
        unsigned int copySize)
{
  Scaleform::String::DataDesc *v6; // esi
  unsigned int *v7; // eax

  if ( size )
  {
    v7 = (unsigned int *)pheap->Alloc(pheap, size + 12, 0);
    *((_BYTE *)v7 + size + 8) = 0;
    v7[1] = 1;
    *v7 = lengthIsSize | size;
    v6 = (Scaleform::String::DataDesc *)v7;
  }
  else
  {
    InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
    v6 = &Scaleform::String::NullData;
  }
  memcpy((unsigned __int8 *)v6->Data, (unsigned __int8 *)pdata, copySize);
  return v6;
}
