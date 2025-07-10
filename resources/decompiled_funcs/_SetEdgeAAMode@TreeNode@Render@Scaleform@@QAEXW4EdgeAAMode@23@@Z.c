void __thiscall Scaleform::Render::TreeNode::SetEdgeAAMode(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::EdgeAAMode edgeAA)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0xC) != edgeAA )
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x20u);
    WritableData->Flags = edgeAA | WritableData->Flags & 0xFFF3;
  }
}
