Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::`vftable';
    v3[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_vtbl *)&Scaleform::GFx::Text::StyleManager::`vftable';
    v3[1].pRCCRaw = 0;
    v3[1].pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)2;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)&v3[1].12);
    v4 = result;
    v3[1].pTraits.pObject = 0;
    result->pV = (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
