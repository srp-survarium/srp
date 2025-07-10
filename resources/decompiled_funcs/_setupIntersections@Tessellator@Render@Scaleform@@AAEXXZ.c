void __thiscall Scaleform::Render::Tessellator::setupIntersections(Scaleform::Render::Tessellator *this)
{
  Scaleform::Render::Tessellator *v1; // edx
  unsigned int v2; // ebx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *p_InteriorChains; // esi
  Scaleform::Render::ArrayPaged<unsigned int,4,16> *p_InteriorOrder; // ebp
  int v5; // eax
  int v6; // ecx
  Scaleform::Render::Tessellator::MonoVertexType **v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  Scaleform::Render::Tessellator::MonoVertexType **v11; // [esp+8h] [ebp-4h]

  v1 = this;
  v2 = 0;
  this->InteriorChains.Size = 0;
  this->InteriorOrder.Size = 0;
  if ( this->ActiveChains.Size )
  {
    p_InteriorChains = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->InteriorChains;
    p_InteriorOrder = &this->InteriorOrder;
    do
    {
      v5 = v2 >> 4;
      v6 = v2 & 0xF;
      v1->ActiveChains.Pages[v5][v6]->posIntr = v2;
      v7 = (Scaleform::Render::Tessellator::MonoVertexType **)&v1->ActiveChains.Pages[v5][v6];
      v8 = p_InteriorChains->Size >> 4;
      v11 = v7;
      if ( v8 >= p_InteriorChains->NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8>::allocPage(
          p_InteriorChains,
          v8);
        v7 = v11;
      }
      p_InteriorChains->Pages[v8][p_InteriorChains->Size++ & 0xF] = *v7;
      v9 = p_InteriorOrder->Size >> 4;
      if ( v9 >= p_InteriorOrder->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
          p_InteriorOrder,
          p_InteriorOrder->Size >> 4);
      v1 = this;
      p_InteriorOrder->Pages[v9][p_InteriorOrder->Size++ & 0xF] = v2++;
    }
    while ( v2 < this->ActiveChains.Size );
  }
}
