void __thiscall Scaleform::GFx::MovieImpl::SetPause(Scaleform::GFx::MovieImpl *this, int pause)
{
  Scaleform::GFx::InteractiveObject *pPlayListHead; // ecx
  Scaleform::GFx::InteractiveObject *pPlayNext; // edi
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *pTable; // eax
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *p_VideoProviders; // edx
  unsigned int SizeMask; // ecx
  unsigned int v8; // esi
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v9; // eax
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *v10; // ebp
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v11; // eax
  Scaleform::RefCountNTSImpl **v12; // eax
  Scaleform::RefCountNTSImpl *v13; // edi
  unsigned int v14; // eax
  unsigned int *v15; // ecx

  if ( ((this->Flags & 0x100000) == 0 || !(_BYTE)pause) && ((this->Flags & 0x100000) != 0 || (_BYTE)pause) )
  {
    if ( (_BYTE)pause )
    {
      this->Flags |= (unsigned int)&loc_100000;
      this->PauseTickMs = Scaleform::Timer::GetTicks() / 0x3E8;
    }
    else
    {
      this->Flags &= ~0x100000u;
      this->StartTickMs += Scaleform::Timer::GetTicks() / 0x3E8 - this->PauseTickMs;
    }
    pPlayListHead = this->pPlayListHead;
    if ( pPlayListHead )
    {
      do
      {
        pPlayNext = pPlayListHead->pPlayNext;
        ((void (__stdcall *)(int))pPlayListHead->SetPause)(pause);
        pPlayListHead = pPlayNext;
      }
      while ( pPlayNext );
    }
    pTable = this->VideoProviders.pTable;
    p_VideoProviders = &this->VideoProviders;
    if ( pTable && pTable->EntryCount )
    {
      SizeMask = pTable->SizeMask;
      v8 = 0;
      v9 = pTable + 1;
      do
      {
        if ( v9->EntryCount != -2 )
          break;
        ++v8;
        v9 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *)((char *)v9 + 12);
      }
      while ( v8 <= SizeMask );
      v10 = p_VideoProviders;
      while ( v10 )
      {
        v11 = v10->pTable;
        if ( !v10->pTable || (signed int)v8 > (signed int)v11->SizeMask )
          break;
        v12 = (Scaleform::RefCountNTSImpl **)&v11[2] + 3 * v8;
        if ( *v12 )
          ++(*v12)->RefCount;
        v13 = *v12;
        ((void (__thiscall *)(Scaleform::RefCountNTSImpl *, int))(*v12)->__vftable[3].~Scaleform::RefCountNTSImpl)(
          *v12,
          pause);
        Scaleform::RefCountNTSImpl::Release(v13);
        v14 = v10->pTable->SizeMask;
        if ( (int)v8 <= (int)v14 && ++v8 <= v14 )
        {
          v15 = &v10->pTable[1].EntryCount + 3 * v8;
          do
          {
            if ( *v15 != -2 )
              break;
            ++v8;
            v15 += 3;
          }
          while ( v8 <= v14 );
        }
      }
    }
  }
}
