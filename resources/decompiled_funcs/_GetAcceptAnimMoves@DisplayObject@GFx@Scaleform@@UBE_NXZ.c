int __thiscall Scaleform::GFx::DisplayObject::GetAcceptAnimMoves(Scaleform::GFx::DisplayObject *this)
{
  return (this->Flags >> 3) & 1;
}
