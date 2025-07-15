void __thiscall Scaleform::StatsUpdate::MemReport(
        Scaleform::StatsUpdate *this,
        Scaleform::MemItem *rootItem,
        Scaleform::MemoryHeap::MemReportType reportType)
{
  unsigned int v4; // eax
  Scaleform::StringLH *v5; // eax
  Scaleform::MemItem *v6; // edi
  unsigned int NextHandle; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  Scaleform::MemItem *v17; // edi
  const Scaleform::StatDesc *Desc; // eax
  unsigned int StatIdMemory; // eax
  unsigned int v20; // ecx
  const Scaleform::StatDesc *v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // [esp-Ch] [ebp-290h]
  unsigned int v28; // [esp-4h] [ebp-288h]
  unsigned int v29; // [esp-4h] [ebp-288h]
  unsigned int v30; // [esp-4h] [ebp-288h]
  unsigned int v31; // [esp-4h] [ebp-288h]
  unsigned int v32; // [esp-4h] [ebp-288h]
  unsigned int v33; // [esp-4h] [ebp-288h]
  unsigned int v34; // [esp-4h] [ebp-288h]
  unsigned int v35; // [esp-4h] [ebp-288h]
  unsigned int v36; // [esp-4h] [ebp-288h]
  unsigned int v37; // [esp-4h] [ebp-288h]
  unsigned int VideoMemory; // [esp-4h] [ebp-288h]
  unsigned int MovieViewMemory; // [esp-4h] [ebp-288h]
  unsigned int MovieDataMemory; // [esp-4h] [ebp-288h]
  unsigned int v41; // [esp+10h] [ebp-274h] BYREF
  unsigned int v42; // [esp+14h] [ebp-270h] BYREF
  Scaleform::StatsUpdate::SummaryMemoryVisitor v43; // [esp+18h] [ebp-26Ch] BYREF
  unsigned int v44; // [esp+30h] [ebp-254h] BYREF
  unsigned int v45; // [esp+34h] [ebp-250h]
  unsigned int v46; // [esp+38h] [ebp-24Ch]
  unsigned int v47; // [esp+3Ch] [ebp-248h]
  unsigned int v48; // [esp+40h] [ebp-244h]
  unsigned int v49; // [esp+44h] [ebp-240h]
  unsigned int v50; // [esp+48h] [ebp-23Ch]
  unsigned int v51; // [esp+4Ch] [ebp-238h]
  unsigned int v52; // [esp+50h] [ebp-234h]
  unsigned int v53; // [esp+54h] [ebp-230h]
  Scaleform::MsgFormat::Sink v54; // [esp+58h] [ebp-22Ch] BYREF
  Scaleform::StatsUpdate::SummaryStatIdVisitor v55; // [esp+64h] [ebp-220h] BYREF

  rootItem->ID = this->NextHandle++;
  rootItem->StartExpanded = 1;
  if ( reportType == MemReportFileSummary )
  {
    Scaleform::StatsUpdate::MemReportFile(this, rootItem, MemReportFileSummary);
  }
  else if ( reportType == MemReportHeapDetailed )
  {
    Scaleform::StatsUpdate::MemReportHeapsDetailed(this, rootItem, Scaleform::Memory::pGlobalHeap);
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->GetRootStats(
      Scaleform::Memory::pGlobalHeap,
      (Scaleform::MemoryHeap::RootStats *)&v44);
    v42 = (v44 - v50 - v52 + 512) >> 10;
    v41 = (v45 - v50 - v52 + 512) >> 10;
    v54.SinkData.pStr = &rootItem->Name;
    v54.Type = tStr;
    Scaleform::Format<unsigned long,unsigned long>(&v54, "Memory {0:sep:,}K / {1:sep:,}K", &v41, &v42);
    if ( reportType )
    {
      v4 = this->NextHandle++;
      v5 = Scaleform::MemItem::AddChild(rootItem, v4, (const __m128i *)"System Summary");
      v28 = v44;
      v6 = (Scaleform::MemItem *)v5;
      v27 = this->NextHandle++;
      Scaleform::MemItem::AddChild((Scaleform::MemItem *)v5, v27, (const __m128i *)"System Memory FootPrint", v28);
      NextHandle = this->NextHandle;
      v29 = v45;
      ++this->NextHandle;
      Scaleform::MemItem::AddChild(v6, NextHandle, (const __m128i *)"System Memory Used Space", v29);
      if ( v46 )
      {
        v8 = this->NextHandle;
        v30 = v46;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v8, (const __m128i *)"Page Mapping Footprint", v30);
      }
      if ( v47 )
      {
        v9 = this->NextHandle;
        v31 = v47;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v9, (const __m128i *)"Page Mapping UsedSpace", v31);
      }
      if ( v48 )
      {
        v10 = this->NextHandle;
        v32 = v48;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v10, (const __m128i *)"Bookkeeping Footprint", v32);
      }
      if ( v49 )
      {
        v11 = this->NextHandle;
        v33 = v49;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v11, (const __m128i *)"Bookkeeping Used Space", v33);
      }
      if ( v50 )
      {
        v12 = this->NextHandle;
        v34 = v50;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v12, (const __m128i *)"Debug Info Footprint", v34);
      }
      if ( v51 )
      {
        v13 = this->NextHandle;
        v35 = v51;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v13, (const __m128i *)"Debug Info Used Space", v35);
      }
      if ( v52 )
      {
        v14 = this->NextHandle;
        v36 = v52;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v14, (const __m128i *)"Debug Heaps Footprint", v36);
      }
      if ( v53 )
      {
        v15 = this->NextHandle;
        v37 = v53;
        ++this->NextHandle;
        Scaleform::MemItem::AddChild(v6, v15, (const __m128i *)"Debug Heaps Used Space", v37);
      }
      v16 = this->NextHandle++;
      v17 = (Scaleform::MemItem *)Scaleform::MemItem::AddChild(rootItem, v16, (const __m128i *)"Summary");
    }
    else
    {
      v17 = rootItem;
    }
    v17->StartExpanded = 1;
    Scaleform::StatsUpdate::SummaryStatIdVisitor::SummaryStatIdVisitor(&v55, 0);
    Scaleform::StatsUpdate::SummaryStatIdVisitor::Visit(&v55, 0, Scaleform::Memory::pGlobalHeap);
    Scaleform::StatBag::UpdateGroups(&v55.StatIdBag);
    v43.__vftable = (Scaleform::StatsUpdate::SummaryMemoryVisitor_vtbl *)&Scaleform::StatsUpdate::SummaryMemoryVisitor::`vftable';
    v43.Debug = 0;
    memset(&v43.MovieViewMemory, 0, 16);
    Scaleform::StatsUpdate::SummaryMemoryVisitor::Visit(&v43, 0, Scaleform::Memory::pGlobalHeap);
    Desc = Scaleform::StatDesc::GetDesc(3u);
    StatIdMemory = Scaleform::StatsUpdate::SummaryStatIdVisitor::GetStatIdMemory(
                     &v55,
                     (Scaleform::StatDesc::Iterator)Desc);
    if ( StatIdMemory )
    {
      v20 = this->NextHandle++;
      Scaleform::MemItem::AddChild(v17, v20, (const __m128i *)"Image", StatIdMemory);
    }
    v21 = Scaleform::StatDesc::GetDesc(4u);
    v22 = Scaleform::StatsUpdate::SummaryStatIdVisitor::GetStatIdMemory(&v55, (Scaleform::StatDesc::Iterator)v21);
    if ( v22 )
    {
      v23 = this->NextHandle++;
      Scaleform::MemItem::AddChild(v17, v23, (const __m128i *)"Sound", v22);
    }
    if ( v43.VideoMemory )
    {
      v24 = this->NextHandle;
      VideoMemory = v43.VideoMemory;
      ++this->NextHandle;
      Scaleform::MemItem::AddChild(v17, v24, (const __m128i *)"Video", VideoMemory);
    }
    v25 = this->NextHandle;
    MovieViewMemory = v43.MovieViewMemory;
    ++this->NextHandle;
    Scaleform::MemItem::AddChild(v17, v25, (const __m128i *)"Movie View", MovieViewMemory);
    v26 = this->NextHandle;
    MovieDataMemory = v43.MovieDataMemory;
    ++this->NextHandle;
    Scaleform::MemItem::AddChild(v17, v26, (const __m128i *)"Movie Data", MovieDataMemory);
    if ( reportType )
      Scaleform::StatsUpdate::MemReportHeaps(this, Scaleform::Memory::pGlobalHeap, rootItem, reportType);
    v43.__vftable = (Scaleform::StatsUpdate::SummaryMemoryVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    if ( v55.ExcludedHeaps.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v55.ExcludedHeaps.Data.Data);
    Scaleform::StatBag::~StatBag(&v55.StatIdBag);
  }
}
