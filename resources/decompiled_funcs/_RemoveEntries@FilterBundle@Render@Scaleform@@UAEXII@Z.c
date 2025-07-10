void __thiscall Scaleform::Render::FilterBundle::RemoveEntries(
        Scaleform::Render::FilterBundle *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::FilterPrimitive::Remove(&this->Prim, index, count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}
