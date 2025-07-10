char __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildren(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch1,
        Scaleform::GFx::DisplayObjectBase *ch2)
{
  Scaleform::GFx::DisplayList *p_LastHitTestY; // esi
  unsigned int DisplayIndex; // ebx
  unsigned int v6; // eax

  p_LastHitTestY = (Scaleform::GFx::DisplayList *)&this->pDispObj[1].LastHitTestY;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(p_LastHitTestY, ch1);
  v6 = Scaleform::GFx::DisplayList::FindDisplayIndex(p_LastHitTestY, ch2);
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(this, DisplayIndex, v6);
}
