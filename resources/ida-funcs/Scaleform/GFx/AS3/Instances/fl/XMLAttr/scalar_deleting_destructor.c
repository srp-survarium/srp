Scaleform::GFx::AS3::Instances::fl::XMLAttr *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::XMLAttr::~XMLAttr(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
