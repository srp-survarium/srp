BOOL __cdecl Scaleform::GFx::AS2::IsRectValid(const Scaleform::Render::Rect<double> *r)
{
  BOOL result; // eax
  double x1; // [esp+Ch] [ebp-8h]
  double y1; // [esp+Ch] [ebp-8h]

  x1 = r->x1;
  result = 0;
  if ( (HIDWORD(x1) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(x1) | LODWORD(x1)) )
  {
    y1 = r->y1;
    if ( ((HIDWORD(y1) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(y1) | LODWORD(y1)))
      && !Scaleform::GFx::NumberUtil::IsNaN(r->x2)
      && !Scaleform::GFx::NumberUtil::IsNaN(r->y2) )
    {
      return 1;
    }
  }
  return result;
}
