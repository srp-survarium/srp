void __userpurge Scaleform::GFx::TextClipboard::SetStyledText(
        Scaleform::GFx::TextClipboard *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::Text::StyledText *pstyledText)
{
  Scaleform::Render::Text::StyledText *v4; // ecx
  Scaleform::MemoryHeap *v5; // esi
  Scaleform::Render::Text::Allocator *v6; // eax
  Scaleform::Render::Text::Allocator *v7; // eax
  Scaleform::Render::Text::Allocator *v8; // edi
  Scaleform::Render::Text::StyledText *v9; // eax
  Scaleform::Render::Text::StyledText *v10; // eax

  v4 = this->pStyledText;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  v5 = Scaleform::Memory::pGlobalHeap;
  v6 = (Scaleform::Render::Text::Allocator *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               76,
                                               0,
                                               a2);
  if ( v6 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v6, v5, 1u);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = (Scaleform::Render::Text::StyledText *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))v5->Alloc)(v5, 36);
  if ( v9 )
    Scaleform::Render::Text::StyledText::StyledText(v9, v8);
  else
    v10 = 0;
  this->pStyledText = v10;
  Scaleform::Render::Text::StyledText::CopyStyledText(
    pstyledText,
    (Scaleform::Render::Text::Paragraph *)v10,
    0,
    (Scaleform::Render::Text::Paragraph *)0xFFFFFFFF);
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
}
