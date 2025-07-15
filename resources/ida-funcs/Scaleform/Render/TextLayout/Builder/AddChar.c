void __thiscall Scaleform::Render::TextLayout::Builder::AddChar(
        Scaleform::Render::TextLayout::Builder *this,
        unsigned __int16 glyphIndex,
        float advance,
        unsigned __int8 invisible,
        bool fauxBold,
        bool fauxItalic)
{
  unsigned __int8 v6; // al
  Scaleform::Render::TextLayout::CharRecord *p_rec; // edi
  int v8; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  Scaleform::Render::TextLayout::CharRecord rec; // [esp+0h] [ebp-8h] BYREF

  v6 = invisible != 0;
  if ( fauxBold )
    v6 |= 2u;
  if ( fauxItalic )
    v6 |= 4u;
  rec.Advance = advance;
  rec.Flags = v6;
  rec.Tag = 0;
  rec.GlyphIndex = glyphIndex;
  p_rec = &rec;
  v8 = 8;
  p_Data = &this->Data;
  do
  {
    --v8;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::CharRecord *)((char *)p_rec + 1);
  }
  while ( v8 );
}
