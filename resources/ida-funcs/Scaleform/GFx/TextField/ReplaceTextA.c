void __thiscall Scaleform::GFx::TextField::ReplaceTextA(
        Scaleform::GFx::TextField *this,
        const wchar_t *ptext,
        unsigned int beginPos,
        unsigned int endPos,
        unsigned int textLen)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  unsigned int Length; // edi
  unsigned __int8 AvmObjOffset; // al
  int v9; // eax
  unsigned __int8 v10; // al
  int v11; // eax
  Scaleform::Render::TreeText *RenderNode; // eax

  Scaleform::Render::Text::DocView::ReplaceTextA(this->pDocument.pObject, ptext, beginPos, endPos, textLen);
  pObject = this->pDocument.pObject;
  if ( pObject->pEditorKit.pObject )
  {
    Length = Scaleform::Render::Text::StyledText::GetLength(pObject->pDocument.pObject);
    if ( (unsigned int)Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)this->pDocument.pObject->pEditorKit.pObject) > Length )
      Scaleform::GFx::Text::EditorKit::SetCursorPos(
        (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
        Length,
        0);
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v9 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 16))(
           (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(v9);
  }
  v10 = this->AvmObjOffset;
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  if ( v10 )
  {
    v11 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + v10)
                                        + 16))(
            (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * v10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 100))(v11);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
