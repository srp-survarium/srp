void __thiscall Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>(
        Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *this)
{
  if ( this->Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data);
}
