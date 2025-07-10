void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::willTrigger(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        bool *result,
        const Scaleform::GFx::ASString *type)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v5; // esi
  int v6; // eax
  unsigned int *v7; // eax
  int *v8; // eax
  int v9; // eax
  bool v10; // al
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v11; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // esi
  int v13; // eax
  unsigned int *v14; // eax
  int *v15; // eax
  int v16; // eax
  bool v17; // al
  Scaleform::GFx::AS3::Traits *v18; // eax
  int v19; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v20; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v21; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v22; // esi
  int v23; // eax
  unsigned int *v24; // eax
  int *v25; // eax
  int v26; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v27; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v28; // esi
  int v29; // eax
  unsigned int *v30; // eax
  int *v31; // eax
  int v32; // eax
  bool v33; // al
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> captureArray; // [esp+10h] [ebp-90h] BYREF

  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v10 = 0;
  if ( pObject )
  {
    v5.pTable = pObject->pTable;
    if ( pObject->pTable )
    {
      v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             pObject,
             type,
             type->pNode->HashFlags & v5.pTable->SizeMask);
      if ( v6 >= 0 )
      {
        v7 = &v5.pTable[1].SizeMask + 3 * v6;
        if ( v7 )
        {
          v8 = (int *)(v7 + 1);
          if ( v8 )
          {
            v9 = *v8;
            if ( v9 )
            {
              if ( *(_DWORD *)(v9 + 4) )
                v10 = 1;
            }
          }
        }
      }
    }
  }
  *result = v10;
  if ( !v10 )
  {
    v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
    v17 = 0;
    if ( v11 )
    {
      pTable = v11[1].pTable;
      if ( pTable )
      {
        v13 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v11 + 1,
                type,
                type->pNode->HashFlags & pTable->SizeMask);
        if ( v13 >= 0 )
        {
          v14 = &pTable[1].SizeMask + 3 * v13;
          if ( v14 )
          {
            v15 = (int *)(v14 + 1);
            if ( v15 )
            {
              v16 = *v15;
              if ( v16 )
              {
                if ( *(_DWORD *)(v16 + 4) )
                  v17 = 1;
              }
            }
          }
        }
      }
    }
    *result = v17;
    if ( !v17 )
    {
      v18 = this->pTraits.pObject;
      if ( (unsigned int)(v18->TraitsType - 17) <= 0xC && (v18->Flags & 0x20) == 0 )
      {
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(
          &captureArray,
          v18->pVM->MHeap);
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(
          this,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC,
          &captureArray);
        v19 = 0;
        if ( captureArray.Size )
        {
          while ( 1 )
          {
            v20 = captureArray.Data[v19].pObject;
            v21 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v20->pImpl.pObject;
            if ( v21 )
            {
              v22.pTable = v21->pTable;
              if ( v21->pTable )
              {
                v23 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                        v21,
                        type,
                        type->pNode->HashFlags & v22.pTable->SizeMask);
                if ( v23 >= 0 )
                {
                  v24 = &v22.pTable[1].SizeMask + 3 * v23;
                  if ( v24 )
                  {
                    v25 = (int *)(v24 + 1);
                    if ( v25 )
                    {
                      v26 = *v25;
                      if ( v26 )
                      {
                        if ( *(_DWORD *)(v26 + 4) )
                          break;
                      }
                    }
                  }
                }
              }
            }
            v27 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v20->pImpl.pObject;
            v33 = 0;
            if ( v27 )
            {
              v28 = v27[1].pTable;
              if ( v28 )
              {
                v29 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                        v27 + 1,
                        type,
                        type->pNode->HashFlags & v28->SizeMask);
                if ( v29 >= 0 )
                {
                  v30 = &v28[1].SizeMask + 3 * v29;
                  if ( v30 )
                  {
                    v31 = (int *)(v30 + 1);
                    if ( v31 )
                    {
                      v32 = *v31;
                      if ( v32 )
                      {
                        if ( *(_DWORD *)(v32 + 4) )
                          v33 = 1;
                      }
                    }
                  }
                }
              }
            }
            *result = v33;
            if ( !v33 && ++v19 < captureArray.Size )
              continue;
            goto LABEL_44;
          }
          *result = 1;
        }
LABEL_44:
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::~ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(&captureArray);
      }
    }
  }
}
