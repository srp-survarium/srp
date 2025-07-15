Scaleform::Render::Point<long> *__thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::Render::Point<long> *result,
        const Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  long double y; // st7

  y = point->y;
  result->x = (int)point->x;
  result->y = (int)y;
  return result;
}
