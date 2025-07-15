Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ShapeMeshProvider::GetBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned int Capacity; // eax
  Scaleform::Render::Rect<float> *v5; // eax
  double x1; // st7
  Scaleform::Render::Rect<float> *v7; // eax
  float y1; // [esp+24h] [ebp-2Ch]
  float x2; // [esp+28h] [ebp-28h]
  float y2; // [esp+2Ch] [ebp-24h]
  Scaleform::Render::Rect<float> left; // [esp+30h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> resulta; // [esp+40h] [ebp-10h] BYREF

  Capacity = this->FillToStyleTable.Data.Policy.Capacity;
  if ( Capacity )
  {
    Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
      &resulta,
      (const Scaleform::Render::ShapeDataInterface *)(Capacity + 36),
      m,
      Bound_OuterEdges);
    Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
      &left,
      (const Scaleform::Render::ShapeDataInterface *)(this->FillToStyleTable.Data.Policy.Capacity + 96),
      m,
      Bound_OuterEdges);
    v5 = Scaleform::Render::Rect<float>::Union(&resulta, left.x1, left.y1, left.x2, left.y2);
    y1 = v5->y1;
    x2 = v5->x2;
    y2 = v5->y2;
    x1 = v5->x1;
    v7 = result;
    result->x1 = x1;
    result->y1 = y1;
    result->x2 = x2;
    result->y2 = y2;
  }
  else
  {
    Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
      result,
      (const Scaleform::Render::ShapeDataInterface *)this->FillToStyleTable.Data.Size,
      m,
      Bound_OuterEdges);
    return result;
  }
  return v7;
}
