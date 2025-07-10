void __cdecl Scaleform::GFx::AS2::ValidateRect(Scaleform::Render::Rect<double> *r)
{
  double x1; // [esp+4h] [ebp-8h]
  double x2; // [esp+4h] [ebp-8h]
  double y1; // [esp+4h] [ebp-8h]
  double y2; // [esp+4h] [ebp-8h]

  x1 = r->x1;
  if ( (HIDWORD(x1) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(x1) | LODWORD(x1) )
    r->x1 = 0.0;
  x2 = r->x2;
  if ( (HIDWORD(x2) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(x2) | LODWORD(x2) )
    r->x2 = 0.0;
  y1 = r->y1;
  if ( (HIDWORD(y1) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(y1) | LODWORD(y1) )
    r->y1 = 0.0;
  y2 = r->y2;
  if ( (HIDWORD(y2) & 0x7FF00000) == 0x7FF00000 )
  {
    if ( (unsigned int)&loc_FFFFF & HIDWORD(y2) | LODWORD(y2) )
      r->y2 = 0.0;
  }
}
