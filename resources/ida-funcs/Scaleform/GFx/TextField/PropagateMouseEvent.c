void __thiscall Scaleform::GFx::TextField::PropagateMouseEvent(
        Scaleform::GFx::TextField *this,
        const Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int ControllerIndex; // eax
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v5; // ecx
  Scaleform::GFx::TextField *pObject; // ecx
  unsigned __int8 AvmObjOffset; // al
  int v8; // eax
  Scaleform::Render::Text::EditorKitBase *v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // ebx
  Scaleform::GFx::TextField::CSSHolderBase *v12; // ecx
  float *v13; // ebx
  Scaleform::GFx::MouseState *MouseState; // ebx
  bool v15; // zf
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // eax
  char IsUrlUnderMouseCursor; // al
  unsigned int v20; // eax
  unsigned int (__thiscall *GetCursorType)(Scaleform::GFx::InteractiveObject *); // edx
  unsigned int v22; // eax
  unsigned int v23; // ebx
  Scaleform::GFx::TextField::CSSHolderBase *v24; // ecx
  Scaleform::GFx::MouseState *v25; // ebx
  Scaleform::GFx::MovieImpl *v26; // [esp+20h] [ebp-3Ch]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+24h] [ebp-38h] BYREF
  Scaleform::GFx::MouseState *v28; // [esp+28h] [ebp-34h]
  Scaleform::Render::Point<float> x; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::Render::Point<float> p; // [esp+34h] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> v31; // [esp+3Ch] [ebp-20h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  v26 = pMovieImpl;
  if ( pMovieImpl && (this->pDef.pObject->Flags & 0x1000) == 0 )
  {
    if ( id->Id == 8 )
      Scaleform::GFx::InteractiveObject::DoMouseDrag(this, id->ControllerIndex);
    ControllerIndex = id->ControllerIndex;
    if ( ControllerIndex < 6 )
      v5 = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->mMouseState[ControllerIndex];
    else
      v5 = 0;
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      v5,
      &result);
    pObject = (Scaleform::GFx::TextField *)result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(pObject);
      pObject = (Scaleform::GFx::TextField *)result.pObject;
    }
    if ( pObject != this || id->Id == 0x4000 )
    {
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v8 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + AvmObjOffset)
                                           + 16))(
               (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
             + 4 * AvmObjOffset);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 96))(v8)
          && (this->Flags & 2) != 0
          && (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
        {
          Scaleform::GFx::TextField::ChangeUrlFormat(
            this,
            Link_release,
            (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
            0);
          Scaleform::GFx::TextField::ChangeUrlFormat(
            this,
            Link_rollout,
            (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
            0);
        }
        pObject = (Scaleform::GFx::TextField *)result.pObject;
      }
    }
    if ( pObject != this )
    {
      v9 = this->pDocument.pObject->pEditorKit.pObject;
      if ( !v9 || ((int)v9[16].__vftable & 0x20) == 0 )
        goto LABEL_68;
    }
    if ( !this->GetVisible(this) )
      goto LABEL_69;
    v10 = id->Id;
    if ( id->Id > 0x20 )
    {
      if ( v10 != 4096 )
        goto LABEL_68;
    }
    else if ( id->Id != 32 )
    {
      if ( v10 == 8 )
      {
        MouseState = Scaleform::GFx::MovieImpl::GetMouseState(pMovieImpl, id->ControllerIndex);
        v15 = this->pDocument.pObject->pEditorKit.pObject == 0;
        v28 = MouseState;
        if ( !v15 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, &v31);
          p.x = MouseState->LastPosition.x;
          p.y = MouseState->LastPosition.y;
          Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v31, &x, &p);
          Scaleform::GFx::Text::EditorKit::OnMouseMove(
            (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
            x.x,
            x.y);
        }
        if ( Scaleform::GFx::TextField::HasStyleSheet(this)
          && (this->Flags & 2) != 0
          && (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
        {
          v16 = id->ControllerIndex;
          p.x = 0.0;
          p.y = 0.0;
          LOBYTE(x.x) = Scaleform::GFx::TextField::IsUrlUnderMouseCursor(this, v16, 0, (Scaleform::Range *)&p);
          if ( LOBYTE(x.x) )
          {
            v17 = id->ControllerIndex;
            if ( !Scaleform::GFx::TextField::IsUrlTheSame(this, v17, (const Scaleform::Range *)&p) )
            {
              Scaleform::GFx::TextField::ChangeUrlFormat(
                this,
                Link_release,
                (Scaleform::Render::Text::TextFormat *)v17,
                0);
              Scaleform::GFx::TextField::ChangeUrlFormat(
                this,
                Link_rollout,
                (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
                0);
            }
            Scaleform::GFx::TextField::ChangeUrlFormat(
              this,
              (Scaleform::GFx::TextField::LinkEvent)(~(2 * (unsigned __int8)v28->CurButtonsState) & 2),
              (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
              (const Scaleform::Range *)&p);
          }
          else
          {
            Scaleform::GFx::TextField::ChangeUrlFormat(
              this,
              Link_release,
              (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
              0);
            Scaleform::GFx::TextField::ChangeUrlFormat(
              this,
              Link_rollout,
              (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
              0);
          }
          Scaleform::GFx::TextField::SetHandCursor(this, SLOBYTE(x.x));
          v18 = this->GetCursorType(this);
          Scaleform::GFx::MovieImpl::ChangeMouseCursorType(v26, id->ControllerIndex, v18);
        }
        else if ( (this->Flags & 2) != 0 && (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
        {
          IsUrlUnderMouseCursor = Scaleform::GFx::TextField::IsUrlUnderMouseCursor(this, id->ControllerIndex, 0, 0);
          Scaleform::GFx::TextField::SetHandCursor(this, IsUrlUnderMouseCursor);
          v20 = this->GetCursorType(this);
          Scaleform::GFx::MovieImpl::ChangeMouseCursorType(v26, id->ControllerIndex, v20);
        }
        else if ( (this->Flags & 0x20) != 0 )
        {
          Scaleform::GFx::TextField::ChangeUrlFormat(
            this,
            Link_rollout,
            (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
            0);
          GetCursorType = this->GetCursorType;
          this->Flags &= ~0x20u;
          v22 = GetCursorType(this);
          Scaleform::GFx::MovieImpl::ChangeMouseCursorType(v26, id->ControllerIndex, v22);
        }
        goto LABEL_68;
      }
      if ( v10 == 16 )
      {
        if ( Scaleform::GFx::TextField::HasStyleSheet(this)
          && (this->Flags & 2) != 0
          && (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
        {
          v11 = id->ControllerIndex;
          v28 = Scaleform::GFx::MovieImpl::GetMouseState(v26, v11);
          p.x = 0.0;
          p.y = 0.0;
          if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(this, v11, 0, (Scaleform::Range *)&p) )
          {
            v12 = this->pCSSData.pObject;
            if ( v12 )
            {
              if ( v12->HasASStyleSheet(v12) && (v28->CurButtonsState & 1) != 0 )
                Scaleform::GFx::TextField::ChangeUrlFormat(
                  this,
                  Link_press,
                  (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
                  (const Scaleform::Range *)&p);
            }
          }
          pMovieImpl = v26;
        }
        if ( this->pDocument.pObject->pEditorKit.pObject )
        {
          v13 = (float *)Scaleform::GFx::MovieImpl::GetMouseState(pMovieImpl, id->ControllerIndex);
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, &v31);
          p.x = v13[8];
          p.y = v13[9];
          Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v31, &x, &p);
          Scaleform::GFx::Text::EditorKit::OnMouseDown(
            (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
            x.x,
            x.y,
            v13[6]);
LABEL_65:
          if ( !Scaleform::GFx::InteractiveObject::IsInPlayList(this) )
            Scaleform::GFx::InteractiveObject::AddToPlayList(this);
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(this);
        }
      }
LABEL_68:
      this->OnEvent(this, id);
LABEL_69:
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      return;
    }
    if ( Scaleform::GFx::TextField::HasStyleSheet(this)
      && (this->Flags & 2) != 0
      && (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
    {
      v23 = id->ControllerIndex;
      LODWORD(x.x) = Scaleform::GFx::MovieImpl::GetMouseState(v26, v23);
      p.x = 0.0;
      p.y = 0.0;
      if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(this, v23, 0, (Scaleform::Range *)&p) )
      {
        v24 = this->pCSSData.pObject;
        if ( v24 )
        {
          if ( v24->HasASStyleSheet(v24) && (*(_BYTE *)(LODWORD(x.x) + 24) & 1) == 0 )
            Scaleform::GFx::TextField::ChangeUrlFormat(
              this,
              Link_release,
              (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
              (const Scaleform::Range *)&p);
        }
      }
      Scaleform::GFx::TextField::ChangeUrlFormat(
        this,
        Link_release,
        (Scaleform::Render::Text::TextFormat *)id->ControllerIndex,
        0);
      pMovieImpl = v26;
    }
    if ( !this->pDocument.pObject->pEditorKit.pObject )
      goto LABEL_68;
    v25 = Scaleform::GFx::MovieImpl::GetMouseState(pMovieImpl, id->ControllerIndex);
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, &v31);
    p.x = v25->LastPosition.x;
    p.y = v25->LastPosition.y;
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v31, &x, &p);
    Scaleform::GFx::Text::EditorKit::OnMouseUp(
      (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
      x.x,
      x.y,
      v25->CurButtonsState);
    goto LABEL_65;
  }
}
