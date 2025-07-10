double __thiscall Scaleform::Render::Stroker::GetLastX(Scaleform::Render::Stroker *this)
{
  return this->Path.Path.Pages[(this->Path.Path.Size - 1) >> 4][(this->Path.Path.Size - 1) & 0xF].x;
}
