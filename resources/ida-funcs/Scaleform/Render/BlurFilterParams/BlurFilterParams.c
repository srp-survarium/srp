void __thiscall Scaleform::Render::BlurFilterParams::BlurFilterParams(
        Scaleform::Render::BlurFilterParams *this,
        const Scaleform::Render::BlurFilterParams *__that)
{
  Scaleform::Render::Color *Colors; // eax
  float y; // [esp+8h] [ebp+4h]

  this->Mode = __that->Mode;
  this->Passes = __that->Passes;
  this->BlurX = __that->BlurX;
  this->BlurY = __that->BlurY;
  Colors = __that->Colors;
  y = __that->Offset.y;
  this->Offset.x = *(float *)&Colors[-3].Raw;
  this->Offset.y = y;
  this->Strength = *(float *)&Colors[-1].Raw;
  `vector copy constructor iterator'(
    (char *)this->Colors,
    (char *)Colors,
    4u,
    2,
    (void *(__thiscall *)(void *, void *))Scaleform::Render::Color::Color);
}
