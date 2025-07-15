void __thiscall Scaleform::GFx::AS3::EventChains::QueueEvents(
        Scaleform::GFx::AS3::EventChains *this,
        Scaleform::GFx::EventId::IdCode evtId)
{
  Scaleform::GFx::EventId::IdCode v2; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // esi
  signed int Index; // eax
  int p_SizeMask; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **v6; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v7; // esi
  unsigned int v8; // edi
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *v9; // eax
  Scaleform::RefCountNTSImpl *v10; // eax
  Scaleform::RefCountNTSImpl *pObject; // eax
  Scaleform::RefCountNTSImpl_vtbl **v12; // ecx
  Scaleform::GFx::EventId evt; // [esp+Ch] [ebp-14h] BYREF

  v2 = evtId;
  pTable = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::findIndexCore<int>(
              (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)this,
              (Scaleform::GFx::MovieDefImpl *const *)&evtId,
              evtId & pTable->SizeMask);
    if ( Index >= 0 )
    {
      p_SizeMask = (int)&pTable[2 * Index + 1].SizeMask;
      if ( p_SizeMask )
      {
        v6 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **)(p_SizeMask + 4);
        if ( v6 )
        {
          v7 = *v6;
          v8 = 0;
          while ( v8 < v7->Size )
          {
            v9 = &v7->Data[v8];
            if ( v9->pObject )
            {
              evt.Id = v2;
              memset(&evt.WcharCode, 0, 9);
              evt.RollOverCnt = 0;
              evt.KeysState.States = 0;
              evt.MouseWheelDelta = 0;
              evt.ControllerIndex = -1;
              pObject = v9->pObject;
              if ( pObject )
                v12 = &(&pObject->__vftable)[BYTE1(pObject[8].__vftable)];
              else
                v12 = 0;
              ((void (__thiscall *)(Scaleform::RefCountNTSImpl_vtbl **, Scaleform::GFx::EventId *))(*v12)[8].~Scaleform::RefCountNTSImpl)(
                v12,
                &evt);
              ++v8;
            }
            else if ( v7->Size == 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                v7,
                v7,
                0);
            }
            else
            {
              v10 = v9->pObject;
              if ( v10 )
                Scaleform::RefCountNTSImpl::Release(v10);
              memmove((int)&v7->Data[v8], (const __m128i *)&v7->Data[v8 + 1], 4 * (v7->Size - v8) - 4);
              --v7->Size;
            }
          }
        }
      }
    }
  }
}
