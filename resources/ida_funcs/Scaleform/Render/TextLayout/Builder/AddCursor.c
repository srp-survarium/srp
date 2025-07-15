void __thiscall Scaleform::Render::TextLayout::Builder::AddCursor(
        Scaleform::Render::TextLayout::Builder *this,
        const Scaleform::Render::Rect<float> *r,
        unsigned int color)
{
  double x2; // st7
  Scaleform::Render::TextLayout::CursorRecord *p_rec; // edi
  int v5; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  Scaleform::Render::TextLayout::CursorRecord rec; // [esp+4h] [ebp-18h] BYREF

  rec.Filler = 0;
  rec.x1 = r->x1;
  rec.y1 = r->y1;
  rec.Tag = 7;
  x2 = r->x2;
  rec.Flags = 0;
  rec.x2 = x2;
  rec.mColor = color;
  p_rec = &rec;
  rec.y2 = r->y2;
  v5 = 24;
  p_Data = &this->Data;
  do
  {
    --v5;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::CursorRecord *)((char *)p_rec + 1);
  }
  while ( v5 );
}
