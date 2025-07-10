int __thiscall Scaleform::Render::Scale9GridTess::getAreaCode(
        Scaleform::Render::Scale9GridTess *this,
        const Scaleform::Render::Rect<float> *r,
        float x,
        float y)
{
  BOOL v4; // esi
  BOOL v5; // edx
  BOOL v6; // ecx

  v4 = r->x2 < (double)x;
  v5 = r->y2 < (double)y;
  v6 = r->x1 > (double)x;
  if ( r->y1 <= (double)y )
    return v4 | (2 * (v5 | (2 * v6)));
  else
    return v4 | (2 * (v5 | (2 * (v6 | 2))));
}
