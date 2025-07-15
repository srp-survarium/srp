Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data.Data);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
