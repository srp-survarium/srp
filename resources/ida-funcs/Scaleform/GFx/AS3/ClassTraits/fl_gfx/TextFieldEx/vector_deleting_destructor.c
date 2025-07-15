Scaleform::GFx::AS3::ClassTraits::fl_xml::XMLNodeType *__thiscall Scaleform::GFx::AS3::ClassTraits::fl_gfx::TextFieldEx::`vector deleting destructor'(
        Scaleform::GFx::AS3::ClassTraits::fl_xml::XMLNodeType *this,
        char a2)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->ITraits.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
