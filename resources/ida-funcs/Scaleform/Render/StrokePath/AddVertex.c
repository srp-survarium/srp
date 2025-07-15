void __thiscall Scaleform::Render::StrokePath::AddVertex(
        Scaleform::Render::StrokePath *this,
        const Scaleform::Render::StrokeVertex *v)
{
  unsigned int Size; // eax
  unsigned int v4; // ebx

  Size = this->Path.Size;
  if ( !Size || Scaleform::Render::StrokeVertex::Distance(&this->Path.Pages[(Size - 1) >> 4][(Size - 1) & 0xF], v) )
  {
    v4 = this->Path.Size >> 4;
    if ( v4 >= this->Path.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)this,
        this->Path.Size >> 4);
    this->Path.Pages[v4][this->Path.Size++ & 0xF] = *v;
  }
}
