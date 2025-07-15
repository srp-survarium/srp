BOOL __thiscall Scaleform::Render::ContextImpl::Context::HasChanges(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // edx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pPages; // eax

  v1 = this->pSnapshots[0];
  pPages = v1->Changes.pPages;
  return pPages && pPages->Count
      || (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v1->DestroyedNodes.Root.pNext != &v1->DestroyedNodes
      || this->DIChangesRequired;
}
