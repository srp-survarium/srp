void __thiscall Scaleform::GFx::AS3::ValueStack::ReleaseReserved(
        Scaleform::GFx::AS3::ValueStack *this,
        Scaleform::GFx::AS3::Value *first)
{
  Scaleform::GFx::AS3::ValueStack::Page *pCurrentPage; // eax
  Scaleform::GFx::AS3::ValueStack::Page *pPrev; // edx
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::AS3::Value *Values; // edx
  Scaleform::GFx::AS3::Value::VU *p_value; // esi
  bool v7; // zf
  Scaleform::GFx::AS3::Value *v8; // eax

  --this->pCurrentPage->ReservationNum;
  pCurrentPage = this->pCurrentPage;
  if ( pCurrentPage->ReservationNum || !pCurrentPage->pPrev )
  {
    this->pStack = first;
  }
  else
  {
    pPrev = pCurrentPage->pPrev;
    this->pCurrentPage = pPrev;
    pCurrent = this->pCurrent;
    pPrev->pNext = 0;
    this->pCurrent = this->pCurrentPage->pCurrent;
    this->pStack = this->pCurrentPage->pFirst;
    pCurrentPage->pNext = this->pReserved;
    Values = pCurrentPage->Values;
    this->pReserved = pCurrentPage;
    if ( pCurrentPage->Values <= pCurrent )
    {
      p_value = &pCurrentPage->Values[0].value;
      do
      {
        v7 = this->pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
        v8 = this->pCurrent;
        if ( !v7 )
        {
          v8->Flags = Values->Flags;
          v8->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)p_value[-1].VS._2.VObj;
          v8->value.VS._1.VInt = p_value->VS._1.VInt;
          v8->value.VS._2.VObj = p_value->VS._2.VObj;
          Values->Flags = 0;
        }
        ++Values;
        p_value += 2;
      }
      while ( Values <= pCurrent );
    }
  }
}
