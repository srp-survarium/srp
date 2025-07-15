void __thiscall Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(
        Scaleform::GFx::AS2::ArraySortOnFunctor *this,
        const Scaleform::GFx::AS2::ArraySortOnFunctor *__that)
{
  Scaleform::Array<Scaleform::GFx::AS2::ArraySortFunctor,2,Scaleform::ArrayDefaultPolicy> *p_FunctorArray; // esi
  unsigned int Size; // ebx
  unsigned int v4; // ebp
  Scaleform::GFx::AS2::ArraySortFunctor *Data; // [esp+10h] [ebp+4h]

  this->This = __that->This;
  this->FieldArray = __that->FieldArray;
  this->Env = __that->Env;
  this->LogPtr = __that->LogPtr;
  p_FunctorArray = &this->FunctorArray;
  this->FunctorArray.Data.Data = 0;
  this->FunctorArray.Data.Size = 0;
  this->FunctorArray.Data.Policy.Capacity = 0;
  Size = __that->FunctorArray.Data.Size;
  Data = __that->FunctorArray.Data.Data;
  if ( Size )
  {
    v4 = this->FunctorArray.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->FunctorArray.Data,
      &this->FunctorArray,
      Size + v4);
    Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::ConstructArray(
      (char *)&p_FunctorArray->Data.Data[v4],
      Size,
      Data);
  }
}
