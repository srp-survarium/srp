double __thiscall Scaleform::Render::Tessellator::GetLastY(Scaleform::Render::Tessellator *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(this->SrcVertices.Size - 1) & 0xF].y;
}
