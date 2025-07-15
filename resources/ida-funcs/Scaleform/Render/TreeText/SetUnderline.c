void __thiscall Scaleform::Render::TreeText::SetUnderline(
        Scaleform::Render::TreeText *this,
        bool underline,
        unsigned int startPos,
        unsigned int endPos)
{
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  Scaleform::MemoryHeap *v9; // eax
  int v10; // esi
  const Scaleform::Render::Text::TextFormat *v11; // eax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  Scaleform::Render::Text::TextFormat fmt; // [esp+8h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+30h] [ebp-28h] BYREF

  v5 = *(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                 + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                 + 20);
  v6 = *(_DWORD *)(v5 + 144);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 8);
    v8 = v7[2];
    if ( v8 )
      v9 = *(Scaleform::MemoryHeap **)(v8 + 28);
    else
      v9 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v7);
    Scaleform::Render::Text::TextFormat::TextFormat(&fmt, v9);
    Scaleform::Render::Text::TextFormat::SetUnderline(&fmt, underline);
    Scaleform::Render::Text::DocView::SetTextFormat(
      *(Scaleform::Render::Text::DocView **)(v5 + 144),
      &fmt,
      startPos,
      endPos);
    v10 = *(_DWORD *)(v5 + 144);
    v11 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_DWORD *)(v10 + 8) + 28),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v10 + 8), v11);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
