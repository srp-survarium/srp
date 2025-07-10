void __thiscall Scaleform::Render::Tessellator::SetEdgeAAWidth(Scaleform::Render::Tessellator *this, float w)
{
  this->EdgeAAWidth = w;
  this->EdgeAAFlag = w > 0.0;
}
