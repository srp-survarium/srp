void __thiscall Scaleform::StatsUpdate::SummaryStatIdVisitor::SummaryStatIdVisitor(
        Scaleform::StatsUpdate::SummaryStatIdVisitor *this,
        bool debug)
{
  this->__vftable = (Scaleform::StatsUpdate::SummaryStatIdVisitor_vtbl *)&Scaleform::StatsUpdate::SummaryStatIdVisitor::`vftable';
  Scaleform::StatBag::StatBag(&this->StatIdBag, 0, 0x2000u);
  this->Debug = debug;
  this->ExcludedHeaps.Data.Data = 0;
  this->ExcludedHeaps.Data.Size = 0;
  this->ExcludedHeaps.Data.Policy.Capacity = 0;
}
