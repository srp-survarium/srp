void __thiscall Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // ecx
  signed int RefCount; // eax
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // edi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pRootHead; // eax

  pRCC = this->_pRCC;
  RefCount = this->RefCount;
  v4 = (Scaleform::GFx::AS3::RefCountCollector<328> *)((unsigned int)pRCC & 0xFFFFFFFC);
  if ( (RefCount & 0x3FFFFF) != 0 )
  {
    if ( (RefCount & 0x70000000) != 0x30000000 )
    {
      if ( (RefCount & 0x1000000) != 0 || RefCount < 0 )
      {
        this->RefCount = RefCount & 0x8FFFFFFF | 0x30000000;
      }
      else if ( (v4->Flags & 8) == 0 )
      {
        p_pRootHead = &v4->Roots[(unsigned __int8)pRCC & 3].pRootHead;
        this->pNext = *p_pRootHead;
        this->pPrev = 0;
        if ( *p_pRootHead )
          (*p_pRootHead)->pPrev = this;
        ++v4->Roots[(unsigned __int8)pRCC & 3].nRoots;
        *p_pRootHead = this;
        this->RefCount = this->RefCount & 0xFFFFFFF | 0xB0000000;
      }
    }
  }
  else
  {
    if ( (RefCount & 0x2000000) != 0 )
      this->Finalize_GC(this);
    if ( (this->RefCount & 0x1000000) != 0 )
      this->RefCount |= 0x800000u;
    else
      Scaleform::GFx::AS3::RefCountBaseGC<328>::FreeThis(this, v4);
  }
}
