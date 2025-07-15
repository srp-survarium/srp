void __thiscall Scaleform::Render::ShapeDataInterface::SkipPathData(
        Scaleform::Render::ShapeDataInterface *this,
        Scaleform::Render::ShapePosInfo *pos)
{
  _BYTE v3[24]; // [esp+8h] [ebp-18h] BYREF

  while ( this->ReadEdge(this, pos, (float *)v3) )
    ;
}
