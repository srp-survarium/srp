void __thiscall Scaleform::Render::TreeNode::Clear3D(Scaleform::Render::TreeNode *this)
{
  unsigned int v1; // ebx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // esi

  v1 = 1;
  if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x200) != 0 )
    v1 = 8193;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, v1);
  memcpy((unsigned __int8 *)&WritableData[2], (unsigned __int8 *)&Scaleform::Render::Matrix3x4<float>::Identity, 0x30u);
  WritableData->Flags &= ~0x200u;
}
