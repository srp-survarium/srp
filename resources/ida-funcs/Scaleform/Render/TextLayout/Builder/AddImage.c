void __thiscall Scaleform::Render::TextLayout::Builder::AddImage(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::Render::Image *img,
        float scaleX,
        float scaleY,
        float baseLine,
        float advance)
{
  unsigned __int8 *v7; // edi
  int v8; // esi
  unsigned int Size; // edx
  unsigned int v10; // eax
  Scaleform::Render::Image **Data; // ecx
  _BYTE v12[2]; // [esp+0h] [ebp-18h] BYREF
  __int16 v13; // [esp+2h] [ebp-16h]
  Scaleform::Render::Image *v14; // [esp+4h] [ebp-14h]
  float v15; // [esp+8h] [ebp-10h]
  float v16; // [esp+Ch] [ebp-Ch]
  float v17; // [esp+10h] [ebp-8h]
  float v18; // [esp+14h] [ebp-4h]

  v15 = scaleX;
  v16 = scaleY;
  v17 = baseLine;
  v18 = advance;
  v12[0] = 8;
  v12[1] = 0;
  v13 = 0;
  v14 = img;
  v7 = v12;
  v8 = 24;
  do
  {
    --v8;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, v7++);
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
      (Scaleform::RefCountImpl **)&img);
  }
}
