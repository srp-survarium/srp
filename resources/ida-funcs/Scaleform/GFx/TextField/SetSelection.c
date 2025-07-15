void __thiscall Scaleform::GFx::TextField::SetSelection(Scaleform::GFx::TextField *this, int beginIndex, int endIndex)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  signed int v5; // esi
  signed int v6; // edi
  signed int Length; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [esp+4h] [ebp-4h] BYREF

  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, (int)this, (int)&result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  }
  pObject = this->pDocument.pObject;
  if ( pObject->pEditorKit.pObject )
  {
    v5 = beginIndex;
    if ( beginIndex < 0 )
      v5 = 0;
    v6 = endIndex;
    if ( endIndex < 0 )
      v6 = 0;
    Length = Scaleform::Render::Text::StyledText::GetLength(pObject->pDocument.pObject);
    if ( Length < v5 )
      v5 = Length;
    if ( Length < v6 )
      v6 = Length;
    Scaleform::GFx::Text::EditorKit::SetSelection(
      (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
      v5,
      v6);
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
}
