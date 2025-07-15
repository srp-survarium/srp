void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::~LoaderInfo(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::Loader *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // ecx
  unsigned int v5; // eax

  pObject = this->pLoader.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Loader *)((char *)pObject - 1);
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
  v4 = this->Content.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->Content.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
      return;
    }
    v5 = v4->RefCount;
    if ( (v5 & 0x3FFFFF) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
}
