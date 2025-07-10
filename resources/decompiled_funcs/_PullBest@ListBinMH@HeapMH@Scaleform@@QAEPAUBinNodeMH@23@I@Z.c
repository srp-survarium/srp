Scaleform::HeapMH::BinNodeMH *__thiscall Scaleform::HeapMH::ListBinMH::PullBest(
        Scaleform::HeapMH::ListBinMH *this,
        unsigned int blocks)
{
  int v2; // edi
  Scaleform::HeapMH::BinNodeMH *result; // eax
  int v5; // ecx
  Scaleform::HeapMH::BinNodeMH *Next; // edx

  v2 = blocks - 1;
  if ( blocks - 1 >= 0x1F )
    v2 = 31;
  result = 0;
  if ( this->Mask >> v2 )
  {
    v5 = v2 + (unsigned __int8)Scaleform::Alg::LowerBit(this->Mask >> v2);
    result = this->Roots[v5];
    Next = (Scaleform::HeapMH::BinNodeMH *)result->Next;
    if ( result == Next )
    {
      this->Roots[v5] = 0;
      this->Mask &= ~(1 << v5);
    }
    else
    {
      this->Roots[v5] = Next;
      *(_DWORD *)(result->Prev + 4) = result->Next;
      *(_DWORD *)result->Next = result->Prev;
    }
  }
  return result;
}
