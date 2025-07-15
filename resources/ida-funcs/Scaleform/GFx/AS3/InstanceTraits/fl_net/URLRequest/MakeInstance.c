Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v3; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  int p_EmptyStringNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *v6; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    pObject = v3->pTraits.pObject;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest_vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::URLRequest::`vftable';
    p_EmptyStringNode = (int)&pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    v3->Url.pNode = (Scaleform::GFx::ASStringNode *)p_EmptyStringNode;
    ++*(_DWORD *)(p_EmptyStringNode + 12);
    v6 = result;
    v3->DataObj.pObject = 0;
    result->pV = v3;
  }
  else
  {
    v6 = result;
    result->pV = 0;
  }
  return v6;
}
