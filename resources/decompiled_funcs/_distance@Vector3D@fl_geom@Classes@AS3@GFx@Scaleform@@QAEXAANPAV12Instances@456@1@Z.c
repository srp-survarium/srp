void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::distance(
        Scaleform::GFx::AS3::Classes::fl_geom::Vector3D *this,
        long double *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *pt1,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *pt2)
{
  long double v4; // st4
  long double v5; // st6
  long double v6; // st4
  long double v7; // st5
  long double v8; // st6

  v4 = pt1->x - pt2->x;
  v5 = v4 * v4;
  v6 = pt1->y - pt2->y;
  v7 = v5;
  v8 = pt1->z - pt2->z;
  *result = sqrt(v6 * v6 + v7 + v8 * v8);
}
