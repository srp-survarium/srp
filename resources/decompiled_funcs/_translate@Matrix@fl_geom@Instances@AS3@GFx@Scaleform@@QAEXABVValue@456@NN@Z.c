void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::translate(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        const Scaleform::GFx::AS3::Value *result,
        long double dx,
        long double dy)
{
  long double v4; // st7

  v4 = this->ty + dy;
  this->tx = this->tx + dx;
  this->ty = v4;
}
