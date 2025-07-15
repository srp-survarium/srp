void __thiscall Scaleform::GFx::DisplayObjectBase::SetAlpha(Scaleform::GFx::DisplayObjectBase *this, long double alpha)
{
  Scaleform::Render::TreeNode *pObject; // eax
  Scaleform::Render::Cxform *v4; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax
  float v8[8]; // [esp+34h] [ebp-20h] BYREF

  if ( (HIDWORD(alpha) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(alpha) | LODWORD(alpha)) )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
      v4 = (Scaleform::Render::Cxform *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                                                   + 4
                                                   * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000))
                                                    / 28)
                                                   + 20)
                                       + 80);
    else
      v4 = &Scaleform::Render::Cxform::Identity;
    qmemcpy(v8, v4, sizeof(v8));
    v8[3] = alpha / 100.0;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
    qmemcpy(&WritableData[10], v8, 0x20u);
    this->SetAcceptAnimMoves(this, 0);
  }
}
