void __thiscall Scaleform::Render::Tessellator::collectFanEdges(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonotoneType *v3; // esi
  Scaleform::Render::Tessellator::MonoVertexType *start; // ebp
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *p_LeftChain; // esi
  unsigned int v6; // edi

  v3 = m;
  this->LeftChain.Size = 0;
  this->RightChain.Size = 0;
  start = m->start;
  if ( m->start )
  {
    do
    {
      p_LeftChain = &this->LeftChain;
      if ( (start->srcVer & 0x80000000) == 0 )
        p_LeftChain = &this->RightChain;
      v6 = p_LeftChain->Size >> 4;
      if ( v6 >= p_LeftChain->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8>::allocPage(
          p_LeftChain,
          p_LeftChain->Size >> 4);
      p_LeftChain->Pages[v6][p_LeftChain->Size++ & 0xF] = start;
      start = start->next;
    }
    while ( start );
    v3 = m;
  }
  if ( this->LeftChain.Size )
    Scaleform::Render::Tessellator::collectFanEdges(
      this,
      &this->LeftChain,
      &this->RightChain,
      LOWORD(v3->style) | 0x8000);
  if ( this->RightChain.Size )
    Scaleform::Render::Tessellator::collectFanEdges(this, &this->RightChain, &this->LeftChain, v3->style);
}
