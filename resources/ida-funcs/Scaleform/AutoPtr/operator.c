Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *__thiscall Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p)
{
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pObject; // edi

  pObject = this->pObject;
  if ( this->pObject != p )
  {
    if ( pObject && this->Owner )
    {
      this->Owner = 0;
      if ( pObject->Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pObject);
    }
    this->pObject = p;
  }
  this->Owner = p != 0;
  return this;
}
