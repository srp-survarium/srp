void __thiscall Scaleform::GFx::TextField::TextDocumentListener::View_OnChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *editor)
{
  Scaleform::Render::TreeText *RenderNode; // eax

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this[-15].HandlersMask);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
