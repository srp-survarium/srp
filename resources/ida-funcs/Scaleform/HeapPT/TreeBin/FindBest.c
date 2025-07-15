Scaleform::HeapPT::BinTNode *__thiscall Scaleform::HeapPT::TreeBin::FindBest(
        Scaleform::HeapPT::TreeBin *this,
        unsigned int size)
{
  Scaleform::HeapPT::BinTNode *v3; // ebp
  unsigned int v4; // esi
  unsigned int v5; // ebx
  unsigned __int8 v6; // al
  Scaleform::HeapPT::BinTNode *v7; // eax
  int v8; // ecx
  unsigned int i; // edx
  unsigned int v10; // ecx
  Scaleform::HeapPT::BinTNode *v11; // ecx
  unsigned int v12; // ecx
  Scaleform::HeapPT::BinTNode *v14; // [esp+10h] [ebp-8h]
  Scaleform::HeapPT::BinTNode *v16; // [esp+1Ch] [ebp+4h]

  v3 = 0;
  v4 = -size;
  v14 = 0;
  if ( size >> 5 )
  {
    if ( size >> 5 <= 0xFFFF )
    {
      v6 = Scaleform::Alg::UpperBit(size >> 5);
      v5 = ((size >> (v6 + 4)) & 1) + 2 * v6;
    }
    else
    {
      v5 = 31;
    }
  }
  else
  {
    v5 = 0;
  }
  v7 = this->Roots[v5];
  LOBYTE(v8) = 0;
  if ( v7 )
  {
    v16 = 0;
    if ( v5 < 0x1F )
      v8 = 28 - (v5 >> 1);
    for ( i = size << v8; ; i *= 2 )
    {
      v10 = v7->Size - size;
      if ( v10 < v4 )
      {
        v3 = v7;
        v14 = v7;
        v4 = v7->Size - size;
        if ( !v10 )
          break;
      }
      v11 = v7->Child[1];
      v7 = v7->Child[i >> 31];
      if ( v11 && v11 != v7 )
        v16 = v11;
      if ( !v7 )
      {
        v7 = v16;
        v3 = v14;
        break;
      }
    }
    if ( v7 )
      goto LABEL_23;
    if ( v3 )
      return v3;
  }
  v12 = this->Mask & ((1 << (v5 + 1)) | -(1 << (v5 + 1)));
  if ( v12 )
    v7 = this->Roots[(unsigned __int8)Scaleform::Alg::LowerBit(v12)];
  for ( ; v7; v7 = v7->Child[v7->Child[0] == 0] )
  {
LABEL_23:
    if ( v7->Size - size < v4 )
    {
      v4 = v7->Size - size;
      v3 = v7;
    }
  }
  return v3;
}
