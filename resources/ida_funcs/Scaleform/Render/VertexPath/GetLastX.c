double __thiscall Scaleform::Render::VertexPath::GetLastX(Scaleform::Render::VertexPath *this)
{
  return this->Vertices.Pages[(this->Vertices.Size - 1) >> 4][(this->Vertices.Size - 1) & 0xF].x;
}
