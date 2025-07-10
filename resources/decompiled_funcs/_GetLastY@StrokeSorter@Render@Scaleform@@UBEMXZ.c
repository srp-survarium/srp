double __thiscall Scaleform::Render::StrokeSorter::GetLastY(Scaleform::Render::StrokeSorter *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(this->SrcVertices.Size - 1) & 0xF].y;
}
