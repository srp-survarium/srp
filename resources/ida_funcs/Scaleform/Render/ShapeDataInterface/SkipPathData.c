void __thiscall Scaleform::Render::ShapeDataInterface::SkipPathData(
        Scaleform::Render::ShapeDataInterface *this,
        Scaleform::Render::ShapePosInfo *pos)
{
  float coords[6]; // [esp+8h] [ebp-18h] BYREF

  while ( this->ReadEdge(this, pos, coords) )
    ;
}
