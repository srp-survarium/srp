void __thiscall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::PushBack(
        Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this,
        const Scaleform::GFx::AS2::WithStackEntry *entry)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v3; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // edi
  unsigned int v5; // esi

  if ( !this->pWithStackArray )
  {
    v3 = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)((int (__stdcall *)(int, _DWORD))this->pHeap->Alloc)(12, 0);
    if ( v3 )
    {
      v3->Data.Data = 0;
      v3->Data.Size = 0;
      v3->Data.Policy.Capacity = 0;
    }
    else
    {
      v3 = 0;
    }
    this->pWithStackArray = v3;
  }
  pWithStackArray = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)this->pWithStackArray;
  v5 = pWithStackArray->Size + 1;
  if ( v5 >= pWithStackArray->Size )
  {
    if ( v5 >= pWithStackArray->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        pWithStackArray,
        pWithStackArray,
        v5 + (v5 >> 2));
  }
  else if ( v5 < pWithStackArray->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
      pWithStackArray,
      pWithStackArray,
      pWithStackArray->Size + 1);
  }
  pWithStackArray->Size = v5;
  pWithStackArray->Data[v5 - 1] = (Scaleform::GFx::AS2::AsFunctionObject::ArgSpec)*entry;
}
