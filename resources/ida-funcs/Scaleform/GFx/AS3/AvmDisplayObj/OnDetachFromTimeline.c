void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  this->pAS3RawPtr = pAS3RawPtr;
  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      this->pAS3CollectiblePtr.pObject = 0;
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      this->pAS3CollectiblePtr.pObject = 0;
    }
  }
}
