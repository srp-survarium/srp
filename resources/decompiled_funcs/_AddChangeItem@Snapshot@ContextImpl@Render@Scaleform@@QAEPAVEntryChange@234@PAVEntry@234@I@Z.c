Scaleform::Render::ContextImpl::EntryChange *__thiscall Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(
        Scaleform::Render::ContextImpl::Snapshot *this,
        Scaleform::Render::ContextImpl::Entry *pentry,
        unsigned int changeBits)
{
  Scaleform::Render::ContextImpl::EntryChange *result; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126> *p_Changes; // esi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pLast; // eax
  unsigned int Count; // ecx

  result = this->pFreeChangeNodes;
  if ( result )
  {
    this->pFreeChangeNodes = result->pNextFreeNode;
  }
  else
  {
    p_Changes = &this->Changes;
    Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::ensureCountAvailable(
      &this->Changes,
      1u);
    pLast = p_Changes->pLast;
    Count = pLast->Count;
    pLast->Count = Count + 1;
    result = &pLast->Items[Count];
  }
  result->pNode = pentry;
  result->ChangeBits = changeBits;
  return result;
}
