double __thiscall Scaleform::Render::Hairliner::GetLastX(Scaleform::Render::Hairliner *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(this->SrcVertices.Size - 1) & 0xF].x;
}
