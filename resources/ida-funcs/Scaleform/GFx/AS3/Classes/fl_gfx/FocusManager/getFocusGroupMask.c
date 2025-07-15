void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocusGroupMask(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj)
{
  if ( *(&this->pTraits.pObject->pVM[1].HandleException + 4) )
    *result = Scaleform::GFx::InteractiveObject::GetFocusGroupMask((Scaleform::GFx::InteractiveObject *)obj->pDispObj.pObject);
}
