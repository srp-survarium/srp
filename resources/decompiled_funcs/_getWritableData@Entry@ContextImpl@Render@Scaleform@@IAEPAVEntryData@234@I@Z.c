Scaleform::Render::ContextImpl::EntryData *__thiscall Scaleform::Render::ContextImpl::Entry::getWritableData(
        Scaleform::Render::ContextImpl::Entry *this,
        unsigned int changeBits)
{
  _DWORD *v3; // ebx
  Scaleform::Render::ContextImpl::Snapshot *v4; // esi

  v3 = (_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                + 20);
  if ( this->pPrev )
  {
    this->pPrev->RefCount |= changeBits;
  }
  else
  {
    v4 = *(Scaleform::Render::ContextImpl::Snapshot **)(((unsigned int)this & 0xFFFFF000) + 0xC);
    *v3 = (*(int (__thiscall **)(_DWORD, Scaleform::Render::LinearHeap *))(*(_DWORD *)*v3 + 4))(
            *v3,
            &v4->Heaps.Root.pNext->ChangeHeap);
    this->pPrev = (Scaleform::Render::ContextImpl::Entry *)Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(
                                                             v4,
                                                             this,
                                                             changeBits);
  }
  return (Scaleform::Render::ContextImpl::EntryData *)*v3;
}
