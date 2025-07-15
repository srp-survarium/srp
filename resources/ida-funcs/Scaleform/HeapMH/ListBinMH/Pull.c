void __thiscall Scaleform::HeapMH::ListBinMH::Pull(Scaleform::HeapMH::ListBinMH *this, unsigned __int8 *node)
{
  unsigned int v3; // ecx
  Scaleform::HeapMH::BinNodeMH *v4; // esi
  Scaleform::HeapMH::BinNodeMH *Next; // edi

  v3 = node[12] - 1;
  if ( v3 >= 0x1F )
    v3 = 31;
  v4 = this->Roots[v3];
  if ( node == (unsigned __int8 *)v4 )
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
      *(_DWORD *)(*(_DWORD *)node + 4) = *((_DWORD *)node + 1);
      **((_DWORD **)node + 1) = *(_DWORD *)node;
    }
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)node + 4) = *((_DWORD *)node + 1);
    **((_DWORD **)node + 1) = *(_DWORD *)node;
  }
}
