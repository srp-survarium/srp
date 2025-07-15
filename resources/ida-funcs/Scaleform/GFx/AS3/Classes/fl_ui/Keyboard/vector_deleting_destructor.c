Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *__thiscall Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::`vector deleting destructor'(
        Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->CharCodeStrings.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->CharCodeStrings.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Class::~Class(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
