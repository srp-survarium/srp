void __thiscall Scaleform::Render::StrokerAA::AddVertex(Scaleform::Render::StrokerAA *this, float x, float y)
{
  Scaleform::Render::StrokeVertex v; // [esp+0h] [ebp-Ch] BYREF

  v.x = x;
  v.y = y;
  v.dist = 0.0;
  Scaleform::Render::StrokePath::AddVertex(&this->Path, &v);
}
