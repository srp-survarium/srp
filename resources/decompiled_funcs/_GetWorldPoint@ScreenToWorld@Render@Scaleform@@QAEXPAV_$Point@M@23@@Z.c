void __thiscall Scaleform::Render::ScreenToWorld::GetWorldPoint(
        Scaleform::Render::ScreenToWorld *this,
        Scaleform::Render::Point<float> *ptOut)
{
  Scaleform::Render::Point3<float> pt3; // [esp+0h] [ebp-Ch] BYREF

  Scaleform::Render::ScreenToWorld::GetWorldPoint(this, &pt3);
  ptOut->x = pt3.x;
  ptOut->y = pt3.y;
}
