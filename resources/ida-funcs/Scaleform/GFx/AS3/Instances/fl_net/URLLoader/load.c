void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::load(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request)
{
  Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    request,
    this,
    LM_None);
}
