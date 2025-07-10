void __thiscall Scaleform::GFx::TextField::SetShadowColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  unsigned int v2; // eax
  Scaleform::Render::TreeText *RenderNode; // eax

  this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & rgb
                                                             | (this->pDocument.pObject->Filter.ShadowAlpha << 24);
  if ( this->pShadow )
  {
    v2 = (unsigned int)&vostok::memory::s_CRT_arena[5574199]
       & this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw;
    *(_WORD *)this->pShadow = v2;
    this->pShadow->ShadowColor.Channels.Red = BYTE2(v2);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
