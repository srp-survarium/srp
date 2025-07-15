void __thiscall Scaleform::HeapMH::ListBinMH::Merge(
        Scaleform::HeapMH::ListBinMH *this,
        unsigned __int8 *node,
        unsigned int bytes,
        bool left,
        bool right,
        Scaleform::HeapMH::PageMH *page)
{
  unsigned int v6; // ebx
  unsigned __int8 *v9; // esi
  int v10; // eax
  int v11; // ecx
  Scaleform::HeapMH::BinNodeMH *v12; // eax
  unsigned __int8 *v13; // [esp+14h] [ebp+4h]

  v6 = bytes >> 4;
  node[16 * (bytes >> 4) - 1] = bytes >> 4;
  v9 = node;
  v13 = node + 12;
  *v13 = bytes >> 4;
  if ( left )
  {
    v9 = &node[-16 * *(node - 1)];
    v13 = v9 + 12;
    v6 += v9[12];
    Scaleform::HeapMH::ListBinMH::Pull(this, (Scaleform::HeapMH::BinNodeMH *)v9);
  }
  if ( right )
  {
    v10 = 16 * node[12];
    v6 += node[v10 + 12];
    Scaleform::HeapMH::ListBinMH::Pull(this, (Scaleform::HeapMH::BinNodeMH *)&node[v10]);
  }
  v9[16 * v6 - 1] = v6;
  *v13 = v6;
  *((_DWORD *)v9 + 2) = page;
  v11 = v6 - 1;
  if ( v6 - 1 >= 0x1F )
    v11 = 31;
  v12 = this->Roots[v11];
  if ( v12 )
  {
    *(_DWORD *)v9 = v12;
    *((_DWORD *)v9 + 1) = v12->Next;
    *(_DWORD *)v12->Next = v9;
    v12->Next = (unsigned int)v9;
  }
  else
  {
    *(_DWORD *)v9 = v9;
    *((_DWORD *)v9 + 1) = v9;
  }
  this->Roots[v11] = (Scaleform::HeapMH::BinNodeMH *)v9;
  this->Mask |= 1 << v11;
}
