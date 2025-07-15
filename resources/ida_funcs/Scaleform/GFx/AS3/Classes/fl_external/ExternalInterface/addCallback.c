void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::addCallback(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *functionName,
        const Scaleform::GFx::AS3::Value *closure)
{
  Scaleform::GFx::AS3::MovieRoot::AddInvokeAlias(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].__vftable,
    functionName,
    closure);
}
