void __thiscall Scaleform::GFx::AS3::TR::State::exec_applytype(Scaleform::GFx::AS3::TR::State *this, int arg_count)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  Scaleform::GFx::AS3::Value *FixedArr; // edx
  Scaleform::GFx::AS3::ClassTraits::fl::Object *pObject; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v9; // eax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *ClassVector; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v11; // [esp-4h] [ebp-D0h]
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-C0h] BYREF
  Scaleform::GFx::AS3::TR::ReadArgsObject args; // [esp+1Ch] [ebp-B0h] BYREF

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v4 = WCode->Size + 1;
  if ( v4 >= WCode->Size )
  {
    if ( v4 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v4 + (v4 >> 2));
  }
  else if ( v4 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v4;
  Data[v4 - 1] = arg_count;
  VMRef = this->pTracer->CF->pFile->VMRef;
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&args, VMRef, this, arg_count);
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    &args.ArgObject);
  ++args.Num;
  FixedArr = args.FixedArr;
  if ( args.ArgNum <= args.CallArgs.Data.Size )
    FixedArr = args.CallArgs.Data.Data;
  pObject = 0;
  switch ( FixedArr->Flags & 0x1F )
  {
    case 0u:
      pObject = VMRef->TraitsObject.pObject;
      break;
    case 9u:
      pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)FixedArr->value.VS._1.VInt;
      break;
    case 0xCu:
      if ( !FixedArr->value.VS._1.VInt )
        pObject = VMRef->TraitsObject.pObject;
      break;
    case 0xDu:
      pObject = *(Scaleform::GFx::AS3::ClassTraits::fl::Object **)(FixedArr->value.VS._1.VInt + 20);
      break;
    default:
      break;
  }
  v9 = VMRef->TraitsObject.pObject;
  if ( pObject )
  {
    if ( pObject == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsInt.pObject )
    {
      v9 = VMRef->TraitsVector_int.pObject;
    }
    else if ( pObject == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsUint.pObject )
    {
      v9 = VMRef->TraitsVector_uint.pObject;
    }
    else if ( pObject == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsNumber.pObject )
    {
      v9 = VMRef->TraitsVector_Number.pObject;
    }
    else if ( pObject == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsString.pObject )
    {
      v9 = VMRef->TraitsVector_String.pObject;
    }
    else
    {
      v11 = pObject;
      ClassVector = Scaleform::GFx::AS3::VM::GetClassVector(VMRef);
      v9 = Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(ClassVector, v11);
    }
  }
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)v9;
  val.Flags = 9;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject(&args);
}
