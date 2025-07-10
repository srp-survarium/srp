Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::DestructArray(
    this->V.ValueA.Data.Data,
    this->V.ValueA.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->V.ValueA.Data.Data);
  this->V.__vftable = (Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
