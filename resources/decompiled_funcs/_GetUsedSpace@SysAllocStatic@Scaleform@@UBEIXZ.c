unsigned int __thiscall Scaleform::SysAllocStatic::GetUsedSpace(Scaleform::SysAllocStatic *this)
{
  return this->TotalSpace - (this->pAllocator->FreeBlocks << this->pAllocator->MinShift);
}
