double __thiscall Scaleform::Render::Hairliner::GetLastY(Scaleform::Render::Hairliner *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(this->SrcVertices.Size - 1) & 0xF].y;
}
