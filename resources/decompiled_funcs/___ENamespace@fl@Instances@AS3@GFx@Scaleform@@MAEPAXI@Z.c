Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace::~Namespace(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
