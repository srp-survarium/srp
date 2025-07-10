char __thiscall Scaleform::GFx::TextField::OnCharEvent(
        Scaleform::GFx::TextField *this,
        unsigned int wcharCode,
        unsigned int controllerIdx)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  int v6; // eax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  if ( this->pASRoot->pMovieImpl )
  {
    pObject = this->pDocument.pObject->pEditorKit.pObject;
    if ( pObject )
    {
      if ( (!pObject->IsReadOnly(pObject) || Scaleform::GFx::TextField::IsSelectable(this))
        && this->FocusedControllerIdx == controllerIdx )
      {
        v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + this->AvmObjOffset)
                                           + 16))(
               (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
             + 4 * this->AvmObjOffset);
        if ( (*(unsigned __int8 (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v6 + 112))(
               v6,
               wcharCode,
               controllerIdx) )
        {
          Scaleform::GFx::Text::EditorKit::OnChar(
            (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
            wcharCode);
        }
      }
    }
  }
  return 1;
}
