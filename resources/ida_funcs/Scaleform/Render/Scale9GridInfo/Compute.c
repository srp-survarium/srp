void __thiscall Scaleform::Render::Scale9GridInfo::Compute(Scaleform::Render::Scale9GridInfo *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st4
  double v5; // st3
  double v6; // st6
  double v7; // st6
  double v8; // st7
  double v9; // st5
  double v10; // st6
  double v11; // st6
  double v12; // st4
  double v13; // st3
  double v14; // st6
  double v15; // st4
  double v16; // st5
  double v17; // st3
  float h; // [esp+8h] [ebp-108h]
  float ha; // [esp+8h] [ebp-108h]
  float wa; // [esp+Ch] [ebp-104h]
  float w; // [esp+Ch] [ebp-104h]
  float wb; // [esp+Ch] [ebp-104h]
  float oy7a; // [esp+10h] [ebp-100h]
  float oy7b; // [esp+10h] [ebp-100h]
  float oy7c; // [esp+10h] [ebp-100h]
  float oy7d; // [esp+10h] [ebp-100h]
  float oy7e; // [esp+10h] [ebp-100h]
  float oy7; // [esp+10h] [ebp-100h]
  double oy7f; // [esp+10h] [ebp-100h]
  double oy7g; // [esp+10h] [ebp-100h]
  float ky2; // [esp+1Ch] [ebp-F4h]
  float ky2a; // [esp+1Ch] [ebp-F4h]
  float ix1; // [esp+20h] [ebp-F0h]
  float ix1a; // [esp+20h] [ebp-F0h]
  float src; // [esp+24h] [ebp-ECh] BYREF
  float v36; // [esp+28h] [ebp-E8h]
  float v37; // [esp+2Ch] [ebp-E4h]
  float v38; // [esp+30h] [ebp-E0h]
  float v39; // [esp+34h] [ebp-DCh]
  float v40; // [esp+38h] [ebp-D8h]
  float pr[6]; // [esp+3Ch] [ebp-D4h] BYREF
  float gy1; // [esp+54h] [ebp-BCh]
  float gy2; // [esp+58h] [ebp-B8h]
  float gx1; // [esp+5Ch] [ebp-B4h]
  float gx2; // [esp+60h] [ebp-B0h]
  float by2; // [esp+64h] [ebp-ACh]
  float bx2; // [esp+68h] [ebp-A8h]
  float bx1; // [esp+6Ch] [ebp-A4h]
  double ix2; // [esp+70h] [ebp-A0h]
  float tx1; // [esp+7Ch] [ebp-94h]
  float ox4; // [esp+80h] [ebp-90h]
  float by1; // [esp+84h] [ebp-8Ch]
  float ty2; // [esp+88h] [ebp-88h]
  float ty3; // [esp+8Ch] [ebp-84h]
  float tx3; // [esp+90h] [ebp-80h]
  float tx2; // [esp+94h] [ebp-7Ch]
  double ox7; // [esp+98h] [ebp-78h]
  float oy3; // [esp+A4h] [ebp-6Ch]
  float ty4; // [esp+A8h] [ebp-68h]
  float ox3; // [esp+ACh] [ebp-64h]
  double ix3; // [esp+B0h] [ebp-60h]
  float tx4; // [esp+BCh] [ebp-54h]
  float ox2; // [esp+C0h] [ebp-50h]
  float ox1; // [esp+C4h] [ebp-4Ch]
  float oy1; // [esp+C8h] [ebp-48h]
  float oy2; // [esp+CCh] [ebp-44h]
  double iy2; // [esp+D0h] [ebp-40h]
  float ox8; // [esp+DCh] [ebp-34h]
  double iy3; // [esp+E0h] [ebp-30h]
  double oy8; // [esp+E8h] [ebp-28h]
  double v71; // [esp+F0h] [ebp-20h]
  double v72; // [esp+F8h] [ebp-18h]
  double v73; // [esp+100h] [ebp-10h]
  double v74; // [esp+108h] [ebp-8h]

  gx1 = this->Scale9.x1;
  gy1 = this->Scale9.y1;
  gx2 = this->Scale9.x2;
  gy2 = this->Scale9.y2;
  bx1 = this->Bounds.x1;
  by1 = this->Bounds.y1;
  bx2 = this->Bounds.x2;
  by2 = this->Bounds.y2;
  v2 = bx1;
  v3 = gx1;
  if ( gx1 <= (double)bx1 )
  {
    bx1 = v3 - 0.8999999761581421;
    v2 = bx1;
  }
  v4 = by1;
  v5 = gy1;
  if ( gy1 <= (double)by1 )
  {
    by1 = v5 - 0.8999999761581421;
    v4 = by1;
  }
  if ( gx2 >= (double)bx2 )
    bx2 = v3 + 0.8999999761581421;
  v6 = bx2;
  if ( gy2 >= (double)by2 )
    by2 = v5 + 0.8999999761581421;
  tx1 = this->S9gMatrix.M[0][1] * v4 + v2 * this->S9gMatrix.M[0][0] + this->S9gMatrix.M[0][3];
  ox4 = this->S9gMatrix.M[1][1] * v4 + this->S9gMatrix.M[1][0] * v2 + this->S9gMatrix.M[1][3];
  tx2 = this->S9gMatrix.M[0][1] * v4 + this->S9gMatrix.M[0][0] * v6 + this->S9gMatrix.M[0][3];
  ty2 = v4 * this->S9gMatrix.M[1][1] + this->S9gMatrix.M[1][0] * v6 + this->S9gMatrix.M[1][3];
  tx3 = this->S9gMatrix.M[0][1] * by2 + this->S9gMatrix.M[0][0] * v6 + this->S9gMatrix.M[0][3];
  ty3 = v6 * this->S9gMatrix.M[1][0] + this->S9gMatrix.M[1][1] * by2 + this->S9gMatrix.M[1][3];
  tx4 = this->S9gMatrix.M[0][1] * by2 + this->S9gMatrix.M[0][0] * v2 + this->S9gMatrix.M[0][3];
  ty4 = v2 * this->S9gMatrix.M[1][0] + by2 * this->S9gMatrix.M[1][1] + this->S9gMatrix.M[1][3];
  *(float *)&ox7 = tx2 - tx1;
  oy7a = ty2 - ox4;
  oy7b = oy7a * oy7a + *(float *)&ox7 * *(float *)&ox7;
  oy7c = sqrt(oy7b);
  wa = oy7c;
  *(float *)&ox7 = tx3 - tx2;
  oy7d = ty3 - ty2;
  oy7e = oy7d * oy7d + *(float *)&ox7 * *(float *)&ox7;
  oy7 = sqrt(oy7e);
  v7 = wa;
  if ( wa == 0.0 )
    v7 = (float)0.001;
  v8 = oy7;
  if ( oy7 == 0.0 )
    v8 = (float)0.001;
  h = (gx1 - bx1) / v7;
  ix1 = (gy1 - by1) / v8;
  w = (bx2 - gx2) / v7;
  ky2 = (by2 - gy2) / v8;
  v9 = h;
  *(float *)&ix2 = w + h;
  if ( *(float *)&ix2 <= 1.0 )
  {
    v10 = 0.05000000074505806;
  }
  else
  {
    *(float *)&ix2 = *(float *)&ix2 + 0.05000000074505806;
    h = v9 / *(float *)&ix2;
    v10 = 0.05000000074505806;
    w = w / *(float *)&ix2;
    v9 = h;
  }
  *(float *)&ix2 = ky2 + ix1;
  if ( *(float *)&ix2 <= 1.0 )
  {
    v11 = v9;
  }
  else
  {
    *(float *)&ix2 = v10 + *(float *)&ix2;
    ix1 = ix1 / *(float *)&ix2;
    v11 = v9;
    ky2 = ky2 / *(float *)&ix2;
  }
  v12 = tx2 - tx1;
  v13 = v11;
  v14 = tx1;
  ix3 = v13 * v12;
  ox1 = ix3 + tx1;
  oy7f = ty2 - ox4;
  iy2 = oy7f * h;
  oy1 = iy2 + ox4;
  ix2 = v12 * w;
  ox2 = tx2 - ix2;
  v15 = ox4;
  v71 = w * oy7f;
  oy2 = ty2 - v71;
  oy7g = tx3 - tx2;
  ox3 = tx2 + oy7g * ix1;
  ox7 = ty3 - ty2;
  oy3 = ty2 + ox7 * ix1;
  ox4 = tx3 - ky2 * oy7g;
  tx1 = ty3 - ky2 * ox7;
  oy8 = tx4 - v14;
  *(float *)&ox7 = tx4 - oy8 * ky2;
  iy3 = ty4 - v15;
  *(float *)&oy7g = ty4 - iy3 * ky2;
  ox8 = ix1 * oy8 + v14;
  *(float *)&oy8 = ix1 * iy3 + v15;
  ix1a = ox8 + ix3;
  ky2a = *(float *)&oy8 + iy2;
  *(float *)&ix2 = ox3 - ix2;
  *(float *)&iy2 = oy3 - v71;
  v16 = tx3 - tx4;
  v74 = w * v16;
  *(float *)&ix3 = ox4 - v74;
  v17 = ty3 - ty4;
  v73 = w * v17;
  *(float *)&iy3 = tx1 - v73;
  v71 = v16 * h;
  wb = v71 + *(float *)&ox7;
  v72 = h * v17;
  ha = v72 + *(float *)&oy7g;
  pr[0] = v14;
  pr[1] = v15;
  pr[2] = ox1;
  pr[3] = oy1;
  pr[4] = ix1a;
  pr[5] = ky2a;
  src = bx1;
  v36 = by1;
  v37 = gx1;
  v39 = gx1;
  v38 = by1;
  v40 = gy1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(this->ResultingMatrices, &src, pr);
  pr[0] = ox1;
  pr[1] = oy1;
  pr[2] = ox2;
  pr[3] = oy2;
  pr[4] = *(float *)&ix2;
  pr[5] = *(float *)&iy2;
  src = gx1;
  v36 = by1;
  v37 = gx2;
  v39 = gx2;
  v38 = by1;
  v40 = gy1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[1], &src, pr);
  pr[0] = ox2;
  pr[1] = oy2;
  pr[2] = tx2;
  pr[3] = ty2;
  pr[4] = ox3;
  pr[5] = oy3;
  src = gx2;
  v36 = by1;
  v37 = bx2;
  v39 = bx2;
  v38 = by1;
  v40 = gy1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[2], &src, pr);
  pr[0] = ox8;
  pr[1] = *(float *)&oy8;
  pr[2] = ix1a;
  pr[3] = ky2a;
  pr[4] = wb;
  pr[5] = ha;
  src = bx1;
  v36 = gy1;
  v37 = gx1;
  v39 = gx1;
  v38 = gy1;
  v40 = gy2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[3], &src, pr);
  pr[0] = ix1a;
  pr[1] = ky2a;
  pr[2] = *(float *)&ix2;
  pr[3] = *(float *)&iy2;
  pr[4] = *(float *)&ix3;
  pr[5] = *(float *)&iy3;
  src = gx1;
  v36 = gy1;
  v37 = gx2;
  v39 = gx2;
  v38 = gy1;
  v40 = gy2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[4], &src, pr);
  pr[0] = *(float *)&ix2;
  pr[1] = *(float *)&iy2;
  pr[2] = ox3;
  pr[3] = oy3;
  pr[4] = ox4;
  pr[5] = tx1;
  src = gx2;
  v36 = gy1;
  v37 = bx2;
  v39 = bx2;
  v38 = gy1;
  v40 = gy2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[5], &src, pr);
  pr[0] = *(float *)&ox7;
  pr[1] = *(float *)&oy7g;
  pr[2] = wb;
  pr[3] = ha;
  pr[4] = tx4 + v71;
  pr[5] = ty4 + v72;
  src = bx1;
  v36 = gy2;
  v37 = gx1;
  v39 = gx1;
  v38 = gy2;
  v40 = by2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[6], &src, pr);
  pr[0] = wb;
  pr[1] = ha;
  pr[2] = *(float *)&ix3;
  pr[3] = *(float *)&iy3;
  pr[4] = tx3 - v74;
  pr[5] = ty3 - v73;
  src = gx1;
  v36 = gy2;
  v37 = gx2;
  v39 = gx2;
  v38 = gy2;
  v40 = by2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[7], &src, pr);
  pr[0] = *(float *)&ix3;
  pr[1] = *(float *)&iy3;
  pr[2] = ox4;
  pr[3] = tx1;
  pr[4] = tx3;
  pr[5] = ty3;
  src = gx2;
  v36 = gy2;
  v37 = bx2;
  v39 = bx2;
  v38 = gy2;
  v40 = by2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[8], &src, pr);
  this->ResultingGrid.x1 = gx1;
  this->ResultingGrid.y1 = gy1;
  this->ResultingGrid.x2 = gx2;
  this->ResultingGrid.y2 = gy2;
}
