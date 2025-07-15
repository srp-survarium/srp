void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::describeType(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *value)
{
  this->pTraits.pObject->pVM->XMLSupport_.pObject->DescribeType(
    this->pTraits.pObject->pVM->XMLSupport_.pObject,
    this->pTraits.pObject->pVM,
    result,
    value);
}
