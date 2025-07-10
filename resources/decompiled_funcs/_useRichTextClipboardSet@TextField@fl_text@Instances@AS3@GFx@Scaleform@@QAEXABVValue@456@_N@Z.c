void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::useRichTextClipboardSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pNext; // ecx

  pObject = this->pDispObj.pObject;
  if ( value )
    *(_DWORD *)&pObject[1].ClipDepth |= 0x100u;
  else
    *(_DWORD *)&pObject[1].ClipDepth &= ~0x100u;
  pNext = pObject[1].pRenNode.pObject[5].PNode.pNext;
  if ( pNext )
  {
    if ( (*(_DWORD *)&pObject[1].ClipDepth & 0x100) != 0 )
      LOWORD(pNext[16].pPrev) |= 4u;
    else
      LOWORD(pNext[16].pPrev) &= ~4u;
  }
}
