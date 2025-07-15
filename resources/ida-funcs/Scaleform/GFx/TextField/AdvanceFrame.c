void __thiscall Scaleform::GFx::TextField::AdvanceFrame(
        Scaleform::GFx::TextField *this,
        bool nextFrame,
        float framePos)
{
  unsigned __int8 v4; // al
  char v5; // bl
  Scaleform::Render::Text::DocView *pObject; // ecx
  unsigned int Flags; // eax
  unsigned int v8; // ecx
  bool v9; // al
  int v10; // eax
  unsigned __int8 AvmObjOffset; // al
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  unsigned __int8 v15; // al
  int v16; // eax
  Scaleform::Render::Text::EditorKitBase *v17; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::Render::TreeText *RenderNode; // eax

  v4 = this->GetStateChangeFlags(this);
  v5 = 0;
  if ( (v4 & 0xF) != 0 || (this->pASRoot->pMovieImpl->Flags2 & 2) != 0 )
  {
    pObject = this->pDocument.pObject;
    if ( pObject )
    {
      this->Scaleform::GFx::InteractiveObject::Flags &= ~0x100000u;
      pObject->RTFlags |= 2u;
      this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
      if ( (v4 & 8) != 0 )
      {
        Scaleform::GFx::TextField::TextDocumentListener::TranslatorChanged(&this->TextDocListener);
        Scaleform::GFx::TextField::SetTextValue(
          this,
          (char *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC) + 8),
          (this->Flags & 0x1000) != 0,
          1);
        v5 = 1;
      }
    }
  }
  Flags = this->Flags;
  this->Scaleform::GFx::InteractiveObject::Flags &= 0xFFF0FFFF;
  v8 = this->Scaleform::GFx::InteractiveObject::Flags;
  if ( (Flags & 0x4000) != 0 )
  {
    this->Flags = Flags & 0xFFFFBFFF;
    v9 = (v8 & 0x200000) != 0 && (v8 & 0x400000) == 0;
    v10 = Scaleform::GFx::TextField::CheckAdvanceStatus(this, v9);
    if ( v10 == -1 )
    {
      this->Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
    }
    else if ( v10 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
    }
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v12 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + AvmObjOffset)
                                        + 16))(
            (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * AvmObjOffset);
    v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 92))(v12);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 20);
      if ( v14 == 2 )
      {
        *(_DWORD *)(v13 + 20) = 0;
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(this);
        if ( !v5 )
        {
          this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
          Scaleform::GFx::TextField::SetTextValue(
            this,
            (char *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC) + 8),
            (this->Flags & 0x1000) != 0,
            1);
        }
      }
      else if ( v14 == 3 )
      {
        *(_DWORD *)(v13 + 20) = 0;
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(this);
      }
    }
  }
  if ( nextFrame )
  {
    if ( (this->Flags & 0x8000) != 0 )
    {
      v15 = this->AvmObjOffset;
      if ( v15 )
      {
        v16 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + v15)
                                            + 16))(
                (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + 4 * v15);
        (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 120))(v16);
      }
    }
    this->Flags |= 0x40u;
  }
  else
  {
    this->Flags &= ~0x40u;
  }
  v17 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v17 )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsFocused(pMovieImpl, this) || ((int)v17[16].__vftable & 0x20) != 0 )
      Scaleform::GFx::Text::EditorKit::Advance(
        (Scaleform::GFx::Text::EditorKit *)v17,
        (double)pMovieImpl->TimeElapsed / 1000000.0);
  }
  if ( (this->Flags & 0x10000) != 0 )
  {
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
}
