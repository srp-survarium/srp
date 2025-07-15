BOOL __thiscall Scaleform::Render::BlurFilterParams::EqualsAll(
        Scaleform::Render::BlurFilterParams *this,
        const Scaleform::Render::BlurFilterParams *b)
{
  return this->Mode == b->Mode
      && b->BlurX == this->BlurX
      && b->BlurY == this->BlurY
      && this->Passes == b->Passes
      && b->Offset.x == this->Offset.x
      && b->Offset.y == this->Offset.y
      && b->Strength == this->Strength
      && this->Colors[0].Raw == b->Colors[0].Raw
      && this->Colors[1].Raw == b->Colors[1].Raw;
}
