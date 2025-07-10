void __thiscall Scaleform::Render::TextLayout::Builder::AddUnderline(
        Scaleform::Render::TextLayout::Builder *this,
        float x,
        float y,
        float len,
        Scaleform::Render::TextUnderlineStyle style,
        unsigned int color)
{
  Scaleform::Render::TextLayout::UnderlineRecord *p_rec; // edi
  int v7; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  Scaleform::Render::TextLayout::UnderlineRecord rec; // [esp+0h] [ebp-14h] BYREF

  rec.x = x;
  rec.y = y;
  rec.Len = len;
  rec.Tag = 6;
  rec.Flags = 0;
  rec.Style = style;
  rec.mColor = color;
  p_rec = &rec;
  v7 = 20;
  p_Data = &this->Data;
  do
  {
    --v7;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::UnderlineRecord *)((char *)p_rec + 1);
  }
  while ( v7 );
}
