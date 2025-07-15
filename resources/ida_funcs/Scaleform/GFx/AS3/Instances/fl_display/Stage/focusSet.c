void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::focusSet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::RefCountNTSImpl *value)
{
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::Sprite *v4; // edi
  Scaleform::GFx::DisplayObject *v5; // eax
  Scaleform::RefCountNTSImpl *v6; // esi

  pVM = this->pTraits.pObject->pVM;
  v4 = 0;
  if ( value )
  {
    v5 = (Scaleform::GFx::DisplayObject *)value[6].__vftable;
    if ( v5 )
      ++v5->RefCount;
    v4 = (Scaleform::GFx::Sprite *)v5;
  }
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM
  + 16 * *((unsigned __int8 *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 16212)
  + 3801,
    (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&value);
  v6 = value;
  if ( value )
  {
    ++value->RefCount;
    Scaleform::RefCountNTSImpl::Release(v6);
  }
  if ( v6 != v4 )
    Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
      (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
      v4,
      0,
      GFx_FocusMovedByAS);
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
}
