Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::`vftable';
    v3->BytesLoaded = 0;
    v3->BytesTotal = 0;
    v3->Content.pObject = 0;
    v3->pLoader.pObject = 0;
    v3->AppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(v3->pTraits.pObject->pVM);
    v4 = result;
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
