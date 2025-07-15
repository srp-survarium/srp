void __thiscall Scaleform::StatsUpdate::GetFileMemory(
        Scaleform::StatsUpdate *this,
        Scaleform::StatDesc::Iterator it,
        int fileStats,
        int rootItem,
        Scaleform::MemoryHeap::MemReportType reportType)
{
  int v5; // ebx
  unsigned int v7; // eax
  Scaleform::MemItem *v8; // esi
  Scaleform::StatDesc *i; // edi
  unsigned int v10; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v11; // ebp
  unsigned int v12; // edi
  Scaleform::RefCountVImpl **v13; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // edx
  Scaleform::MemItem **v15; // edi
  unsigned int memValue; // [esp+18h] [ebp-24h]
  Scaleform::StatDesc::Iterator ita; // [esp+1Ch] [ebp-20h]
  Scaleform::StatInfo v18; // [esp+20h] [ebp-1Ch] BYREF
  _DWORD v19[2]; // [esp+2Ch] [ebp-10h] BYREF
  unsigned int v20; // [esp+34h] [ebp-8h]

  v5 = fileStats;
  memset(&v18, 0, sizeof(v18));
  v19[0] = 0;
  v19[1] = uri;
  v20 = 0;
  memValue = 0;
  if ( Scaleform::StatBag::GetStat((Scaleform::StatBag *)fileStats, &v18, it.pDesc->Id) )
  {
    v18.pInterface->GetStat(v18.pInterface, v18.pData, (Scaleform::Stat::StatValue *)v19, 0);
    v7 = v20;
    *(_DWORD *)(v5 + 524) += v20;
    memValue = v7;
  }
  fileStats = 2;
  v8 = (Scaleform::MemItem *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                               Scaleform::Memory::pGlobalHeap,
                               rootItem,
                               40,
                               &fileStats);
  if ( v8 )
  {
    ita.pDesc = (const Scaleform::StatDesc *)this->NextHandle++;
    v8->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v8->RefCount = 1;
    v8->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v8->Name);
    v8->Value = 0;
    v8->HasValue = 0;
    v8->StartExpanded = 0;
    v8->ID = (unsigned int)ita.pDesc;
    v8->ImageExtraData.pObject = 0;
    v8->Children.Data.Data = 0;
    v8->Children.Data.Size = 0;
    v8->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v8 = 0;
  }
  for ( i = it.pDesc->pChild; i; i = i->pNextSibling )
    Scaleform::StatsUpdate::GetFileMemory(this, (Scaleform::StatDesc::Iterator)i, v5, (int)v8, reportType);
  if ( memValue )
  {
    Scaleform::String::operator=(&v8->Name, (const __m128i *)it.pDesc->pName);
    Scaleform::MemItem::SetValue(v8, memValue);
    v10 = *(_DWORD *)(rootItem + 32);
    v11 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)(rootItem + 28);
    v12 = v10 + 1;
    if ( v10 + 1 >= v10 )
    {
      if ( v12 >= *(_DWORD *)(rootItem + 36) )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          v12 + (v12 >> 2));
    }
    else
    {
      v13 = (Scaleform::RefCountVImpl **)&v11->Data[v10 - 1];
      rootItem = -1;
      do
      {
        if ( *v13 )
          Scaleform::RefCountImpl::Release(*v13);
        --v13;
        --rootItem;
      }
      while ( rootItem );
      if ( v12 < v11->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v11,
          v11,
          v12);
    }
    Data = v11->Data;
    v11->Size = v12;
    v15 = (Scaleform::MemItem **)&Data[v12 - 1];
    if ( v15 )
    {
      if ( v8 )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8);
      *v15 = v8;
    }
  }
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
}
