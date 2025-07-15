void __thiscall Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1>>::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1>>(
        Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1> > *this,
        const Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1> > *a)
{
  Scaleform::Waitable::HandlerStruct *Data; // ebp
  unsigned int Size; // edi
  unsigned int v5; // ebx

  this->Data.Data = 0;
  this->Data.Size = 0;
  this->Data.Policy.Capacity = 0;
  Data = a->Data.Data;
  Size = a->Data.Size;
  if ( Size )
  {
    v5 = this->Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::ResizeNoConstruct(
      &this->Data,
      this,
      v5 + Size);
    Scaleform::ConstructorMov<Scaleform::Waitable::HandlerStruct>::ConstructArray(
      &this->Data.Data[v5].Handler,
      Size,
      Data);
  }
}
