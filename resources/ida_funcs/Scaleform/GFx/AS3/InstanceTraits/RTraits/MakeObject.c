void __thiscall Scaleform::GFx::AS3::InstanceTraits::RTraits::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // eax

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pParent.pObject;
  if ( !pObject )
    pObject = this->pVM->TraitsObject.pObject->ITraits.pObject;
  pObject->MakeObject(pObject, result, t);
}
