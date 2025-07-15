void __thiscall Scaleform::Render::ContextImpl::EntryPage::RemoveEntriesFromList(
        Scaleform::Render::ContextImpl::EntryPage *this,
        Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *plist)
{
  $A6339410173C75E57E963979A37E1205 *v2; // eax
  int v3; // ecx
  Scaleform::Render::ContextImpl::Entry *pNext; // edx
  Scaleform::Render::ContextImpl::Entry *v5; // esi

  v2 = &this->Entries[1].4;
  v3 = 29;
  do
  {
    *($A6339410173C75E57E963979A37E1205 *)(v2[-8].RefCount + 4) = v2[-7];
    v2[-7].pNext->pPrev = v2[-8].pNext;
    *($A6339410173C75E57E963979A37E1205 *)(v2[-1].RefCount + 4) = ($A6339410173C75E57E963979A37E1205)v2->pNext;
    v2->pNext->pPrev = v2[-1].pNext;
    *($A6339410173C75E57E963979A37E1205 *)(v2[6].RefCount + 4) = v2[7];
    v2[7].pNext->pPrev = v2[6].pNext;
    *($A6339410173C75E57E963979A37E1205 *)(v2[13].RefCount + 4) = v2[14];
    v2[14].pNext->pPrev = v2[13].pNext;
    *($A6339410173C75E57E963979A37E1205 *)(v2[20].RefCount + 4) = v2[21];
    pNext = v2[21].pNext;
    v5 = v2[20].pNext;
    v2 += 35;
    --v3;
    pNext->pPrev = v5;
  }
  while ( v3 );
}
