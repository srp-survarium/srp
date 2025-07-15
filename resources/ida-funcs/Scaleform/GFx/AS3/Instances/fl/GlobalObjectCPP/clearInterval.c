void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::clearInterval(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int id)
{
  Scaleform::GFx::MovieImpl::ClearIntervalTimer(
    (Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
    id);
}
