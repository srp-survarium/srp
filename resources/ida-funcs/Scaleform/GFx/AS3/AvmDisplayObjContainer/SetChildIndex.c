char __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch,
        Scaleform::GFx::DisplayObjectBase *index)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::DisplayList *p_LastHitTestY; // edi
  signed int DisplayIndex; // eax

  pDispObj = this->pDispObj;
  if ( (Scaleform::Render::TreeNode *)index >= pDispObj[1].pRenNode.pObject )
    return 0;
  p_LastHitTestY = (Scaleform::GFx::DisplayList *)&pDispObj[1].LastHitTestY;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(
                   (Scaleform::GFx::DisplayList *)&pDispObj[1].LastHitTestY,
                   ch);
  if ( DisplayIndex < 0 )
    return 0;
  if ( ch )
    ++ch->RefCount;
  Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_LastHitTestY, this->pDispObj, DisplayIndex);
  Scaleform::GFx::DisplayList::AddEntryAtIndex(p_LastHitTestY, this->pDispObj, index, ch);
  ch->SetAcceptAnimMoves(ch, 0);
  ch->CreateFrame = 0;
  ch->Depth = -1;
  p_LastHitTestY->Flags |= 3u;
  Scaleform::RefCountNTSImpl::Release(ch);
  return 1;
}
