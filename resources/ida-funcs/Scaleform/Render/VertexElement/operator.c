BOOL __thiscall Scaleform::Render::VertexElement::operator==(
        Scaleform::Render::VertexElement *this,
        const Scaleform::Render::VertexElement *o)
{
  return this->Offset == o->Offset && this->Attribute == o->Attribute;
}
