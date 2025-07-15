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
  float v10; // [esp+0h] [ebp-28h]
  Scaleform::Render::Point<float> v11; // [esp+0h] [ebp-28h]
  float v12; // [esp+0h] [ebp-28h]
  float v13; // [esp+0h] [ebp-28h]
  float v14; // [esp+0h] [ebp-28h]
  Scaleform::Render::Point<float> v15; // [esp+8h] [ebp-20h] BYREF
  Scaleform::Render::Point<float> v16; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Point<float> v17; // [esp+18h] [ebp-10h] BYREF
  Scaleform::Render::Point<float> v18; // [esp+20h] [ebp-8h] BYREF

  v3 = 0;
  v15.x = r->x1;
  v15.y = r->y1;
  v17.x = r->x2;
  v17.y = r->y1;
  v16.x = r->x1;
  v16.y = r->y2;
  v18.x = r->x2;
  v18.y = r->y2;
  if ( v15.x < (double)p->x )
  {
    v3 = 2;
    if ( p->x < (double)v17.x )
      v3 = 1;
  }
  y = v15.y;
  v5 = v16.y;
  if ( v15.y < (double)p->y )
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
      a3->x = v15.x;
      a3->y = y;
      return result;
    case 1:
      v12 = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
              &v15,
              &v17,
              p);
      v7 = v12;
      v11.x = v15.x + (v17.x - v15.x) * v12;
      v8 = v17.y;
      goto LABEL_11;
    case 2:
      result = a3;
      *a3 = v17;
      return result;
    case 16:
      v10 = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
              &v15,
              &v16,
              p);
      v7 = v10;
      v11.x = v15.x + (v16.x - v15.x) * v10;
      v8 = v16.y;
LABEL_11:
      v9 = v15.y;
      goto LABEL_12;
    case 17:
    case 33:
      v13 = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
              &v16,
              &v18,
              p);
      v7 = v13;
      v11.x = v16.x + (v18.x - v16.x) * v13;
      v8 = v18.y;
      v9 = v16.y;
      goto LABEL_12;
    case 18:
      v14 = Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
              &v17,
              &v18,
              p);
      v7 = v14;
      v11.x = v17.x + (v18.x - v17.x) * v14;
      v8 = v18.y;
      v9 = v17.y;
LABEL_12:
      result = a3;
      v11.y = v7 * (v8 - v9) + v9;
      *a3 = v11;
      break;
    case 32:
      result = a3;
      a3->x = v16.x;
      a3->y = v5;
      break;
    case 34:
      result = a3;
      *a3 = v18;
      break;
    default:
      result = a3;
      a3->x = 3.4028235e38;
      a3->y = 3.4028235e38;
      break;
  }
  return result;
}
