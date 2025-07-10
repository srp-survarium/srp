void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocusGroupMask(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj)
{
  if ( LOBYTE(this->pTraits.pObject->pVM[1].ExceptionObj.Bonus.pWeakProxy) )
    *result = Scaleform::GFx::InteractiveObject::GetFocusGroupMask((Scaleform::GFx::InteractiveObject *)obj->pDispObj.pObject);
}
