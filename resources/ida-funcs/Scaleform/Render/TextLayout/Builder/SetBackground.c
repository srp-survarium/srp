void __thiscall Scaleform::Render::TextLayout::Builder::SetBackground(
        Scaleform::Render::TextLayout::Builder *this,
        unsigned int bkColor,
        unsigned int brColor)
{
  unsigned __int8 *v3; // edi
  int v4; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  _BYTE v6[2]; // [esp+Ch] [ebp-Ch] BYREF
  __int16 v7; // [esp+Eh] [ebp-Ah]
  unsigned int v8; // [esp+10h] [ebp-8h]
  unsigned int v9; // [esp+14h] [ebp-4h]

  v7 = 0;
  v6[0] = 2;
  v6[1] = 0;
  v8 = bkColor;
  v9 = brColor;
  v3 = v6;
  v4 = 12;
  p_Data = &this->Data;
  do
  {
    --v4;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v3++);
  }
  while ( v4 );
}
