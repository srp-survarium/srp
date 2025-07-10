void __thiscall Scaleform::Render::ComplexPrimitiveBundle::RemoveEntries(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    &this->Instances,
    index,
    count);
  Scaleform::Render::Bundle::RemoveEntries(this, index, count);
}
