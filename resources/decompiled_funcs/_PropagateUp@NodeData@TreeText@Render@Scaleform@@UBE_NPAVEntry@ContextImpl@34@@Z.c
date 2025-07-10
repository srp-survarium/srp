bool __thiscall Scaleform::Render::TreeText::NodeData::PropagateUp(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::Text::DocView *pObject; // ecx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // edi
  Scaleform::Render::TextLayout *v5; // eax
  int v6; // eax
  int v7; // ebx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::Render::TextLayout *v9; // eax
  __int16 v10; // ax
  float *v11; // eax
  float y1; // [esp+129Ch] [ebp-64Ch] BYREF
  float y2; // [esp+12A0h] [ebp-648h]
  float x2; // [esp+12A4h] [ebp-644h]
  Scaleform::Render::Rect<float> r; // [esp+12A8h] [ebp-640h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+12B8h] [ebp-630h] BYREF
  Scaleform::Render::TextLayout::Builder builder; // [esp+12C8h] [ebp-620h] BYREF

  r.x1 = 0.0;
  r.y1 = 0.0;
  pObject = this->pDocView.pObject;
  r.x2 = 0.0;
  r.y2 = 0.0;
  pr.x1 = 0.0;
  pr.y1 = 0.0;
  pr.x2 = 0.0;
  pr.y2 = 0.0;
  if ( pObject )
  {
    if ( (pObject->RTFlags & 3) != 0 )
      Scaleform::Render::Text::DocView::Format(pObject);
    if ( (this->TextFlags & 1) != 0 )
    {
      Scaleform::Render::TextLayout::Builder::Builder(&builder, Scaleform::Memory::pGlobalHeap);
      Scaleform::Render::Text::DocView::CreateVisibleTextLayout(this->pDocView.pObject, &builder);
      WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 0x400u);
      LODWORD(y1) = 78;
      v5 = (Scaleform::Render::TextLayout *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              144,
                                              &y1);
      if ( v5 )
      {
        Scaleform::Render::TextLayout::TextLayout(v5, &builder);
        v7 = v6;
      }
      else
      {
        v7 = 0;
      }
      v8 = *(Scaleform::RefCountVImpl **)&WritableData[18].Type;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      *(_DWORD *)&WritableData[18].Type = v7;
      LOBYTE(WritableData[19].__vftable) &= ~1u;
      Scaleform::Render::TextLayout::Builder::~Builder(&builder);
    }
  }
  v9 = this->pLayout.pObject;
  if ( v9 )
  {
    y1 = v9->Bounds.y1;
    x2 = v9->Bounds.x2;
    y2 = v9->Bounds.y2;
    r.x1 = v9->Bounds.x1;
    r.y1 = y1;
    r.x2 = x2;
    r.y2 = y2;
    Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(this, &r, 0);
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &r);
    else
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(
        (Scaleform::Render::Matrix2x4<float> *)&this->M34,
        &pr,
        (__m128 *)&r);
  }
  if ( this->AproxLocalBounds.x1 == r.x1
    && this->AproxLocalBounds.x2 == r.x2
    && this->AproxLocalBounds.y1 == r.y1
    && this->AproxLocalBounds.y2 == r.y2
    && pr.x1 == r.x1
    && pr.x2 == r.x2
    && pr.y1 == r.y1
    && pr.y2 == r.y2 )
  {
    LOBYTE(v10) = 0;
  }
  else
  {
    v11 = (float *)Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 8u);
    y2 = r.y1;
    x2 = r.x2;
    y1 = r.y2;
    v11[28] = r.x1;
    v11[29] = y2;
    v11[30] = x2;
    v11[31] = y1;
    y2 = pr.y1;
    x2 = pr.x2;
    y1 = pr.y2;
    v11[32] = pr.x1;
    v11[33] = y2;
    v11[34] = x2;
    v11[35] = y1;
    return this->Flags & 1;
  }
  return v10;
}
