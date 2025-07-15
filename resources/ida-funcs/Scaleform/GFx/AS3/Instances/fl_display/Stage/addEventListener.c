void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::addEventListener(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Value *listener,
        bool useCapture,
        int priority,
        bool useWeakReference)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(
    this,
    result,
    type,
    listener,
    useCapture,
    priority,
    useWeakReference);
  if ( type->pNode == (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].__vftable[46].~Scaleform::GFx::AS3::VM )
    ++*(_DWORD *)&this->pDispObj.pObject[1].Flags;
}
