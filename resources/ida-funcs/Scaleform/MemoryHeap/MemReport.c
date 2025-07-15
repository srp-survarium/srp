void __thiscall Scaleform::MemoryHeap::MemReport(
        Scaleform::MemoryHeap *this,
        Scaleform::MemItem *rootItem,
        Scaleform::MemoryHeap::MemReportType reportType)
{
  Scaleform::StatsUpdate v3; // [esp+0h] [ebp-4h] BYREF

  v3.NextHandle = 0;
  Scaleform::StatsUpdate::MemReport(&v3, rootItem, reportType);
}
