Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->V.ValueA.Data.Data,
    this->V.ValueA.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->V.ValueA.Data.Data);
  this->V.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
