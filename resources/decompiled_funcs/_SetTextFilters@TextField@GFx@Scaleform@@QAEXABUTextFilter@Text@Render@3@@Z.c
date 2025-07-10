void __thiscall Scaleform::GFx::TextField::SetTextFilters(
        Scaleform::GFx::TextField *this,
        const Scaleform::Render::Text::TextFilter *f)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  Scaleform::Render::Text::TextFilter *p_Filter; // esi
  Scaleform::Render::TreeText *RenderNode; // eax

  pObject = this->pDocument.pObject;
  if ( pObject )
  {
    p_Filter = &pObject->Filter;
    if ( !Scaleform::Render::Text::TextFilter::operator==(&pObject->Filter, f) )
    {
      Scaleform::Render::Text::TextFilter::operator=(p_Filter, f);
      RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
      Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    }
  }
}
