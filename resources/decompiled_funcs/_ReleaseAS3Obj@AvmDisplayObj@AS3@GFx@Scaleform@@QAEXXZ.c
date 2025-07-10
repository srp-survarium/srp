void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::ReleaseAS3Obj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      this->pAS3CollectiblePtr.pObject = 0;
      this->pAS3RawPtr = 0;
      return;
    }
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
    this->pAS3CollectiblePtr.pObject = 0;
  }
  this->pAS3RawPtr = 0;
}
