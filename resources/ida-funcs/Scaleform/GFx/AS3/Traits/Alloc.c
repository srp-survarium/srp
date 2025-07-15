int __thiscall Scaleform::GFx::AS3::Traits::Alloc(Scaleform::GFx::AS3::Traits *this)
{
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::AllocInfo ainfo; // [esp+0h] [ebp-4h] BYREF

  ainfo.StatId = (unsigned int)this;
  MemSize = this->MemSize;
  pVM = this->pVM;
  ainfo.StatId = 337;
  return (int)pVM->MHeap->Alloc(pVM->MHeap, MemSize, &ainfo);
}
