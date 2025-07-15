void __thiscall Scaleform::Render::StrokeSorter::AddCubic(
        Scaleform::Render::StrokeSorter *this,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4)
{
  Scaleform::Render::StrokeSorter::AddVertexNV(this, x2, y2, 3u);
  Scaleform::Render::StrokeSorter::AddVertexNV(this, x3, y3, 3u);
  Scaleform::Render::StrokeSorter::AddVertexNV(this, x4, y4, 3u);
}
