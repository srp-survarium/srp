void __thiscall Scaleform::GFx::AS2::RefCountBaseGC<323>::RemoveFromList(
        Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  unsigned int v1; // eax

  *(_DWORD *)(this->RootIndex + 4) = this->pRCC;
  *(_DWORD *)&this->pRCC->Roots.gap0 = this->RootIndex;
  this->RefCount &= 0x77FFFFFFu;
  v1 = this->RefCount >> 27;
  this->pRCC = 0;
  if ( (v1 & 1) == 0 )
    this->RootIndex = -1;
}
