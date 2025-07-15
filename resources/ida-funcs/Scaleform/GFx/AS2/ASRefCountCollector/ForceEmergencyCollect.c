void __thiscall Scaleform::GFx::AS2::ASRefCountCollector::ForceEmergencyCollect(
        Scaleform::GFx::AS2::ASRefCountCollector *this)
{
  unsigned int Size; // edi
  unsigned int PeakRootCount; // eax
  bool v4; // zf
  unsigned int PresetMaxRootCount; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats v6; // [esp+Ch] [ebp-8h] BYREF

  Size = this->Roots.Size;
  v6.RootsFreedTotal = 0;
  v6.RootsNumber = 0;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, &v6);
  PeakRootCount = this->PeakRootCount;
  this->FrameCnt = 0;
  if ( Size >= PeakRootCount )
    PeakRootCount = Size;
  v4 = (this->Flags & 1) == 0;
  this->PeakRootCount = PeakRootCount;
  this->LastRootCount = Size;
  if ( v4 && !this->Roots.Size )
    Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease(&this->Roots);
  PresetMaxRootCount = this->PresetMaxRootCount;
  this->PeakRootCount = 0;
  this->MaxRootCount = PresetMaxRootCount;
}
