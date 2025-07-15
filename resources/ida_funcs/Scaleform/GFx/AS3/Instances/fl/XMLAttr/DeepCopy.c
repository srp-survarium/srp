Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v6; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v8; // eax

  pObject = this->Ns.pObject;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)v5->pVM->MHeap->Alloc(v5->pVM->MHeap, 48u, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(v6, v5, pObject, &this->Text, &this->Data, parent);
    result->pV = v7;
    return result;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}
