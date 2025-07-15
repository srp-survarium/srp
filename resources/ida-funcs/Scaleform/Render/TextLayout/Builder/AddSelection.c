void __thiscall Scaleform::Render::TextLayout::Builder::AddSelection(
        Scaleform::Render::TextLayout::Builder *this,
        const Scaleform::Render::Rect<float> *r,
        unsigned int color)
{
  double x2; // st7
  unsigned __int8 *v4; // edi
  int v5; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  _BYTE v7[2]; // [esp+4h] [ebp-18h] BYREF
  __int16 v8; // [esp+6h] [ebp-16h]
  unsigned int v9; // [esp+8h] [ebp-14h]
  float x1; // [esp+Ch] [ebp-10h]
  float y1; // [esp+10h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-8h]
  float y2; // [esp+18h] [ebp-4h]

  v8 = 0;
  x1 = r->x1;
  y1 = r->y1;
  v7[0] = 5;
  x2 = r->x2;
  v7[1] = 0;
  v12 = x2;
  v9 = color;
  v4 = v7;
  y2 = r->y2;
  v5 = 24;
  p_Data = &this->Data;
  do
  {
    --v5;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v4++);
  }
  while ( v5 );
}
