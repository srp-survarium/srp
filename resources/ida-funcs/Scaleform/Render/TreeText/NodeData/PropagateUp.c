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
  float y1; // [esp+Ch] [ebp-64Ch] BYREF
  float y2; // [esp+10h] [ebp-648h]
  float x2; // [esp+14h] [ebp-644h]
  Scaleform::Render::Rect<float> bounds; // [esp+18h] [ebp-640h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+28h] [ebp-630h] BYREF
  Scaleform::Render::TextLayout::Builder bld; // [esp+38h] [ebp-620h] BYREF

  bounds.x1 = 0.0;
  bounds.y1 = 0.0;
  pObject = this->pDocView.pObject;
  bounds.x2 = 0.0;
  bounds.y2 = 0.0;
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
      Scaleform::Render::TextLayout::Builder::Builder(&bld, Scaleform::Memory::pGlobalHeap);
      Scaleform::Render::Text::DocView::CreateVisibleTextLayout(this->pDocView.pObject, &bld);
      WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 0x400u);
      LODWORD(y1) = 78;
      v5 = (Scaleform::Render::TextLayout *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              144,
                                              &y1);
      if ( v5 )
      {
        Scaleform::Render::TextLayout::TextLayout(v5, &bld);
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
      Scaleform::Render::TextLayout::Builder::~Builder(&bld);
    }
  }
  v9 = this->pLayout.pObject;
  if ( v9 )
  {
    y1 = v9->Bounds.y1;
    x2 = v9->Bounds.x2;
    y2 = v9->Bounds.y2;
    bounds.x1 = v9->Bounds.x1;
    bounds.y1 = y1;
    bounds.x2 = x2;
    bounds.y2 = y2;
    Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(this, &bounds, 0);
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &bounds);
    else
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(
        (Scaleform::Render::Matrix2x4<float> *)&this->M34,
        (__m128 *)&pr,
        (__m128 *)&bounds);
  }
  if ( this->AproxLocalBounds.x1 == bounds.x1
    && this->AproxLocalBounds.x2 == bounds.x2
    && this->AproxLocalBounds.y1 == bounds.y1
    && this->AproxLocalBounds.y2 == bounds.y2
    && pr.x1 == bounds.x1
    && pr.x2 == bounds.x2
    && pr.y1 == bounds.y1
    && pr.y2 == bounds.y2 )
  {
    LOBYTE(v10) = 0;
  }
  else
  {
    v11 = (float *)Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 8u);
    y2 = bounds.y1;
    x2 = bounds.x2;
    y1 = bounds.y2;
    v11[28] = bounds.x1;
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
