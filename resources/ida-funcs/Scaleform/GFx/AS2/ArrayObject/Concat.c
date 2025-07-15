void __thiscall Scaleform::GFx::AS2::ArrayObject::Concat(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::MemoryHeap *pHeap; // edi
  const Scaleform::GFx::AS2::Value *v5; // ebp
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // esi
  unsigned int RootIndex; // eax
  unsigned int Size; // ebp
  unsigned int v10; // edi
  unsigned int v11; // ebp
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::Environment *v15; // eax
  Scaleform::GFx::AS2::Environment *v16; // [esp-4h] [ebp-14h]

  if ( ++this->RecursionCount >= 255 )
  {
    Scaleform::GFx::LogState::LogMessageByType(
      (Scaleform::GFx::LogState *)this->LogPtr,
      (Scaleform::LogMessageId)212992,
      "256 levels of recursion is reached\n");
    --this->RecursionCount;
    return;
  }
  pHeap = penv->StringContext.pContext->pHeap;
  v5 = val;
  v16 = penv;
  penv = (Scaleform::GFx::AS2::Environment *)pHeap;
  v6 = Scaleform::GFx::AS2::Value::ToObject(val, v16);
  v7 = v6;
  if ( !v6 || v6->GetObjectType(&v6->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
  {
    v14 = (Scaleform::GFx::AS2::Value *)pHeap->Alloc(pHeap, 16u, 0);
    if ( v14 )
    {
      Scaleform::GFx::AS2::Value::Value(v14, v5);
      penv = v15;
    }
    else
    {
      penv = 0;
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      &this->Elements,
      (Scaleform::GFx::AS2::Value **)&penv);
    goto LABEL_17;
  }
  RootIndex = v7[1].RootIndex;
  if ( !RootIndex
    || (Size = this->Elements.Data.Size,
        Scaleform::GFx::AS2::ArrayObject::Resize(this, Size + RootIndex),
        v10 = 0,
        !v7[1].RootIndex) )
  {
LABEL_17:
    --this->RecursionCount;
    return;
  }
  v11 = Size;
  do
  {
    v12 = (Scaleform::GFx::AS2::Value *)((int (__thiscall *)(Scaleform::GFx::AS2::Environment *, int, _DWORD))penv->__vftable[5].~Scaleform::GFx::AS2::Environment)(
                                          penv,
                                          16,
                                          0);
    if ( v12 )
      Scaleform::GFx::AS2::Value::Value(
        v12,
        (const Scaleform::GFx::AS2::Value *)(&v7[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v10]);
    else
      v13 = 0;
    this->Elements.Data.Data[v11] = v13;
    ++v10;
    ++v11;
  }
  while ( v10 < v7[1].RootIndex );
  --this->RecursionCount;
}
