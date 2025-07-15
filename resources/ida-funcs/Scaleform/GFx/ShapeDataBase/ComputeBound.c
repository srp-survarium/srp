void __thiscall Scaleform::GFx::ShapeDataBase::ComputeBound(
        Scaleform::GFx::ShapeDataBase *this,
        Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Rect<float> bounds; // [esp+0h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [esp+10h] [ebp-20h] BYREF

  trans.M[0][0] = 1.0;
  trans.M[0][1] = 0.0;
  trans.M[0][2] = 0.0;
  trans.M[0][3] = 0.0;
  trans.M[1][0] = 0.0;
  trans.M[1][2] = 0.0;
  trans.M[1][3] = 0.0;
  trans.M[1][1] = 1.0;
  bounds.x1 = 1.0e30;
  bounds.y1 = 1.0e30;
  bounds.x2 = -1.0e30;
  bounds.y2 = -1.0e30;
  Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(this, &trans, &bounds, Bound_OuterEdges);
  *r = bounds;
}
