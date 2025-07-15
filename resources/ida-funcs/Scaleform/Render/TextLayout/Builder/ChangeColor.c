void __thiscall Scaleform::Render::TextLayout::Builder::ChangeColor(
        Scaleform::Render::TextLayout::Builder *this,
        unsigned int color)
{
  unsigned __int8 *v2; // edi
  int v3; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  _BYTE v5[2]; // [esp+Ch] [ebp-8h] BYREF
  __int16 v6; // [esp+Eh] [ebp-6h]
  unsigned int v7; // [esp+10h] [ebp-4h]

  v5[0] = 1;
  v5[1] = 0;
  v6 = 0;
  v7 = color;
  v2 = v5;
  v3 = 8;
  p_Data = &this->Data;
  do
  {
    --v3;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v2++);
  }
  while ( v3 );
}
