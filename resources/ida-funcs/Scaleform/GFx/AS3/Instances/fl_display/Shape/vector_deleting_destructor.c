Scaleform::GFx::AS3::Instances::fl_display::Shape *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Shape::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::Shape_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Shape::`vftable';
  pObject = this->pGraphics.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pGraphics.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)((char *)pObject - 1);
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
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
