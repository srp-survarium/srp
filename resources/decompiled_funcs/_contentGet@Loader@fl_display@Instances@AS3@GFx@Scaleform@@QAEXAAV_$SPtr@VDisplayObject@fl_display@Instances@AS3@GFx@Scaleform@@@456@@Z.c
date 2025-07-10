void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::contentGet(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax

  if ( this->pDispObj.pObject[1].pRenNode.pObject )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::getChildAt(this, result, 0);
  }
  else
  {
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
        result->pObject = 0;
      }
    }
  }
}
