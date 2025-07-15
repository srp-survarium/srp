BOOL __thiscall Scaleform::Render::Viewport::operator==(
        Scaleform::Render::Viewport *this,
        const Scaleform::Render::Viewport *other)
{
  return this->BufferWidth == other->BufferWidth
      && this->BufferHeight == other->BufferHeight
      && this->Left == other->Left
      && this->Top == other->Top
      && this->Width == other->Width
      && this->Height == other->Height
      && this->ScissorLeft == other->ScissorLeft
      && this->ScissorTop == other->ScissorTop
      && this->ScissorWidth == other->ScissorWidth
      && this->ScissorHeight == other->ScissorHeight
      && this->Flags == other->Flags;
}
