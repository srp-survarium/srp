Scaleform::GFx::AS3::Instances::fl::XMLList *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList::~XMLList(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
