void __thiscall Scaleform::GFx::AS3::ValueRegisterFile::ReleaseReserved(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 n)
{
  unsigned __int16 v2; // ax
  int v4; // ebx
  int v5; // ebp
  Scaleform::GFx::AS3::Value *pRF; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *v8; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pCurrentPage; // eax
  int PageSize; // edx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v13; // eax
  unsigned __int16 MaxReservedPageSize; // cx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v15; // edx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pPrev; // eax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v17; // edx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v18; // eax

  v2 = n;
  if ( n )
  {
    v4 = 0;
    v5 = n;
    do
    {
      pRF = this->pRF;
      Flags = pRF[v4].Flags;
      v8 = &pRF[v4];
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
        {
          pWeakProxy = v8->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          v8->Flags &= 0xFFFFFDE0;
          v8->Bonus.pWeakProxy = 0;
          v8->value.VS._1.VInt = 0;
          v8->value.VS._2.VObj = 0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v8);
        }
      }
      ++v4;
      --v5;
    }
    while ( v5 );
    v2 = n;
  }
  this->ReservedNum -= v2;
  pCurrentPage = this->pCurrentPage;
  PageSize = pCurrentPage->PageSize;
  this->pRF -= *((unsigned __int16 *)&pCurrentPage->Values[PageSize].Flags + --pCurrentPage->CurrPos);
  if ( !this->ReservedNum )
  {
    v13 = this->pCurrentPage;
    if ( v13->pPrev )
    {
      MaxReservedPageSize = this->MaxReservedPageSize;
      if ( MaxReservedPageSize < v13->PageSize )
        MaxReservedPageSize = v13->PageSize;
      v15 = this->pCurrentPage;
      this->MaxReservedPageSize = MaxReservedPageSize;
      pPrev = v13->pPrev;
      v15->pPrev = 0;
      this->pCurrentPage->pNext = this->pReserved;
      v17 = this->pCurrentPage;
      this->pCurrentPage = pPrev;
      this->pReserved = v17;
      pPrev->pNext = 0;
      v18 = this->pCurrentPage;
      this->ReservedNum = v18->ReservedNum;
      this->pRF = v18->pCurrent;
    }
  }
}
