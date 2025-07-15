void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocusGroupMask(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj,
        unsigned int mask)
{
  if ( *(&this->pTraits.pObject->pVM[1].HandleException + 4) )
  {
    if ( obj )
      ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, unsigned int))obj->pDispObj.pObject->Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::__vftable[1].SetY)(
        obj->pDispObj.pObject,
        mask);
  }
}
