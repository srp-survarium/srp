void __thiscall Scaleform::Render::TreeText::SetVAlignment(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::VAlignment a)
{
  int v3; // eax
  char v4; // cl
  Scaleform::Render::ContextImpl::EntryData *WritableData; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144);
  if ( v3 )
  {
    if ( a == VAlign_Center )
    {
      v4 = 3;
    }
    else if ( a == VAlign_Bottom )
    {
      v4 = 2;
    }
    else
    {
      v4 = 1;
    }
    *(_BYTE *)(v3 + 260) ^= (*(_BYTE *)(v3 + 260) ^ (4 * v4)) & 0xC;
    *(_BYTE *)(v3 + 263) |= 1u;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[19].__vftable) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
