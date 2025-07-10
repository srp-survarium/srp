void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::invert(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Matrix2x4<double> m; // [esp+8h] [ebp-40h] BYREF

  m.M[0][0] = this->a;
  m.M[0][1] = this->c;
  m.M[0][2] = 0.0;
  m.M[0][3] = this->tx;
  m.M[1][0] = this->b;
  m.M[1][1] = this->d;
  m.M[1][2] = 0.0;
  m.M[1][3] = this->ty;
  Scaleform::Render::Matrix2x4<double>::Invert(&m);
  this->a = m.M[0][0];
  this->b = m.M[1][0];
  this->c = m.M[0][1];
  this->d = m.M[1][1];
  this->tx = m.M[0][3];
  this->ty = m.M[1][3];
}
