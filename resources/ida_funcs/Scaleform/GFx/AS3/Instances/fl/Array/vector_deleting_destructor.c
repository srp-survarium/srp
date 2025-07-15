Scaleform::GFx::AS3::Instances::fl::Array *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        char a2)
{
  Scaleform::GFx::AS3::Impl::SparseArray::~SparseArray(&this->SA);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
