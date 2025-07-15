Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObject::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript_vtbl *)&Scaleform::GFx::AS3::Instances::fl::GlobalObject::`vftable';
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
