void __thiscall Scaleform::Render::TextLayout::Builder::SetNewLine(
        Scaleform::Render::TextLayout::Builder *this,
        float x,
        float y)
{
  unsigned __int8 *v3; // edi
  int v4; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  _BYTE v6[2]; // [esp+0h] [ebp-Ch] BYREF
  __int16 v7; // [esp+2h] [ebp-Ah]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  v8 = x;
  v9 = y;
  v6[0] = 3;
  v6[1] = 0;
  v7 = 0;
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
