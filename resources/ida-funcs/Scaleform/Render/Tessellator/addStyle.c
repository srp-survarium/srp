void __thiscall Scaleform::Render::Tessellator::addStyle(
        Scaleform::Render::Tessellator *this,
        unsigned int style,
        bool complex)
{
  unsigned int v3; // edx
  unsigned int Size; // eax
  unsigned int v6; // ebp
  unsigned __int8 *v7; // ebx
  const __m128i *Array; // eax
  unsigned int v9; // ecx
  unsigned int *v10; // eax

  v3 = style;
  if ( style )
  {
    if ( 32 * this->ComplexFlags.Size <= style )
    {
      do
      {
        Size = this->ComplexFlags.Size;
        v6 = 2 * Size;
        if ( !Size )
          v6 = 8;
        if ( v6 > Size )
        {
          v7 = Scaleform::Render::LinearHeap::Alloc(this->ComplexFlags.pHeap, 4 * v6);
          memset((int)v7, 0, 4 * v6);
          Array = (const __m128i *)this->ComplexFlags.Array;
          if ( Array )
          {
            v9 = this->ComplexFlags.Size;
            if ( v9 )
              memcpy((int)v7, Array, 4 * v9);
          }
          v3 = style;
          this->ComplexFlags.Array = (unsigned int *)v7;
        }
        this->ComplexFlags.Size = v6;
      }
      while ( 32 * v6 <= v3 );
    }
    if ( complex )
    {
      v10 = &this->ComplexFlags.Array[v3 >> 5];
      *v10 |= 1 << (v3 & 0x1F);
      this->HasComplexFill = 1;
    }
    if ( this->MaxStyle < v3 )
      this->MaxStyle = v3;
  }
}
