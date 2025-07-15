void __thiscall Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // eax
  Scaleform::Render::ContextImpl::SnapshotPage *pNext; // ebp
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // ecx
  Scaleform::Render::ContextImpl::EntryPage *pEntryPage; // eax
  Scaleform::Render::TreeCacheNode **p_pRenderer; // esi
  int v7; // edi
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *i; // [esp+4h] [ebp-4h]

  if ( this->pRenderer )
  {
    v2 = this->pSnapshots[2];
    if ( v2 )
    {
      pNext = v2->SnapshotPages.Root.pNext;
      p_SnapshotPages = &v2->SnapshotPages;
      for ( i = &v2->SnapshotPages;
            pNext != (Scaleform::Render::ContextImpl::SnapshotPage *)p_SnapshotPages;
            pNext = pNext->pNext )
      {
        pEntryPage = pNext->pEntryPage;
        if ( pEntryPage )
        {
          p_pRenderer = &pEntryPage->Entries[0].pRenderer;
          v7 = 145;
          do
          {
            if ( *p_pRenderer != (Scaleform::Render::TreeCacheNode *)2989 && *p_pRenderer )
              this->pRenderer->EntryFlush(this->pRenderer, (Scaleform::Render::ContextImpl::Entry *)(p_pRenderer - 3));
            p_pRenderer += 7;
            --v7;
          }
          while ( v7 );
          p_SnapshotPages = i;
        }
      }
      this->pRenderer->ContextReleased(this->pRenderer, this);
      if ( this->pShutdownEvent )
      {
        Scaleform::Event::SetEvent(this->pShutdownEvent);
        this->pShutdownEvent = 0;
      }
    }
  }
}
