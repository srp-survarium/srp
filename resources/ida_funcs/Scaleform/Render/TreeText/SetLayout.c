void __thiscall Scaleform::Render::TreeText::SetLayout(
        Scaleform::Render::TreeText *this,
        const Scaleform::Render::TextLayout::Builder *b)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // edi
  Scaleform::Render::TextLayout *v4; // eax
  int v5; // eax
  int v6; // ebx
  Scaleform::RefCountVImpl *v7; // ecx
  int v8; // [esp+Ch] [ebp-4h] BYREF

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  v8 = 78;
  v4 = (Scaleform::Render::TextLayout *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          this,
                                          144,
                                          &v8);
  if ( v4 )
  {
    Scaleform::Render::TextLayout::TextLayout(v4, b);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = *(Scaleform::RefCountVImpl **)&WritableData[18].Type;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  *(_DWORD *)&WritableData[18].Type = v6;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
