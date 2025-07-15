void __thiscall Scaleform::Render::TreeNode::SetMatrix3D(Scaleform::Render::TreeNode *this, const __m128i *m)
{
  unsigned int v3; // ebx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // esi

  v3 = 1;
  if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x200) == 0 )
    v3 = 8193;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, v3);
  memcpy((int)&WritableData[2], m, 0x30u);
  WritableData->Flags |= 0x200u;
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
