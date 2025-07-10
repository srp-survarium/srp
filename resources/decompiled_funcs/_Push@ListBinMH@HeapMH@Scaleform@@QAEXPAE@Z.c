void __thiscall Scaleform::HeapMH::ListBinMH::Push(
        Scaleform::HeapMH::ListBinMH *this,
        Scaleform::HeapMH::BinNodeMH *node)
{
  unsigned int v2; // eax
  Scaleform::HeapMH::BinNodeMH *v3; // edi

  v2 = LOBYTE(node[1].Prev) - 1;
  if ( v2 >= 0x1F )
    v2 = 31;
  v3 = this->Roots[v2];
  if ( v3 )
  {
    node->Prev = (unsigned int)v3;
    node->Next = v3->Next;
    *(_DWORD *)v3->Next = node;
    v3->Next = (unsigned int)node;
  }
  else
  {
    node->Prev = (unsigned int)node;
    node->Next = (unsigned int)node;
  }
  this->Roots[v2] = node;
  this->Mask |= 1 << v2;
}
