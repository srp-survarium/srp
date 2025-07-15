void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::unescapeMultiByte(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::unescapeMultiByteInternal(this->pTraits.pObject->pVM, result, value);
}
