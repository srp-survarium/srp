void __thiscall Scaleform::GFx::TextField::ResetBlink(Scaleform::GFx::TextField *this, bool state, bool blocked)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  Scaleform::Render::TreeText *RenderNode; // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
  {
    if ( !pObject->IsReadOnly(pObject) )
    {
      Scaleform::GFx::Text::EditorKit::ResetBlink(
        (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
        state,
        blocked);
      RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
      Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    }
  }
}
