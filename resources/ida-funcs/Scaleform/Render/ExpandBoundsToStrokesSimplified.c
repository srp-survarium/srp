void __cdecl Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::Rect<float> *bounds)
{
  unsigned int v3; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  unsigned int styles[3]; // [esp+28h] [ebp-6Ch] BYREF
  Scaleform::Render::Rect<float> result; // [esp+34h] [ebp-60h] BYREF
  float coord[6]; // [esp+44h] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+5Ch] [ebp-38h] BYREF

  v3 = shape->GetStartingPos(shape);
  pos.Sfactor = 1.0;
  pos.Pos = v3;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  if ( ReadPathInfo(shape, &pos, coord, styles) )
  {
    do
    {
      if ( styles[2] )
      {
        Scaleform::Render::ComputeBoundsRoundStroke<Scaleform::Render::Matrix2x4<float>>(
          &result,
          shape,
          trans,
          &pos,
          coord,
          styles);
        if ( result.x1 <= (double)result.x2 && result.y1 <= (double)result.y2 )
        {
          Scaleform::Render::Rect<float>::ExpandToPoint(bounds, result.x1, result.y1);
          Scaleform::Render::Rect<float>::ExpandToPoint(bounds, result.x2, result.y2);
        }
      }
      else
      {
        shape->SkipPathData(shape, &pos);
      }
    }
    while ( shape->ReadPathInfo(shape, &pos, coord, styles) );
  }
}
