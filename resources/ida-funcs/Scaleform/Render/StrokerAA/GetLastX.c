double __thiscall Scaleform::Render::StrokerAA::GetLastX(Scaleform::Render::StrokerAA *this)
{
  return this->Path.Path.Pages[(this->Path.Path.Size - 1) >> 4][(this->Path.Path.Size - 1) & 0xF].x;
}
