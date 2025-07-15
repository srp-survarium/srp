void __cdecl Scaleform::GFx::AS3::Instances::FunctionBase::apply(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Size; // edi
  Scaleform::GFx::AS3::VM *v8; // ebx
  Scaleform::GFx::AS3::ClassTraits::fl::Array *pObject; // ecx
  Scaleform::GFx::AS3::Value *Data; // ebp
  unsigned int v11; // ecx
  const Scaleform::GFx::AS3::Value *v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // esi
  Scaleform::GFx::AS3::Value *v15; // ebx
  const Scaleform::GFx::AS3::Value *v16; // eax
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::Value *v19; // [esp-14h] [ebp-54h]
  Scaleform::GFx::AS3::VM::Error v20; // [esp+8h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v22; // [esp+20h] [ebp-20h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+30h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *argca; // [esp+54h] [ebp+14h]

  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  r = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  Size = 0;
  if ( !argc )
  {
    v19 = Scaleform::GFx::AS3::Value::GetUndefined();
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, v19, &r, 0, argv, 0);
    goto LABEL_32;
  }
  if ( argc == 1 )
  {
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, argv, &r, 0, 0, 0);
    goto LABEL_32;
  }
  v8 = vm;
  pObject = vm->TraitsArray.pObject;
  v22.Flags = 0;
  v22.Bonus.pWeakProxy = 0;
  if ( pObject->Coerce(pObject, argv + 1, &v22) )
  {
    args.Data.pHeap = vm->MHeap;
    Data = 0;
    v11 = 0;
    v12 = 0;
    memset(&args, 0, 12);
    if ( (v22.Flags & 0x1F) - 12 > 3 || v22.value.VS._1.VInt )
    {
      v13 = *(_DWORD *)(v22.value.VS._1.VInt + 32);
      argca = (Scaleform::GFx::AS3::Impl::SparseArray *)(v22.value.VS._1.VInt + 32);
      if ( v13 <= *(_DWORD *)(v22.value.VS._1.VInt + 68) )
      {
        v11 = *(_DWORD *)(v22.value.VS._1.VInt + 68);
        v12 = *(const Scaleform::GFx::AS3::Value **)(v22.value.VS._1.VInt + 64);
      }
      else
      {
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &args.Data,
          v13);
        Size = args.Data.Size;
        Data = args.Data.Data;
        v14 = 0;
        if ( args.Data.Size )
        {
          v15 = args.Data.Data;
          do
          {
            v16 = Scaleform::GFx::AS3::Impl::SparseArray::At(argca, v14);
            Scaleform::GFx::AS3::Value::Assign(v15, v16);
            ++v14;
            ++v15;
          }
          while ( v14 < Size );
          v8 = vm;
        }
        v11 = Size;
        v12 = Data;
      }
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v8, _this, argv, &r, v11, v12, 0);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(Data, Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    if ( (v22.Flags & 0x1F) > 9 )
    {
      if ( (v22.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v22);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
    }
LABEL_32:
    Scaleform::GFx::AS3::Value::Swap(result, &r);
    if ( (r.Flags & 0x1F) <= 9 )
      return;
    if ( (r.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      return;
    }
    goto LABEL_35;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v20, eApplyError, vm);
  Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v17);
  pNode = v20.Message.pNode;
  --v20.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (v22.Flags & 0x1F) > 9 )
  {
    if ( (v22.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v22);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
  }
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      return;
    }
LABEL_35:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
}
