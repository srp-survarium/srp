void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  char *pClassName; // edx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax

  pClassName = (char *)this->pClassName;
  this->__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pClassName);
  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      this->__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
      return;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
}
