void __thiscall Scaleform::GFx::AS3::ValueRegisterFile::Reserve(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 n)
{
  unsigned __int16 ReservedNum; // cx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pCurrentPage; // edx
  __int16 v5; // bx
  Scaleform::GFx::AS3::Value *Values; // eax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v7; // eax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v8; // eax
  int v9; // ecx
  int v10; // edx
  Scaleform::GFx::AS3::Value *v11; // eax

  ReservedNum = this->ReservedNum;
  pCurrentPage = this->pCurrentPage;
  if ( ReservedNum + n > pCurrentPage->PageSize )
  {
    v7 = Scaleform::GFx::AS3::ValueRegisterFile::NewPage(this, n);
    v5 = 0;
    v7->pNext = 0;
    v7->pPrev = this->pCurrentPage;
    this->pCurrentPage->pNext = v7;
    this->pCurrentPage->ReservedNum = this->ReservedNum;
    this->pCurrentPage->pCurrent = this->pRF;
    this->pCurrentPage = v7;
    Values = v7->Values;
    this->ReservedNum = n;
  }
  else
  {
    v5 = ReservedNum - (((char *)this->pRF - (char *)pCurrentPage - 24) >> 4);
    Values = &pCurrentPage->Values[ReservedNum];
    this->ReservedNum = n + ReservedNum;
  }
  this->pRF = Values;
  v8 = this->pCurrentPage;
  *((_WORD *)&v8->Values[v8->PageSize].Flags + v8->CurrPos++) = v5;
  if ( n )
  {
    v9 = 0;
    v10 = n;
    do
    {
      v11 = &this->pRF[v9];
      if ( v11 )
      {
        v11->Flags = 0;
        v11->Bonus.pWeakProxy = 0;
      }
      ++v9;
      --v10;
    }
    while ( v10 );
  }
}
