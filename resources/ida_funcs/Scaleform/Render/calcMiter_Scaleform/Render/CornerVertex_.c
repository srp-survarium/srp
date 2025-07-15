void __usercall Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
        float *x@<edi>,
        float *y@<esi>,
        Scaleform::Render::CornerVertex v0,
        Scaleform::Render::CornerVertex v1,
        Scaleform::Render::CornerVertex v2,
        float width)
{
  double v6; // st3
  float ay; // [esp+4h] [ebp-44h]
  float v8; // [esp+8h] [ebp-40h]
  float by; // [esp+Ch] [ebp-3Ch]
  float v10; // [esp+10h] [ebp-38h]
  float cy; // [esp+14h] [ebp-34h]
  float v12; // [esp+18h] [ebp-30h]
  float dy; // [esp+1Ch] [ebp-2Ch]
  float dy1; // [esp+2Ch] [ebp-1Ch]
  float dy1a; // [esp+2Ch] [ebp-1Ch]
  float dy1b; // [esp+2Ch] [ebp-1Ch]
  float len2; // [esp+30h] [ebp-18h]
  float len2a; // [esp+30h] [ebp-18h]
  float len2b; // [esp+30h] [ebp-18h]
  float len2c; // [esp+30h] [ebp-18h]
  float len2d; // [esp+30h] [ebp-18h]
  float len2e; // [esp+30h] [ebp-18h]
  float dx2; // [esp+34h] [ebp-14h]
  float dx2a; // [esp+34h] [ebp-14h]
  double dx1; // [esp+38h] [ebp-10h]
  double v26; // [esp+40h] [ebp-8h]
  float dy2; // [esp+64h] [ebp+1Ch]
  float dy2a; // [esp+64h] [ebp+1Ch]
  float dy2b; // [esp+64h] [ebp+1Ch]
  float dy2c; // [esp+64h] [ebp+1Ch]
  float dy2d; // [esp+64h] [ebp+1Ch]
  float dy2e; // [esp+64h] [ebp+1Ch]
  float dy2f; // [esp+64h] [ebp+1Ch]
  float dy2g; // [esp+64h] [ebp+1Ch]
  float dy2h; // [esp+64h] [ebp+1Ch]

  len2 = v1.x - v0.x;
  dx1 = v1.y - v0.y;
  dy1 = dx1;
  len2a = dy1 * dy1 + len2 * len2;
  len2b = sqrt(len2a);
  dx2 = len2b;
  dy1a = v2.x - v1.x;
  v26 = v2.y - v1.y;
  len2c = v26;
  len2d = len2c * len2c + dy1a * dy1a;
  len2e = sqrt(len2d);
  *(float *)&dx1 = dx1 * width / dx2;
  dy1b = (v0.x - v1.x) * width / dx2;
  dx2a = width * v26 / len2e;
  dy2 = width * (v1.x - v2.x) / len2e;
  *(Scaleform::Render::CornerVertex *)x = v1;
  v6 = dy2;
  dy2a = dy2 + v2.y;
  dy = dy2a;
  dy2b = v2.x + dx2a;
  v12 = dy2b;
  dy2c = v6 + v1.y;
  cy = dy2c;
  dy2d = dx2a + v1.x;
  v10 = dy2d;
  dy2e = v1.y + dy1b;
  by = dy2e;
  dy2f = v1.x + *(float *)&dx1;
  v8 = dy2f;
  dy2g = dy1b + v0.y;
  ay = dy2g;
  dy2h = *(float *)&dx1 + v0.x;
  Scaleform::Render::Math2D::Intersection(dy2h, ay, v8, by, v10, cy, v12, dy, x, y, 0.001);
}
