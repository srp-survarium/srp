void __thiscall Scaleform::Render::MaskBundle::RemoveEntries(
        Scaleform::Render::MaskBundle *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::MaskPrimitive::Remove(&this->Prim, index, count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}
