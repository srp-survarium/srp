void __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::Stats::Stats(
        Scaleform::GFx::AS3::RefCountCollector<328>::Stats *this,
        Scaleform::GFx::Resource *advanceStats)
{
  if ( advanceStats )
    Scaleform::RefCountImpl::AddRef(advanceStats);
  this->AdvanceStats.pObject = (Scaleform::AmpStats *)advanceStats;
  this->GensNumber = 0;
  this->ObjectsFreedTotal = 0;
  this->ObjectsIteratedNumber = 0;
  this->RootsFreedTotal = 0;
  this->RootsNumber = 0;
}
