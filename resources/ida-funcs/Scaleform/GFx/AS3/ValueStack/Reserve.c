void __thiscall Scaleform::GFx::AS3::ValueStack::Reserve(Scaleform::GFx::AS3::ValueStack *this, unsigned __int16 n)
{
  Scaleform::GFx::AS3::ValueStack::Page *pCurrentPage; // eax
  Scaleform::GFx::AS3::Value *pCurrent; // ecx
  Scaleform::GFx::AS3::ValueStack::Page *v5; // eax

  pCurrentPage = this->pCurrentPage;
  pCurrent = this->pCurrent;
  if ( &pCurrent[n] >= &pCurrentPage->Values[pCurrentPage->PageSize] )
  {
    v5 = Scaleform::GFx::AS3::ValueStack::NewPage(this, n);
    v5->pNext = 0;
    v5->pPrev = this->pCurrentPage;
    this->pCurrentPage->pNext = v5;
    this->pCurrentPage->pCurrent = this->pCurrent;
    this->pCurrentPage->pFirst = this->pStack;
    this->pCurrentPage = v5;
    v5 = (Scaleform::GFx::AS3::ValueStack::Page *)((char *)v5 + 24);
    this->pStack = (Scaleform::GFx::AS3::Value *)v5;
    this->NumOfReservedElem = n;
    this->pCurrent = v5[-1].Values;
  }
  else
  {
    this->NumOfReservedElem = n;
    this->pStack = pCurrent + 1;
  }
  ++this->pCurrentPage->ReservationNum;
}
