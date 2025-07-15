char __thiscall Scaleform::GFx::AS3::XMLSupportImpl::Add(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::XMLList *l,
        Scaleform::GFx::AS3::Instances::fl::XML *r)
{
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // ebp
  Scaleform::GFx::AS3::Traits *v6; // eax
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // esi
  Scaleform::GFx::AS3::BuiltinTraitsType v8; // edi
  __int32 v9; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // ebx

  pObject = r->pTraits.pObject;
  v5 = l;
  v6 = l->pTraits.pObject;
  TraitsType = v6->TraitsType;
  v8 = pObject->TraitsType;
  if ( TraitsType != Traits_XML && TraitsType != Traits_XMLList
    || (v6->Flags & 0x20) != 0
    || v8 != Traits_XML && v8 != Traits_XMLList
    || (pObject->Flags & 0x20) != 0 )
  {
    return 0;
  }
  Scaleform::GFx::AS3::XMLSupportImpl::MakeXMLList(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&l);
  v9 = TraitsType - 13;
  v10 = l;
  if ( v9 )
  {
    if ( v9 == 1 )
      Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(l, v5);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(l, (Scaleform::GFx::AS3::Instances::fl::XML *)v5);
  }
  if ( v8 == Traits_XML )
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v10, r);
  else
    Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(v10, (Scaleform::GFx::AS3::Instances::fl::XMLList *)r);
  Scaleform::GFx::AS3::Value::Pick(result, v10);
  return 1;
}
