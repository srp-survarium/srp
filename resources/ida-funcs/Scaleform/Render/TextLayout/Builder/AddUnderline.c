void __thiscall Scaleform::Render::TextLayout::Builder::AddUnderline(
        Scaleform::Render::TextLayout::Builder *this,
        float x,
        float y,
        float len,
        Scaleform::Render::TextUnderlineStyle style,
        unsigned int color)
{
  unsigned __int8 *v6; // edi
  int v7; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  _BYTE v9[2]; // [esp+0h] [ebp-14h] BYREF
  __int16 v10; // [esp+2h] [ebp-12h]
  float v11; // [esp+4h] [ebp-10h]
  float v12; // [esp+8h] [ebp-Ch]
  float v13; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+10h] [ebp-4h]

  v11 = x;
  v12 = y;
  v13 = len;
  v9[0] = 6;
  v9[1] = 0;
  v10 = style;
  v14 = color;
  v6 = v9;
  v7 = 20;
  p_Data = &this->Data;
  do
  {
    --v7;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v6++);
  }
  while ( v7 );
}
