Scaleform::Render::Point<float> *__usercall Scaleform::GFx::ClosestPointOnRectangle@<eax>(
        const Scaleform::Render::Rect<float> *r@<eax>,
        const Scaleform::Render::Point<float> *p@<ecx>,
        Scaleform::Render::Point<float> *a3@<esi>)
{
  int v3; // edx
  double y; // st5
  double v5; // st4
  Scaleform::Render::Point<float> *result; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st5
  float reta; // [esp+0h] [ebp-28h]
  float ret; // [esp+0h] [ebp-28h]
  float retb; // [esp+0h] [ebp-28h]
  float retc; // [esp+0h] [ebp-28h]
  float retd; // [esp+0h] [ebp-28h]
  float ret_4; // [esp+4h] [ebp-24h]
  Scaleform::Render::Point<float> v1; // [esp+8h] [ebp-20h] BYREF
  Scaleform::Render::Point<float> v2; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Point<float> v18; // [esp+18h] [ebp-10h] BYREF
  Scaleform::Render::Point<float> v19; // [esp+20h] [ebp-8h] BYREF

  v3 = 0;
  v1.x = r->x1;
  v1.y = r->y1;
  v18.x = r->x2;
  v18.y = r->y1;
  v2.x = r->x1;
  v2.y = r->y2;
  v19.x = r->x2;
  v19.y = r->y2;
  if ( v1.x < (double)p->x )
  {
    v3 = 2;
    if ( p->x < (double)v18.x )
      v3 = 1;
  }
  y = v1.y;
  v5 = v2.y;
  if ( v1.y < (double)p->y )
  {
    if ( p->y < v5 )
      v3 |= 0x10u;
    else
      v3 |= 0x20u;
  }
  switch ( v3 )
  {
    case 0:
      result = a3;
      a3->x = v1.x;
      a3->y = y;
      return result;
    case 1:
      retb = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
               &v1,
               &v18,
               p);
      v7 = retb;
      ret = v1.x + (v18.x - v1.x) * retb;
      v8 = v18.y;
      goto LABEL_11;
    case 2:
      result = a3;
      *a3 = v18;
      return result;
    case 16:
      reta = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
               &v1,
               &v2,
               p);
      v7 = reta;
      ret = v1.x + (v2.x - v1.x) * reta;
      v8 = v2.y;
LABEL_11:
      v9 = v1.y;
      goto LABEL_12;
    case 17:
    case 33:
      retc = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
               &v2,
               &v19,
               p);
      v7 = retc;
      ret = v2.x + (v19.x - v2.x) * retc;
      v8 = v19.y;
      v9 = v2.y;
      goto LABEL_12;
    case 18:
      retd = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
               &v18,
               &v19,
               p);
      v7 = retd;
      ret = v18.x + (v19.x - v18.x) * retd;
      v8 = v19.y;
      v9 = v18.y;
LABEL_12:
      result = a3;
      ret_4 = v7 * (v8 - v9) + v9;
      a3->x = ret;
      a3->y = ret_4;
      break;
    case 32:
      result = a3;
      a3->x = v2.x;
      a3->y = v5;
      break;
    case 34:
      result = a3;
      *a3 = v19;
      break;
    default:
      result = a3;
      a3->x = 3.4028235e38;
      a3->y = 3.4028235e38;
      break;
  }
  return result;
}
