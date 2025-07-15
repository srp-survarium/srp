void __thiscall Scaleform::Render::TextLayout::Builder::SetNewLine(
        Scaleform::Render::TextLayout::Builder *this,
        float x,
        float y)
{
  Scaleform::Render::TextLayout::LineRecord *p_rec; // edi
  int v4; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  Scaleform::Render::TextLayout::LineRecord rec; // [esp+0h] [ebp-Ch] BYREF

  rec.x = x;
  rec.y = y;
  rec.Tag = 3;
  rec.Flags = 0;
  rec.Filler = 0;
  p_rec = &rec;
  v4 = 12;
  p_Data = &this->Data;
  do
  {
    --v4;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::LineRecord *)((char *)p_rec + 1);
  }
  while ( v4 );
}
