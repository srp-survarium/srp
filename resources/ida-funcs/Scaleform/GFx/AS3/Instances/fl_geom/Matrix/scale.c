void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::scale(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        const Scaleform::GFx::AS3::Value *result,
        long double sx,
        long double sy)
{
  long double v4; // st6
  long double v5; // st5
  long double v6; // st4
  long double v7; // st3
  long double v8; // st7

  v4 = this->c * sx;
  v5 = this->tx * sx;
  v6 = this->b * sy;
  v7 = this->d * sy;
  v8 = this->ty * sy;
  this->a = this->a * sx;
  this->b = v6;
  this->c = v4;
  this->d = v7;
  this->tx = v5;
  this->ty = v8;
}
