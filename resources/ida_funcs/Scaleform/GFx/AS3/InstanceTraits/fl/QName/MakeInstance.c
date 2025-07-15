Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::QName *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        const Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Instance *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::QName *v6; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *v8; // eax

  v5 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v6 = (Scaleform::GFx::AS3::Instances::fl::QName *)v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, t);
    v6->__vftable = (Scaleform::GFx::AS3::Instances::fl::QName_vtbl *)&Scaleform::GFx::AS3::Instances::fl::QName::`vftable';
    pNode = n->pNode;
    v6->LocalName = (Scaleform::GFx::ASString)n->pNode;
    ++pNode->RefCount;
    v6->Ns.pObject = ns;
    if ( ns )
      ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
    v8 = result;
    result->pV = v6;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}
