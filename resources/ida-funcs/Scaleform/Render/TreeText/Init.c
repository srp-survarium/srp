void __userpurge Scaleform::Render::TreeText::Init(
        Scaleform::Render::TreeText *this@<ecx>,
        int a2@<ebx>,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::Allocator *fntMgr,
        Scaleform::GFx::Resource *log,
        Scaleform::GFx::Resource *a6)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // esi
  Scaleform::Render::Text::DocView *v8; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v9; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v10; // ebx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::MemoryHeap *v12; // eax
  int v13; // eax
  Scaleform::Render::ContextImpl::EntryData *v14; // eax
  int v15; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [esp+24h] [ebp-28h] BYREF

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  if ( !WritableData[18].__vftable )
  {
    v15 = 78;
    v8 = (Scaleform::Render::Text::DocView *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeText *, int, int *, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               272,
                                               &v15,
                                               a2);
    if ( v8 )
    {
      Scaleform::Render::Text::DocView::DocView(v8, fntMgr, log, a6);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    v11 = (Scaleform::RefCountVImpl *)WritableData[18].__vftable;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    WritableData[18].__vftable = v10;
    v12 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::Text::TextFormat::TextFormat(&defaultTextFmt, v12);
    Scaleform::Render::Text::TextFormat::InitByDefaultValues(&defaultTextFmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
      (Scaleform::Render::Text::StyledText *)WritableData[18].CopyTo,
      &defaultTextFmt);
    defaultParagraphFmt.RefCount = 1;
    memset(&defaultParagraphFmt.pTabStops, 0, 16);
    Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(&defaultParagraphFmt);
    Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
      (Scaleform::Render::Text::StyledText *)WritableData[18].CopyTo,
      &defaultParagraphFmt);
    v13 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                                + 20)
                    + 144);
    if ( v13 )
      *(_BYTE *)(v13 + 261) &= ~0x40u;
    v14 = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
    LOBYTE(v14[19].__vftable) |= 1u;
    if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
      Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&defaultParagraphFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
  }
}


void __thiscall Scaleform::Render::TreeText::Init(Scaleform::Render::TreeText *this, Scaleform::GFx::Resource *docView)
{
  Scaleform::RefCountVImpl **v2; // esi

  v2 = (Scaleform::RefCountVImpl **)&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u)[18];
  if ( docView )
    Scaleform::RefCountImpl::AddRef(docView);
  if ( *v2 )
    Scaleform::RefCountImpl::Release(*v2);
  *v2 = (Scaleform::RefCountVImpl *)docView;
}
