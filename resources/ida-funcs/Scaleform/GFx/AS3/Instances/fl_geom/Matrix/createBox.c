void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::createBox(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        const Scaleform::GFx::AS3::Value *result,
        long double scaleX,
        long double scaleY,
        long double rotation,
        long double tx,
        long double ty)
{
  long double v8; // st5
  long double v9; // st4
  long double v10; // st6
  long double v11; // st3
  long double v12; // st7
  Scaleform::Render::Matrix2x4<double> m; // [esp+48h] [ebp-40h] BYREF

  m.M[0][2] = 0.0;
  m.M[1][2] = 0.0;
  m.M[0][0] = this->a;
  m.M[1][0] = this->b;
  m.M[0][1] = this->c;
  m.M[1][1] = this->d;
  m.M[0][3] = this->tx;
  m.M[1][3] = this->ty;
  Scaleform::Render::Matrix2x4<double>::AppendRotation(&m, rotation);
  v8 = m.M[0][1] * scaleX;
  v9 = m.M[1][0] * scaleY;
  v10 = m.M[1][1] * scaleY;
  v11 = scaleX * m.M[0][3] + tx;
  v12 = scaleY * m.M[1][3] + ty;
  this->a = m.M[0][0] * scaleX;
  this->b = v9;
  this->c = v8;
  this->d = v10;
  this->tx = v11;
  this->ty = v12;
}
