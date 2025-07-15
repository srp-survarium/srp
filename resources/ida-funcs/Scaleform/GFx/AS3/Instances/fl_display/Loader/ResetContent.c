void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::ResetContent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *p_Content; // esi
  unsigned int RefCount; // eax

  pObject = this->pContentLoaderInfo.pObject;
  v2 = pObject->Content.pObject;
  p_Content = &pObject->Content;
  if ( v2 )
  {
    if ( ((unsigned __int8)v2 & 1) != 0 )
    {
      p_Content->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v2 - 1);
      p_Content->pObject = 0;
    }
    else
    {
      RefCount = v2->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v2->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v2);
      }
      p_Content->pObject = 0;
    }
  }
}
