void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::escapeMultiByte(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::escapeMultiByteInternal(this->pTraits.pObject->pVM, result, value);
}
