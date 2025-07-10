BOOL __cdecl Scaleform::Render::Rasterizer::cellXLess(
        const Scaleform::Render::Rasterizer::Cell *a,
        const Scaleform::Render::Rasterizer::Cell *b)
{
  return a->x < b->x;
}
