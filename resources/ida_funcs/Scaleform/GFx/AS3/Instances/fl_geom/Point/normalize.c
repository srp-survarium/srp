void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::normalize(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        const Scaleform::GFx::AS3::Value *result,
        long double thickness)
{
  long double v3; // st7
  long double v4; // st6
  long double v5; // st7

  if ( 0.0 == this->x && 0.0 == this->y )
  {
    this->x = 0.0;
    this->y = 0.0;
  }
  else
  {
    v3 = sqrt(this->y * this->y + this->x * this->x);
    v4 = thickness * this->y / v3;
    v5 = thickness * this->x / v3;
    this->y = v4;
    this->x = v5;
  }
}
