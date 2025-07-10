void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setModalClip(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *mc,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::MovieImpl *v5; // ecx

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
  {
    v5 = (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
    if ( mc )
      Scaleform::GFx::MovieImpl::SetModalClip(v5, (Scaleform::GFx::Sprite *)mc->pDispObj.pObject, controllerIdx);
    else
      Scaleform::GFx::MovieImpl::SetModalClip(v5, 0, controllerIdx);
  }
}
