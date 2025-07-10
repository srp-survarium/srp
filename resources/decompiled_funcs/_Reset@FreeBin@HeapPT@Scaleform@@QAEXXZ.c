void __thiscall Scaleform::HeapPT::FreeBin::Reset(Scaleform::HeapPT::FreeBin *this)
{
  this->ListBin1.Mask = 0;
  memset((int)this->ListBin1.Roots, 0, sizeof(this->ListBin1.Roots));
  this->ListBin2.Mask = 0;
  memset((int)this->ListBin2.Roots, 0, sizeof(this->ListBin2.Roots));
  this->TreeBin1.Mask = 0;
  memset((int)this->TreeBin1.Roots, 0, sizeof(this->TreeBin1.Roots));
  this->FreeBlocks = 0;
}
