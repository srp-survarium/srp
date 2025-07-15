void __thiscall Scaleform::Render::TextLayout::Builder::ChangeFont(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::Render::Font *f,
        float size)
{
  unsigned __int8 *v4; // ebx
  int v5; // edi
  Scaleform::Render::Font *v6; // edi
  double v7; // st7
  double v8; // st7
  unsigned int v9; // eax
  Scaleform::Render::Font **Data; // ecx
  double v11; // [esp+0h] [ebp-Ch] BYREF
  Scaleform::Render::Font *v12; // [esp+8h] [ebp-4h]

  *((float *)&v11 + 1) = size;
  LODWORD(v11) = 4;
  v12 = f;
  v4 = (unsigned __int8 *)&v11;
  v5 = 12;
  do
  {
    --v5;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, v4++);
  }
  while ( v5 );
  v6 = f;
  v7 = size;
  this->LastFont = f;
  v11 = v7;
  v8 = ((double (__thiscall *)(Scaleform::Render::Font *))v6->GetNominalGlyphHeight)(v6);
  v9 = 0;
  this->LastScale = v11 / v8;
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
