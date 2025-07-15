void __thiscall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this)
{
  unsigned int NumArrays; // ecx
  unsigned int MaxArrays; // eax
  bool v4; // zf
  Scaleform::Render::LinearHeap *pHeap; // ecx
  unsigned __int8 *v6; // edi
  unsigned int v7; // edx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v8; // eax

  NumArrays = this->NumArrays;
  MaxArrays = this->MaxArrays;
  if ( NumArrays >= MaxArrays )
  {
    v4 = NumArrays == 0;
    pHeap = this->pHeap;
    if ( v4 )
    {
      this->MaxArrays = 16;
      this->Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(pHeap, 0x100u);
    }
    else
    {
      v6 = Scaleform::Render::LinearHeap::Alloc(pHeap, 32 * MaxArrays);
      memcpy((int)v6, (const __m128i *)this->Arrays, 16 * this->NumArrays);
      v7 = 2 * this->MaxArrays;
      this->Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)v6;
      this->MaxArrays = v7;
    }
  }
  v8 = &this->Arrays[this->NumArrays];
  v8->Size = 0;
  v8->NumPages = 0;
  v8->MaxPages = 0;
  v8->Pages = 0;
  ++this->NumArrays;
}
