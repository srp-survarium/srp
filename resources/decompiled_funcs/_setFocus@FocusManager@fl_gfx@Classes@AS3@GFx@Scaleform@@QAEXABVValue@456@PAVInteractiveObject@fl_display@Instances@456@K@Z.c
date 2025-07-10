void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocus(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::RefCountNTSImpl *obj,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::Sprite *v5; // edi
  Scaleform::GFx::DisplayObject *v6; // eax
  unsigned int v7; // ebp
  Scaleform::RefCountNTSImpl *v8; // esi

  pVM = this->pTraits.pObject->pVM;
  v5 = 0;
  if ( obj )
  {
    v6 = (Scaleform::GFx::DisplayObject *)obj[6].__vftable;
    if ( v6 )
      ++v6->RefCount;
    v5 = (Scaleform::GFx::Sprite *)v6;
  }
  v7 = controllerIdx;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM
  + 16 * *((unsigned __int8 *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + controllerIdx + 16212)
  + 3801,
    (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&obj);
  v8 = obj;
  if ( obj )
  {
    ++obj->RefCount;
    Scaleform::RefCountNTSImpl::Release(v8);
  }
  if ( v8 != v5 )
    Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
      (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
      v5,
      v7,
      GFx_FocusMovedByAS);
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
}
