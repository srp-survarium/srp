void __thiscall Scaleform::GFx::TextField::SetShadowColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  unsigned int v2; // eax
  Scaleform::Render::TreeText *RenderNode; // eax

  this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw = rgb & 0xFFFFFF
                                                             | (this->pDocument.pObject->Filter.ShadowAlpha << 24);
  if ( this->pShadow )
  {
    v2 = this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF;
    this->pShadow->ShadowColor.Channels.Blue = this->pDocument.pObject->Filter.ShadowParams.Colors[0].Channels.Blue;
    this->pShadow->ShadowColor.Channels.Green = BYTE1(v2);
    this->pShadow->ShadowColor.Channels.Red = BYTE2(v2);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
