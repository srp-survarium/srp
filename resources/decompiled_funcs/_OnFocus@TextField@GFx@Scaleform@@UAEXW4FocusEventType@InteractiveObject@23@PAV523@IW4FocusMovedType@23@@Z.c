void __thiscall Scaleform::GFx::TextField::OnFocus(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::InteractiveObject::FocusEventType event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int16 Flags; // ax
  Scaleform::Render::Text::DocView *pObject; // edx
  Scaleform::Render::Text::EditorKitBase *v8; // ecx
  char v9; // al
  Scaleform::GFx::InteractiveObject::FocusEventType v10; // ebx
  int Length; // eax
  Scaleform::Render::Text::DocView *v12; // edx
  Scaleform::GFx::Text::EditorKit *v13; // ecx
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::RefCountVImpl *v15; // eax
  Scaleform::RefCountVImpl *v16; // edi
  Scaleform::GFx::TextField_vtbl *v17; // ebx
  Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  const Scaleform::Render::Rect<float> *v19; // eax
  Scaleform::Render::Text::EditorKitBase *v20; // eax
  Scaleform::Render::TreeText *v21; // eax
  Scaleform::RefCountVImpl *v22; // eax
  Scaleform::RefCountVImpl *v23; // edi
  Scaleform::Render::Text::EditorKitBase *v24; // ecx
  bool v25; // al
  Scaleform::Render::Text::EditorKitBase *v26; // eax
  char v27; // al
  Scaleform::Render::Text::EditorKitBase *v28; // ecx
  Scaleform::Render::Rect<float> v29; // [esp+50h] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> v30; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+70h] [ebp-20h] BYREF

  Flags = this->pDef.pObject->Flags;
  if ( (Flags & 0x1000) == 0 )
  {
    pObject = this->pDocument.pObject;
    v8 = pObject->pEditorKit.pObject;
    if ( v8 )
      v9 = LOBYTE(v8[16].__vftable) >> 1;
    else
      v9 = (unsigned __int8)Flags >> 5;
    v10 = event;
    if ( (v9 & 1) != 0 )
    {
      if ( event == MouseMove )
      {
        if ( (this->Flags & 0x400) == 0 && fmt == GFx_FocusMovedByKeyboard )
        {
          Length = Scaleform::Render::Text::StyledText::GetLength(pObject->pDocument.pObject);
          Scaleform::GFx::TextField::SetSelection(this, 0, Length);
        }
        v12 = this->pDocument.pObject;
        this->FocusedControllerIdx = controllerIdx;
        v13 = (Scaleform::GFx::Text::EditorKit *)v12->pEditorKit.pObject;
        if ( v13 )
        {
          Scaleform::GFx::Text::EditorKit::OnSetFocus(v13);
          RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
          Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
          v15 = (Scaleform::RefCountVImpl *)this->pASRoot->pMovieImpl->GetStateAddRef(
                                              &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                              8);
          v16 = v15;
          if ( v15 )
          {
            Scaleform::RefCountImpl::Release(v15);
            v17 = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
            WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, &result);
            v19 = v17->GetBounds(this, &v30, WorldMatrix);
            Scaleform::Render::TwipsToPixels(&v29, v19);
            ((void (__thiscall *)(Scaleform::RefCountVImpl *, bool, Scaleform::Render::Rect<float> *))v16->AddRef)(
              v16,
              (this->pDocument.pObject->Flags & 4) != 0,
              &v29);
            v10 = MouseMove;
          }
        }
      }
      else if ( event == Unknown )
      {
        this->FocusedControllerIdx = -1;
        v20 = pObject->pEditorKit.pObject;
        if ( v20 )
        {
          if ( (this->Flags & 0x200) == 0 )
            Scaleform::Render::Text::DocView::SetSelection(
              (Scaleform::Render::Text::DocView *)v20[1].__vftable,
              0,
              0,
              1);
          Scaleform::GFx::Text::EditorKit::OnKillFocus((Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject);
          v21 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
          Scaleform::Render::TreeText::NotifyLayoutChanged(v21);
          v22 = (Scaleform::RefCountVImpl *)this->pASRoot->pMovieImpl->GetStateAddRef(
                                              &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                              8);
          v23 = v22;
          if ( v22 )
          {
            Scaleform::RefCountImpl::Release(v22);
            v23->Release(v23);
          }
        }
      }
    }
    v24 = this->pDocument.pObject->pEditorKit.pObject;
    if ( v24 )
      v25 = v24->IsReadOnly(v24);
    else
      v25 = (this->pDef.pObject->Flags & 8) != 0;
    if ( !v25
      || ((v26 = this->pDocument.pObject->pEditorKit.pObject) == 0
        ? (v27 = LOBYTE(this->pDef.pObject->Flags) >> 5)
        : (v27 = LOBYTE(v26[16].__vftable) >> 1),
          (v27 & 1) != 0) )
    {
      if ( v10 == MouseMove )
        Scaleform::GFx::TextField::ResetBlink(this, 1, 1);
      else
        Scaleform::GFx::TextField::ResetBlink(this, 0, 0);
      Scaleform::GFx::InteractiveObject::OnFocus(this, v10, oldOrNewFocusCh, controllerIdx, fmt);
      v28 = this->pDocument.pObject->pEditorKit.pObject;
      if ( v28 && !v28->IsReadOnly(v28) )
      {
        this->Flags |= 0x4000u;
        if ( !Scaleform::GFx::InteractiveObject::IsInPlayList(this) )
          Scaleform::GFx::InteractiveObject::AddToPlayList(this);
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(this);
      }
    }
    else if ( v10 == Unknown || this->IsFocusEnabled(this, fmt) )
    {
      Scaleform::GFx::InteractiveObject::OnFocus(this, v10, oldOrNewFocusCh, controllerIdx, fmt);
    }
  }
}
