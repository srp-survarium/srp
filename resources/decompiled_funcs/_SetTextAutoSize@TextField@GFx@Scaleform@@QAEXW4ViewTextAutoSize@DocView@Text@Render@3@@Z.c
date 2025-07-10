void __thiscall Scaleform::GFx::TextField::SetTextAutoSize(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Text::DocView::ViewTextAutoSize va)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  pObject->RTFlags |= 1u;
  pObject->AlignProps ^= (pObject->AlignProps ^ (16 * va)) & 0x30;
}
