void __thiscall Scaleform::GFx::TextField::SetTextColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::MemoryHeap *v3; // edi
  Scaleform::Render::Text::DocView *pObject; // ecx
  Scaleform::Render::Text::DocView *v5; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::Text::TextFormat colorTextFmt; // [esp+8h] [ebp-28h] BYREF

  v3 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  colorTextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&colorTextFmt.FontList, v3);
  Scaleform::StringDH::StringDH(&colorTextFmt.Url, v3);
  colorTextFmt.LetterSpacing = 0;
  colorTextFmt.pImageDesc.pObject = 0;
  colorTextFmt.pFontHandle.pObject = 0;
  colorTextFmt.FormatFlags = 0;
  colorTextFmt.FontSize = 0;
  colorTextFmt.ColorV = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & rgb | 0xFF000000;
  pObject = this->pDocument.pObject;
  colorTextFmt.PresentMask = 1;
  Scaleform::Render::Text::DocView::SetTextFormat(pObject, &colorTextFmt, 0, 0xFFFFFFFF);
  Scaleform::Render::Text::TextFormat::operator=(
    &colorTextFmt,
    this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
  v5 = this->pDocument.pObject;
  colorTextFmt.PresentMask |= 1u;
  colorTextFmt.ColorV = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & rgb | colorTextFmt.ColorV & 0xFF000000;
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v5->pDocument.pObject, &colorTextFmt);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::Render::Text::TextFormat::~TextFormat(&colorTextFmt);
}
