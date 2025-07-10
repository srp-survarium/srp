void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v3; // eax
  Scaleform::GFx::AS3::Object *v4; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  int p_EmptyStringNode; // eax

  v3 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v4 = &v3->Scaleform::GFx::AS3::Instances::fl::Object;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::Event::Event(v3, t);
    pObject = v4->pTraits.pObject;
    v4->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx::`vftable';
    p_EmptyStringNode = (int)&pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    v4[1].pTraits.pObject = (Scaleform::GFx::AS3::Traits *)p_EmptyStringNode;
    ++*(_DWORD *)(p_EmptyStringNode + 12);
    Scaleform::GFx::AS3::Value::Pick(result, v4);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
