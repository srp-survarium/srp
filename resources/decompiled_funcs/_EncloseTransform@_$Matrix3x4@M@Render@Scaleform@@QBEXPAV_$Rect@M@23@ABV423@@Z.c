void __thiscall Scaleform::Render::Matrix3x4<float>::EncloseTransform(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Rect<float> *pr,
        const Scaleform::Render::Rect<float> *r)
{
  double v3; // st7
  double v4; // st6
  double v5; // st4
  double v6; // st7
  float x1; // [esp+Ch] [ebp-20h]
  float x2; // [esp+Ch] [ebp-20h]
  float v9; // [esp+Ch] [ebp-20h]
  float v10; // [esp+Ch] [ebp-20h]
  float y1; // [esp+10h] [ebp-1Ch]
  float y2; // [esp+10h] [ebp-1Ch]
  float v13; // [esp+10h] [ebp-1Ch]
  float v14; // [esp+14h] [ebp-18h]
  float v15; // [esp+18h] [ebp-14h]
  float x; // [esp+1Ch] [ebp-10h]
  float y; // [esp+20h] [ebp-Ch]
  float v18; // [esp+24h] [ebp-8h]
  float v19; // [esp+28h] [ebp-4h]

  x1 = r->x1;
  y1 = r->y1;
  v3 = this->M[0][2];
  v14 = this->M[0][0] * x1 + this->M[0][1] * y1 + v3 + this->M[0][3];
  v4 = this->M[1][2];
  v15 = x1 * this->M[1][0] + y1 * this->M[1][1] + v4 + this->M[1][3];
  x2 = r->x2;
  x = this->M[0][0] * x2 + this->M[0][1] * y1 + v3 + this->M[0][3];
  y = x2 * this->M[1][0] + y1 * this->M[1][1] + v4 + this->M[1][3];
  y2 = r->y2;
  v18 = y2 * this->M[0][1] + x2 * this->M[0][0] + v3 + this->M[0][3];
  v19 = y2 * this->M[1][1] + x2 * this->M[1][0] + v4 + this->M[1][3];
  v9 = r->x1;
  v5 = v3 + y2 * this->M[0][1] + v9 * this->M[0][0] + this->M[0][3];
  v6 = v9;
  v10 = v5;
  v13 = v6 * this->M[1][0] + y2 * this->M[1][1] + v4 + this->M[1][3];
  pr->x1 = v14;
  pr->y1 = v15;
  pr->y2 = v15;
  pr->x2 = v14;
  Scaleform::Render::Rect<float>::ExpandToPoint(pr, x, y);
  Scaleform::Render::Rect<float>::ExpandToPoint(pr, v18, v19);
  Scaleform::Render::Rect<float>::ExpandToPoint(pr, v10, v13);
}
