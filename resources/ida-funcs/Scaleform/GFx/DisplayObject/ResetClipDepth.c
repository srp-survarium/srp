void __thiscall Scaleform::GFx::DisplayObject::ResetClipDepth(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::InteractiveObject *v3; // esi
  Scaleform::GFx::DisplayObjectBase *DisplayIndex; // ebp

  if ( this->ClipDepth )
  {
    pParent = this->pParent;
    if ( pParent
      && (v3 = (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0
             ? pParent
             : 0) != 0 )
    {
      DisplayIndex = (Scaleform::GFx::DisplayObjectBase *)Scaleform::GFx::DisplayList::FindDisplayIndex(
                                                            (Scaleform::GFx::DisplayList *)&v3[1],
                                                            this);
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(
        (Scaleform::GFx::DisplayList *)&v3[1],
        v3,
        (unsigned int)DisplayIndex);
      this->ClipDepth = 0;
      Scaleform::GFx::DisplayList::InsertIntoRenderTree((Scaleform::GFx::DisplayList *)&v3[1], v3, DisplayIndex);
    }
    else
    {
      this->ClipDepth = 0;
    }
  }
}
