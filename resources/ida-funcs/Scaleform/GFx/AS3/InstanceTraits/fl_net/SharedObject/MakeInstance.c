Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject_vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::SharedObject::`vftable';
    v3->DataObj.pObject = 0;
    Scaleform::String::String(&v3->Name);
    Scaleform::String::String(&v3->LocalPath);
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
