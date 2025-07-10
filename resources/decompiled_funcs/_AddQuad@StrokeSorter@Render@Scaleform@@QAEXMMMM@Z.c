void __thiscall Scaleform::Render::StrokeSorter::AddQuad(
        Scaleform::Render::StrokeSorter *this,
        float x2,
        float y2,
        float x3,
        float y3)
{
  Scaleform::Render::StrokeSorter::AddVertexNV(this, x2, y2, 2u);
  Scaleform::Render::StrokeSorter::AddVertexNV(this, x3, y3, 2u);
}
