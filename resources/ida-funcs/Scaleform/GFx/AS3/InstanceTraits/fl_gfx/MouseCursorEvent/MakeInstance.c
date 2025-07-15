Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v3; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  int p_EmptyStringNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *v6; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::Event::Event(v2, t);
    pObject = v3->pTraits.pObject;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx::`vftable';
    p_EmptyStringNode = (int)&pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    v3[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)p_EmptyStringNode;
    ++*(_DWORD *)(p_EmptyStringNode + 12);
    *((_BYTE *)v3 + 48) = *((_BYTE *)v3 + 48) & 0xFC | 2;
    v6 = result;
    v3[1].pRCCRaw = 0;
    result->pV = (Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *)v3;
  }
  else
  {
    v6 = result;
    result->pV = 0;
  }
  return v6;
}
