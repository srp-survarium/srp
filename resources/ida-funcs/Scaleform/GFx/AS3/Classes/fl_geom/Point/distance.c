void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Point::distance(
        Scaleform::GFx::AS3::Classes::fl_geom::Point *this,
        long double *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *pt1,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *pt2)
{
  long double v4; // st6
  long double v5; // st5

  v4 = pt1->x - pt2->x;
  v5 = pt1->y - pt2->y;
  *result = sqrt(v5 * v5 + v4 * v4);
}
