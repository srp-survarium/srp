Scaleform::GFx::AS3::Instances::fl_display::Stage *__thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::Stage_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable';
  pObject = this->pContextMenu.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pContextMenu.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
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
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
