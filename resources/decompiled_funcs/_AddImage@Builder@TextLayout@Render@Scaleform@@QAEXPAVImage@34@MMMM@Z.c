void __thiscall Scaleform::Render::TextLayout::Builder::AddImage(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::Render::Image *img,
        float scaleX,
        float scaleY,
        float baseLine,
        float advance)
{
  Scaleform::Render::TextLayout::ImageRecord *p_rec; // edi
  int v8; // esi
  unsigned int Size; // edx
  unsigned int v10; // eax
  Scaleform::Render::Image **Data; // ecx
  Scaleform::Render::TextLayout::ImageRecord rec; // [esp+0h] [ebp-18h] BYREF

  rec.ScaleX = scaleX;
  rec.ScaleY = scaleY;
  rec.BaseLine = baseLine;
  rec.Advance = advance;
  rec.Tag = 8;
  rec.Flags = 0;
  rec.Filler = 0;
  rec.pImage = img;
  p_rec = &rec;
  v8 = 24;
  do
  {
    --v8;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::ImageRecord *)((char *)p_rec + 1);
  }
  while ( v8 );
  Size = this->Images.Size;
  v10 = 0;
  if ( Size )
  {
    Data = this->Images.Data;
    while ( img != *Data )
    {
      ++v10;
      ++Data;
      if ( v10 >= Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
      (Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *)&this->Images,
      (Scaleform::RefCountImpl *const *)&img);
  }
}
