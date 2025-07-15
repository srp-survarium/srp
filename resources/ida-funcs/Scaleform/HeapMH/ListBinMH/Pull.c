void __thiscall Scaleform::HeapMH::ListBinMH::Pull(
        Scaleform::HeapMH::ListBinMH *this,
        Scaleform::HeapMH::BinNodeMH *node)
{
  unsigned int v3; // ecx
  Scaleform::HeapMH::BinNodeMH *v4; // esi
  Scaleform::HeapMH::BinNodeMH *Next; // edi

  v3 = LOBYTE(node[1].Prev) - 1;
  if ( v3 >= 0x1F )
    v3 = 31;
  v4 = this->Roots[v3];
  if ( node == v4 )
  {
    Next = (Scaleform::HeapMH::BinNodeMH *)v4->Next;
    if ( v4 == Next )
    {
      this->Roots[v3] = 0;
      this->Mask &= ~(1 << v3);
    }
    else
    {
      this->Roots[v3] = Next;
      *(_DWORD *)(node->Prev + 4) = node->Next;
      *(_DWORD *)node->Next = node->Prev;
    }
  }
  else
  {
    *(_DWORD *)(node->Prev + 4) = node->Next;
    *(_DWORD *)node->Next = node->Prev;
  }
}
