void __thiscall Scaleform::GFx::AS3::ValueStack::ValueStack(Scaleform::GFx::AS3::ValueStack *this)
{
  Scaleform::GFx::AS3::ValueStack::Page *v2; // eax
  Scaleform::GFx::AS3::Value *Values; // eax

  this->pCurrent = (Scaleform::GFx::AS3::Value *)-16;
  this->pStack = 0;
  this->pCurrentPage = 0;
  this->pReserved = 0;
  this->NumOfReservedElem = 0;
  v2 = Scaleform::GFx::AS3::ValueStack::NewPage(this, 0x40u);
  this->pCurrentPage = v2;
  v2->pNext = 0;
  this->pCurrentPage->pPrev = 0;
  this->pCurrentPage->pFirst = 0;
  this->pCurrentPage->pCurrent = 0;
  Values = this->pCurrentPage->Values;
  this->pStack = Values;
  this->pCurrent = Values - 1;
  Scaleform::GFx::AS3::ValueStack::Reserve(this, 1u);
}
