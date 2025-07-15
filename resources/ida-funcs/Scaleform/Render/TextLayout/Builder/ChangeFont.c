void __thiscall Scaleform::Render::TextLayout::Builder::ChangeFont(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::Render::Font *f,
        float size)
{
  Scaleform::Render::TextLayout::FontRecord *p_rec; // ebx
  int v5; // edi
  Scaleform::Render::Font *v6; // edi
  double v7; // st7
  double v8; // st7
  unsigned int v9; // eax
  Scaleform::Render::Font **Data; // ecx
  Scaleform::Render::TextLayout::FontRecord rec; // [esp+0h] [ebp-Ch] BYREF

  rec.mSize = size;
  rec.Tag = 4;
  rec.Flags = 0;
  rec.Filler = 0;
  rec.pFont = f;
  p_rec = &rec;
  v5 = 12;
  do
  {
    --v5;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::FontRecord *)((char *)p_rec + 1);
  }
  while ( v5 );
  v6 = f;
  v7 = size;
  this->LastFont = f;
  *(double *)&rec.Tag = v7;
  v8 = ((double (__thiscall *)(Scaleform::Render::Font *))v6->GetNominalGlyphHeight)(v6);
  v9 = 0;
  this->LastScale = *(double *)&rec.Tag / v8;
  if ( this->Fonts.Size )
  {
    Data = this->Fonts.Data;
    while ( v6 != *Data )
    {
      ++v9;
      ++Data;
      if ( v9 >= this->Fonts.Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
      (Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *)&this->Fonts,
      &f);
  }
}
