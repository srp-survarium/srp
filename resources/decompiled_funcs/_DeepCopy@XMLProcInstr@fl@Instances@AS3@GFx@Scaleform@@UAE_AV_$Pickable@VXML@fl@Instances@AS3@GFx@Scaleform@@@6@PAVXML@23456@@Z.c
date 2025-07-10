Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // eax

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v5 = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *)pObject->pVM->MHeap->Alloc(pObject->pVM->MHeap, 44u, 0);
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::XMLProcInstr(v5, pObject, &this->Text, &this->Data, parent);
    result->pV = v6;
    return result;
  }
  else
  {
    v7 = result;
    result->pV = 0;
  }
  return v7;
}
