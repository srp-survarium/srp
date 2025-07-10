void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::~Loader(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // ecx
  unsigned int v5; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::Loader_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Loader::`vftable';
  pObject = this->pContentLoaderInfo.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pContentLoaderInfo.pObject = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)pObject - 1);
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
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::Loader_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable';
  v4 = this->pContextMenu.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->pContextMenu.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
      return;
    }
    v5 = v4->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
}
