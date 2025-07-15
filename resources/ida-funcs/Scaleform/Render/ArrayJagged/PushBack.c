void __thiscall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this,
        unsigned int i,
        const Scaleform::Render::Tessellator::TriangleType *val)
{
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v4; // esi
  unsigned int v5; // edi

  v4 = &this->Arrays[i];
  v5 = v4->Size >> 4;
  if ( v5 >= v4->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      this,
      v4,
      v4->Size >> 4);
  v4->Pages[v5][v4->Size & 0xF] = *val;
  ++this->Arrays[i].Size;
}
