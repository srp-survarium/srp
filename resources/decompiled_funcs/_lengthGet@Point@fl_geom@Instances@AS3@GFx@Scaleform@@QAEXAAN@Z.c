void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::lengthGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        long double *result)
{
  *result = sqrt(this->y * this->y + this->x * this->x);
}
