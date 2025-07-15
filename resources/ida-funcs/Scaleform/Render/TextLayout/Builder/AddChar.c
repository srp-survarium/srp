void __thiscall Scaleform::Render::TextLayout::Builder::AddChar(
        Scaleform::Render::TextLayout::Builder *this,
        __int16 glyphIndex,
        float advance,
        char invisible,
        bool fauxBold,
        bool fauxItalic)
{
  char v6; // al
  unsigned __int8 *v7; // edi
  int v8; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  _BYTE v10[2]; // [esp+0h] [ebp-8h] BYREF
  __int16 v11; // [esp+2h] [ebp-6h]
  float v12; // [esp+4h] [ebp-4h]

  v6 = invisible != 0;
  if ( fauxBold )
    v6 |= 2u;
  if ( fauxItalic )
    v6 |= 4u;
  v12 = advance;
  v10[1] = v6;
  v10[0] = 0;
  v11 = glyphIndex;
  v7 = v10;
  v8 = 8;
  p_Data = &this->Data;
  do
  {
    --v8;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v7++);
  }
  while ( v8 );
}
