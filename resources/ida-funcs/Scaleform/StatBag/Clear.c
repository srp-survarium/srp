void __thiscall Scaleform::StatBag::Clear(Scaleform::StatBag *this)
{
  this->MemAllocOffset = 0;
  memset(this->IdPageTable, 0xFFu, sizeof(this->IdPageTable));
}
