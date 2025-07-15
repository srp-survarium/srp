Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *__thiscall Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->RelatedObj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->RelatedObj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)((char *)pObject - 1);
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
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
