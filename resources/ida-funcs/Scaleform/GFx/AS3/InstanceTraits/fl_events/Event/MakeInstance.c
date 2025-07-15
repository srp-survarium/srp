Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::Event *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v2; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v3; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  int p_EmptyStringNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *v6; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    pObject = v3->pTraits.pObject;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
    p_EmptyStringNode = (int)&pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    v3[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Object_vtbl *)p_EmptyStringNode;
    ++*(_DWORD *)(p_EmptyStringNode + 12);
    v6 = result;
    v3[1].pRCCRaw = 0;
    v3[1].pNext = 0;
    LOBYTE(v3[1].RefCount) &= 0xC0u;
    v3[1].pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)2;
    result->pV = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v3;
  }
  else
  {
    v6 = result;
    result->pV = 0;
  }
  return v6;
}
