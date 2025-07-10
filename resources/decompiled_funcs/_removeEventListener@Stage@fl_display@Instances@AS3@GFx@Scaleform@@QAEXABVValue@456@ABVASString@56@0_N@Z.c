void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::removeEventListener(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *type,
        const Scaleform::GFx::AS3::Value *listener,
        bool useCapture)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::removeEventListener(
    this,
    result,
    type,
    listener,
    useCapture);
  if ( type->pNode == (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].__vftable[46].~Scaleform::GFx::AS3::VM )
    --*(_DWORD *)&this->pDispObj.pObject[1].Flags;
}
