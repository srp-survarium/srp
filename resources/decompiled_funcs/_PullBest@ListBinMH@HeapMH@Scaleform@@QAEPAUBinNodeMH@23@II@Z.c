Scaleform::HeapMH::BinNodeMH *__thiscall Scaleform::HeapMH::ListBinMH::PullBest(
        Scaleform::HeapMH::ListBinMH *this,
        unsigned int blocks,
        unsigned int alignMask)
{
  int v3; // esi
  Scaleform::HeapMH::BinNodeMH *result; // eax
  unsigned int v6; // ecx
  Scaleform::HeapMH::BinNodeMH **v7; // edi
  Scaleform::HeapMH::BinNodeMH *v8; // edi
  Scaleform::HeapMH::BinNodeMH *v9; // esi
  Scaleform::HeapMH::BinNodeMH *Next; // edi
  Scaleform::HeapMH::BinNodeMH **i; // [esp+8h] [ebp-8h]

  v3 = blocks - 1;
  if ( blocks - 1 >= 0x1F )
    v3 = 31;
  result = 0;
  if ( this->Mask >> v3 )
  {
    v6 = v3 + (unsigned __int8)Scaleform::Alg::LowerBit(this->Mask >> v3);
    v7 = &this->Roots[v6];
    for ( i = v7; ; ++i )
    {
      v8 = *v7;
      result = v8;
      if ( v8 )
        break;
LABEL_8:
      ++v6;
      v7 = i + 1;
      if ( v6 >= 0x20 )
        return 0;
    }
    while ( 16 * blocks + (~alignMask & ((unsigned int)result + alignMask)) > (unsigned int)result
                                                                            + 16 * LOBYTE(result[1].Prev) )
    {
      result = (Scaleform::HeapMH::BinNodeMH *)result->Next;
      if ( result == v8 )
        goto LABEL_8;
    }
    v9 = this->Roots[v6];
    if ( result != v9 )
      goto LABEL_14;
    Next = (Scaleform::HeapMH::BinNodeMH *)v9->Next;
    if ( v9 != Next )
    {
      this->Roots[v6] = Next;
LABEL_14:
      *(_DWORD *)(result->Prev + 4) = result->Next;
      *(_DWORD *)result->Next = result->Prev;
      return result;
    }
    this->Roots[v6] = 0;
    this->Mask &= ~(1 << v6);
  }
  return result;
}
