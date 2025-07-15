void __thiscall Scaleform::Render::TextLayout::Builder::SetBackground(
        Scaleform::Render::TextLayout::Builder *this,
        unsigned int bkColor,
        unsigned int brColor)
{
  Scaleform::Render::TextLayout::BackgroundRecord *p_rec; // edi
  int v4; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  Scaleform::Render::TextLayout::BackgroundRecord rec; // [esp+Ch] [ebp-Ch] BYREF

  rec.Filler = 0;
  rec.Tag = 2;
  rec.Flags = 0;
  rec.BackgroundColor = bkColor;
  rec.BorderColor = brColor;
  p_rec = &rec;
  v4 = 12;
  p_Data = &this->Data;
  do
  {
    --v4;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::BackgroundRecord *)((char *)p_rec + 1);
  }
  while ( v4 );
}
