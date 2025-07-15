Scaleform::Render::Rect<long> *__thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::Render::Rect<long> *result,
        const Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  long double y; // st7
  int v5; // eax
  long double v6; // st7
  int v7; // eax
  long double v8; // st7

  y = rect->y;
  result->x1 = (int)rect->x;
  v5 = (int)y;
  v6 = rect->width + rect->x;
  result->y1 = v5;
  v7 = (int)v6;
  v8 = rect->height + rect->y;
  result->x2 = v7;
  result->y2 = (int)v8;
  return result;
}
