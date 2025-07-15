void __thiscall Scaleform::GFx::TextField::SetWidth(Scaleform::GFx::TextField *this, long double width)
{
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  Scaleform::Render::Text::DocView *pObject; // ecx
  Scaleform::Render::TreeText *RenderNode; // eax
  float y1; // [esp+8h] [ebp-18h]
  float y2; // [esp+Ch] [ebp-14h]
  float v8; // [esp+Ch] [ebp-14h]
  Scaleform::Render::Rect<float> rect; // [esp+10h] [ebp-10h] BYREF

  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  y1 = ViewRect->y1;
  pObject = this->pDocument.pObject;
  y2 = ViewRect->y2;
  rect.x1 = ViewRect->x1;
  rect.y1 = y1;
  rect.y2 = y2;
  v8 = width * 20.0;
  rect.x2 = v8 + rect.x1;
  Scaleform::Render::Text::DocView::SetViewRect(pObject, &rect, UseExternally);
  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
