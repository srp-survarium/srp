Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->V.ValueA.Data.Data);
  this->V.__vftable = (Scaleform::GFx::AS3::VectorBase<double>_vtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
