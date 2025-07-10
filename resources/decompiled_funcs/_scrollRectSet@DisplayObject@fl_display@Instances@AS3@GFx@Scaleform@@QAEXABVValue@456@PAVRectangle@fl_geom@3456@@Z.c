void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scrollRectSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *value)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  long double v4; // st7
  long double v5; // st5
  long double y; // st3
  Scaleform::Render::Rect<double> r; // [esp+0h] [ebp-20h] BYREF

  pObject = this->pDispObj.pObject;
  if ( value )
  {
    v4 = value->width * 20.0;
    v5 = value->height * 20.0;
    y = value->y;
    r.x1 = value->x * 20.0;
    r.y1 = 20.0 * y;
    r.x2 = r.x1 + v4;
    r.y2 = r.y1 + v5;
    Scaleform::GFx::DisplayObject::SetScrollRect(pObject, &r);
  }
  else
  {
    Scaleform::GFx::DisplayObject::SetScrollRect(pObject, 0);
  }
}
