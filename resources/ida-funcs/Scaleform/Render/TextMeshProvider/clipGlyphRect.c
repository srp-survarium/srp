char __thiscall Scaleform::Render::TextMeshProvider::clipGlyphRect(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Rect<float> *chr,
        Scaleform::Render::Rect<float> *tex)
{
  double v5; // st7
  double v6; // st7
  double x2; // st6
  double v8; // st7
  double y2; // st6
  double v10; // st7
  float y1; // [esp+1Ch] [ebp-24h]
  float v12; // [esp+1Ch] [ebp-24h]
  float v13; // [esp+1Ch] [ebp-24h]
  float v14; // [esp+1Ch] [ebp-24h]
  float v15; // [esp+1Ch] [ebp-24h]
  float v16; // [esp+1Ch] [ebp-24h]
  float v17; // [esp+1Ch] [ebp-24h]
  float v18; // [esp+1Ch] [ebp-24h]
  float v19; // [esp+1Ch] [ebp-24h]
  Scaleform::Render::Rect<float> r; // [esp+20h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> v21; // [esp+30h] [ebp-10h] BYREF

  if ( (this->Flags & 8) != 0 )
  {
    r.x1 = chr->x1;
    r.y1 = chr->y1;
    r.x2 = chr->x2;
    r.y2 = chr->y2;
    Scaleform::Render::Rect<float>::Intersect(
      &r,
      this->ClipBox.x1,
      this->ClipBox.y1,
      this->ClipBox.x2,
      this->ClipBox.y2);
    if ( r.x2 <= (double)r.x1 || r.y2 <= (double)r.y1 )
    {
      y1 = this->ClipBox.y1;
      chr->x1 = this->ClipBox.x1;
      chr->y1 = y1;
      chr->x2 = chr->x1;
      chr->y2 = y1;
      tex->x2 = tex->x1;
      tex->y2 = tex->y1;
      return 0;
    }
    if ( Scaleform::Render::Rect<float>::operator!=(&r, chr) )
    {
      Scaleform::Render::Rect<float>::Rect<float>(&v21, tex);
      if ( r.x1 != chr->x1 )
      {
        v12 = tex->x2 - tex->x1;
        v5 = (r.x1 - chr->x1) * v12;
        v13 = chr->x2 - chr->x1;
        v21.x1 = v5 / v13 + tex->x1;
      }
      if ( r.y1 != chr->y1 )
      {
        v14 = tex->y2 - tex->y1;
        v6 = (r.y1 - chr->y1) * v14;
        v15 = chr->y2 - chr->y1;
        v21.y1 = v6 / v15 + tex->y1;
      }
      if ( r.x2 != chr->x2 )
      {
        x2 = tex->x2;
        v16 = x2 - tex->x1;
        v8 = (chr->x2 - r.x2) * v16;
        v17 = chr->x2 - chr->x1;
        v21.x2 = x2 - v8 / v17;
      }
      if ( r.y2 != chr->y2 )
      {
        y2 = tex->y2;
        v18 = y2 - tex->y1;
        v10 = (chr->y2 - r.y2) * v18;
        v19 = chr->y2 - chr->y1;
        v21.y2 = y2 - v10 / v19;
      }
      Scaleform::Render::Rect<float>::operator=(chr, &r);
      Scaleform::Render::Rect<float>::operator=(tex, &v21);
    }
  }
  return 1;
}
