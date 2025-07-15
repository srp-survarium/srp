void __thiscall Scaleform::HeapPT::FreeBin::Merge(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::HeapPT::BinTNode *node,
        char shift,
        bool left,
        bool right)
{
  unsigned int ShortSize; // ebx
  Scaleform::HeapPT::FreeBin *v6; // edx
  Scaleform::HeapPT::BinTNode *v7; // esi
  unsigned int Index_high; // eax
  unsigned int Size; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  Scaleform::HeapPT::BinTNode *v13; // eax
  unsigned int v14; // eax

  ShortSize = node->ShortSize;
  v6 = this;
  if ( ShortSize >= 0x21 )
    ShortSize = node->Size;
  v7 = node;
  if ( left )
  {
    Index_high = HIWORD(node[-1].Index);
    if ( Index_high >= 0x21 )
      Index_high = (unsigned int)node[-1].Child[1];
    v7 = (Scaleform::HeapPT::BinTNode *)((char *)node - (Index_high << shift));
    Size = v7->ShortSize;
    if ( Size >= 0x21 )
      Size = v7->Size;
    ShortSize += Size;
    Scaleform::HeapPT::FreeBin::Pull(this, v7);
    v6 = this;
  }
  if ( right )
  {
    v10 = node->ShortSize;
    if ( v10 >= 0x21 )
      v10 = node->Size;
    v11 = v10 << shift;
    v12 = *(unsigned __int16 *)((char *)&node->ShortSize + v11);
    v13 = (Scaleform::HeapPT::BinTNode *)((char *)node + v11);
    if ( v12 >= 0x21 )
      v12 = v13->Size;
    ShortSize += v12;
    Scaleform::HeapPT::FreeBin::Pull(v6, v13);
    v6 = this;
  }
  v14 = ShortSize << shift;
  if ( ShortSize >= 0x21 )
  {
    *(_WORD *)((char *)v7 + v14 - 2) = 33;
    v7->ShortSize = 33;
    *(_DWORD *)((char *)v7 + v14 - 8) = ShortSize;
    v7->Size = ShortSize;
  }
  else
  {
    *(_WORD *)((char *)v7 + v14 - 2) = ShortSize;
    v7->ShortSize = ShortSize;
  }
  Scaleform::HeapPT::FreeBin::Push(v6, v7);
}
