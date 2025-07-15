int __cdecl Scaleform::Render::Math2D::CheckCubicIntersection(
        int styleCount,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        float x,
        float y)
{
  unsigned int Size; // ebx
  Scaleform::Render::Math2D::QuadCurvePath *Data; // ebp
  float *p_ax; // esi
  int v15; // eax
  double v16; // st7
  float v18; // [esp+30h] [ebp-218h]
  float v19; // [esp+34h] [ebp-214h]
  Scaleform::Render::Math2D::QuadCurvePath path; // [esp+38h] [ebp-210h] BYREF

  path.Quads.pHeap = Scaleform::Memory::pGlobalHeap;
  path.Quads.Size = 0;
  path.Quads.Reserved = 32;
  path.Quads.Data = path.Quads.Static;
  Scaleform::Render::Math2D::CubicToQuadratic<Scaleform::Render::Math2D::QuadCurvePath>(
    x1,
    y1,
    x2,
    y2,
    x3,
    y3,
    x4,
    y4,
    &path);
  Size = path.Quads.Size;
  Data = (Scaleform::Render::Math2D::QuadCurvePath *)path.Quads.Data;
  v19 = x1;
  v18 = y1;
  if ( path.Quads.Size )
  {
    p_ax = &path.Quads.Data->ax;
    do
    {
      v15 = Scaleform::Render::Math2D::CheckQuadraticIntersection(
              styleCount,
              v19,
              v18,
              *(p_ax - 2),
              *(p_ax - 1),
              *p_ax,
              p_ax[1],
              x,
              y);
      v19 = *p_ax;
      v16 = p_ax[1];
      p_ax += 4;
      --Size;
      v18 = v16;
      styleCount = v15;
    }
    while ( Size );
  }
  if ( Data != (Scaleform::Render::Math2D::QuadCurvePath *)path.Quads.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  return styleCount;
}
