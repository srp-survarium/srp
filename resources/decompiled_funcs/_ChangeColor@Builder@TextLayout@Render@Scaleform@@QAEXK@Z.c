void __thiscall Scaleform::Render::TextLayout::Builder::ChangeColor(
        Scaleform::Render::TextLayout::Builder *this,
        unsigned int color)
{
  Scaleform::Render::TextLayout::ColorRecord *p_rec; // edi
  int v3; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  Scaleform::Render::TextLayout::ColorRecord rec; // [esp+Ch] [ebp-8h] BYREF

  rec.Tag = 1;
  rec.Flags = 0;
  rec.Filler = 0;
  rec.mColor = color;
  p_rec = &rec;
  v3 = 8;
  p_Data = &this->Data;
  do
  {
    --v3;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::ColorRecord *)((char *)p_rec + 1);
  }
  while ( v3 );
}
