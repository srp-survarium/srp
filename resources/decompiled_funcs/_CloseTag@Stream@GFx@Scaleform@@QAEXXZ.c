void __thiscall Scaleform::GFx::Stream::CloseTag(Scaleform::GFx::Stream *this)
{
  Scaleform::GFx::Stream::SetPosition(this, this->TagStack[--this->TagStackEntryCount]);
  this->UnusedBits = 0;
}
