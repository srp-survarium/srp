void __thiscall Scaleform::Render::ContextImpl::EntryPage::AddEntriesToList(
        Scaleform::Render::ContextImpl::EntryPage *this,
        Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *plist)
{
  $A6339410173C75E57E963979A37E1205 *v2; // ecx
  int v3; // edi
  Scaleform::Render::ContextImpl::Entry *v4; // edx

  v2 = &this->Entries[1].4;
  v3 = 29;
  do
  {
    v2[-8].pNext = plist->Root.pPrev;
    v2[-7].RefCount = (unsigned int)plist;
    plist->Root.pPrev->RefCount = (unsigned int)&v2[-8];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[-8];
    v2[-1].RefCount = (unsigned int)&v2[-8];
    v2->RefCount = (unsigned int)plist;
    plist->Root.pPrev->RefCount = (unsigned int)&v2[-1];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[-1];
    v2[6].RefCount = (unsigned int)&v2[-1];
    v2[7].RefCount = (unsigned int)plist;
    plist->Root.pPrev->RefCount = (unsigned int)&v2[6];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[6];
    v2[13].RefCount = (unsigned int)&v2[6];
    v2[14].RefCount = (unsigned int)plist;
    plist->Root.pPrev->RefCount = (unsigned int)&v2[13];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[13];
    v4 = (Scaleform::Render::ContextImpl::Entry *)&v2[20];
    v2[20].RefCount = (unsigned int)&v2[13];
    v2[21].RefCount = (unsigned int)plist;
    v2 += 35;
    --v3;
    plist->Root.pPrev->RefCount = (unsigned int)v4;
    plist->Root.pPrev = v4;
  }
  while ( v3 );
}
