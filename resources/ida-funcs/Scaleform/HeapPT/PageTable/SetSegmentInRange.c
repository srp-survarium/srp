void __thiscall Scaleform::HeapPT::PageTable::SetSegmentInRange(
        Scaleform::HeapPT::PageTable *this,
        unsigned int address,
        unsigned int size,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // ebp
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // [esp+10h] [ebp-4h]
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *v12; // [esp+1Ch] [ebp+8h]

  v4 = address;
  v5 = address + size - 1;
  v6 = address >> 20;
  v7 = v5 >> 20;
  v11 = v5;
  v8 = address >> 20;
  if ( address >> 20 <= v5 >> 20 )
  {
    v12 = &this->RootTable[v6];
    while ( 1 )
    {
      v9 = 0;
      v10 = 255;
      if ( v8 == v6 )
        v9 = (unsigned __int8)(v4 >> 12);
      if ( v8 == v7 )
        v10 = (unsigned __int8)(v5 >> 12);
      if ( v9 <= v10 )
      {
        memset32(&v12->pTable[v9], (int)seg, v10 - v9 + 1);
        v4 = address;
      }
      ++v12;
      if ( ++v8 > v7 )
        break;
      v5 = v11;
    }
  }
}
