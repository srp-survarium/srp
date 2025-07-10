void __thiscall Scaleform::Render::TextLayout::Builder::AddRefCntData(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::RefCountImpl *p)
{
  Scaleform::Render::TextLayout::RefCntDataRecord *p_rec; // edi
  int v4; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  unsigned int Size; // edx
  unsigned int v7; // eax
  Scaleform::RefCountImpl **Data; // ecx
  Scaleform::Render::TextLayout::RefCntDataRecord rec; // [esp+10h] [ebp-8h] BYREF

  rec.Tag = 9;
  rec.Flags = 0;
  rec.pData = p;
  p_rec = &rec;
  v4 = 8;
  p_Data = &this->Data;
  do
  {
    --v4;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, &p_rec->Tag);
    p_rec = (Scaleform::Render::TextLayout::RefCntDataRecord *)((char *)p_rec + 1);
  }
  while ( v4 );
  Size = this->RefCntData.Size;
  v7 = 0;
  if ( Size )
  {
    Data = this->RefCntData.Data;
    while ( p != *Data )
    {
      ++v7;
      ++Data;
      if ( v7 >= Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(&this->RefCntData, &p);
  }
}
