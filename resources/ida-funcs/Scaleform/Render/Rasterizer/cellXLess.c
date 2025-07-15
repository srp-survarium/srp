BOOL __cdecl Scaleform::Render::Rasterizer::cellXLess(
        const Scaleform::Render::Rasterizer::Cell *a1,
        const Scaleform::Render::Rasterizer::Cell *a2)
{
  return a1->x < a2->x;
}
