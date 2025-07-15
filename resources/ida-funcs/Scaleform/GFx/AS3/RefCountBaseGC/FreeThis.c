void __thiscall Scaleform::GFx::AS3::RefCountBaseGC<328>::FreeThis(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc)
{
  this->RefCount &= 0x8FFFFFFF;
  if ( (this->RefCount & 0x1000000) != 0 )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->RefCount &= ~0x1000000u;
    ((void (__thiscall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, int))this->~Scaleform::GFx::AS3::RefCountBaseGC<328>)(
      this,
      1);
  }
  else
  {
    if ( (this->RefCount & 0x80000000) != 0 )
      Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(
        (Scaleform::GFx::AS3::RefCountCollector<328> *)(this->pRCCRaw & 0xFFFFFFFC),
        this);
    ((void (__thiscall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, int))this->~Scaleform::GFx::AS3::RefCountBaseGC<328>)(
      this,
      1);
  }
}
