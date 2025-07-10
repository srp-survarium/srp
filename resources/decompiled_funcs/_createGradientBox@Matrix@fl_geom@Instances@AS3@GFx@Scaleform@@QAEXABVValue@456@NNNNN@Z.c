void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::createGradientBox(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        const Scaleform::GFx::AS3::Value *result,
        long double width,
        long double height,
        long double rotation,
        long double tx,
        long double ty)
{
  double v8; // st7
  double v9; // st6
  long double v10; // st4
  double v11; // st1
  long double v12; // st7
  long double v13; // st5
  double v14; // st2
  long double v15; // st6
  float v16; // [esp+3Ch] [ebp-4Ch]
  float w; // [esp+40h] [ebp-48h]
  float wa; // [esp+40h] [ebp-48h]
  float h; // [esp+44h] [ebp-44h]
  float ha; // [esp+44h] [ebp-44h]
  float hb; // [esp+44h] [ebp-44h]
  float hc; // [esp+44h] [ebp-44h]
  float hd; // [esp+44h] [ebp-44h]
  float he; // [esp+44h] [ebp-44h]
  Scaleform::Render::Matrix2x4<double> m; // [esp+48h] [ebp-40h] BYREF

  m.M[0][0] = 1.0;
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][1] = 1.0;
  w = width;
  h = height;
  v16 = rotation;
  Scaleform::Render::Matrix2x4<double>::AppendRotation(&m, v16);
  v8 = w;
  wa = w * 0.0006103515625;
  v9 = h;
  ha = 0.0006103515625 * h;
  m.M[1][1] = m.M[1][1] * ha;
  v10 = ha * m.M[1][3];
  v11 = v8;
  v12 = m.M[1][0] * ha;
  hb = tx;
  hc = v11 * 0.5 + hb;
  v13 = wa * m.M[0][3] + hc;
  v14 = v9;
  v15 = m.M[0][1] * wa;
  hd = ty;
  he = v14 * 0.5 + hd;
  this->a = wa * m.M[0][0];
  this->b = v12;
  this->c = v15;
  this->d = m.M[1][1];
  this->tx = v13;
  this->ty = v10 + he;
}
