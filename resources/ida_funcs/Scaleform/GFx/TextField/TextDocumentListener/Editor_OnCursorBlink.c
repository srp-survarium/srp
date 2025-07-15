void __thiscall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnCursorBlink(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *editor,
        bool cursorState)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this[-15].HandlersMask);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
