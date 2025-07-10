void __thiscall Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::angleBetween(
        Scaleform::GFx::AS3::Classes::fl_geom::Vector3D *this,
        long double *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *a,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *b)
{
  *result = acos(
              (a->x * b->x + b->y * a->y + a->z * b->z)
            / (sqrt(b->x * b->x + b->y * b->y + b->z * b->z)
             * sqrt(a->y * a->y + a->x * a->x + a->z * a->z)));
}
