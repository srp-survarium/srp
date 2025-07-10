void __thiscall Scaleform::Render::Tessellator::perceiveStyles(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *aet)
{
  unsigned int v3; // edi
  Scaleform::Render::Tessellator::MonoChainType *v4; // eax
  int rightStyle; // edx
  int *v6; // ecx
  unsigned int Size; // ecx
  int *v8; // edx
  unsigned __int16 leftAbove; // [esp+Ch] [ebp-4h]

  memset((int)this->StyleCounts.Array, 0, 4 * this->StyleCounts.Size);
  v3 = 0;
  for ( leftAbove = 0; v3 < aet->Size; ++v3 )
  {
    v4 = aet->Pages[v3 >> 4][v3 & 0xF];
    v4->flags &= ~4u;
    if ( (v4->flags & 2) == 0 )
    {
      rightStyle = v4->rightStyle;
      v6 = &this->StyleCounts.Array[v4->leftStyle];
      if ( this->FillRule )
      {
        *v6 ^= 1u;
        this->StyleCounts.Array[rightStyle] ^= 1u;
      }
      else
      {
        *v6 += v4->dir;
        this->StyleCounts.Array[rightStyle] -= v4->dir;
      }
      Size = this->StyleCounts.Size;
      if ( Size )
      {
        v8 = &this->StyleCounts.Array[Size - 1];
        while ( 1 )
        {
          --Size;
          if ( *v8 )
            break;
          --v8;
          if ( !Size )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        LOWORD(Size) = 0;
      }
      v4->rightAbove = Size;
      v4->leftAbove = leftAbove;
      if ( leftAbove != (_WORD)Size )
        v4->flags |= 4u;
      leftAbove = Size;
    }
  }
}
