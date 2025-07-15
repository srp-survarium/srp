char __thiscall Scaleform::Render::RawImage::Unmap(Scaleform::Render::RawImage *this)
{
  this->Data.Flags &= ~0x10u;
  return 1;
}
