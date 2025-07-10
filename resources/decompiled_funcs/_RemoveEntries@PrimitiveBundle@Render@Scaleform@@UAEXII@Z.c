void __thiscall Scaleform::Render::PrimitiveBundle::RemoveEntries(
        Scaleform::Render::PrimitiveBundle *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::Primitive::Remove(&this->Prim, index, count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}
