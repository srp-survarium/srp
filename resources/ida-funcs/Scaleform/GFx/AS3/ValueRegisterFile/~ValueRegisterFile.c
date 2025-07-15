void __thiscall Scaleform::GFx::AS3::ValueRegisterFile::~ValueRegisterFile(
        Scaleform::GFx::AS3::ValueRegisterFile *this)
{
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pReserved; // eax
  unsigned __int16 i; // bx
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pCurrentPage; // edi

  while ( this->pReserved )
  {
    pReserved = this->pReserved;
    this->pReserved = pReserved->pNext;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pReserved);
  }
  for ( i = 0; i < this->ReservedNum; ++i )
  {
    v4 = &this->pRF[i];
    if ( (v4->Flags & 0x1F) > 9 )
    {
      if ( (v4->Flags & 0x200) != 0 )
      {
        pWeakProxy = v4->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        v4->Flags &= 0xFFFFFDE0;
        v4->Bonus.pWeakProxy = 0;
        v4->value.VS._1.VInt = 0;
        v4->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&this->pRF[i]);
      }
    }
  }
  pCurrentPage = this->pCurrentPage;
  if ( pCurrentPage )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pCurrentPage);
}
