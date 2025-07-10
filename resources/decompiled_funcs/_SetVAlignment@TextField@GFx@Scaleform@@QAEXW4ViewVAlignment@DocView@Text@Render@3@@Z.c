void __thiscall Scaleform::GFx::TextField::SetVAlignment(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Text::DocView::ViewVAlignment va)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  pObject->RTFlags |= 1u;
  pObject->AlignProps ^= (pObject->AlignProps ^ (4 * va)) & 0xC;
}
