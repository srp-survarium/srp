void __thiscall Scaleform::GFx::AS3::VM::exec_callpropvoid(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // edi
  Scaleform::GFx::AS3::WeakProxy *v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-101h] BYREF
  Scaleform::GFx::AS3::Value v13; // [esp+14h] [ebp-100h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+24h] [ebp-F0h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+34h] [ebp-E0h] BYREF
  Scaleform::GFx::AS3::ReadArgsMnObject args; // [esp+4Ch] [ebp-C8h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::FindObjProperty(
      &prop,
      this,
      (Scaleform::GFx::AS3::Value *)&args.ArgObject,
      (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
      FindCall);
    if ( (prop.This.Flags & 0x1F) == 0
      || ((int)prop.pSI & 1) != 0 && ((int)prop.pSI & 0xFFFFFFFE) == 0
      || ((int)prop.pSI & 2) != 0 && ((int)prop.pSI & 0xFFFFFFFD) == 0 )
    {
      if ( (Scaleform::GFx::AS3::VM::GetValueTraits(this, &args.ArgObject)->Flags & 2) != 0 )
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v13, eCallOfNonFunctionError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v9,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v13, eReadSealedError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v10,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      }
      pWeakProxy = (Scaleform::GFx::ASStringNode *)v13.Bonus.pWeakProxy;
      --v13.Bonus.pWeakProxy[1].pObject;
      if ( !pWeakProxy->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
      goto LABEL_33;
    }
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &result, this, &value, valExecute)->Result )
    {
      if ( (value.Flags & 0x1F) != 0 && ((value.Flags & 0x1F) - 12 > 3 || value.value.VS._1.VInt) )
      {
        FixedArr = args.FixedArr;
        if ( args.ArgNum > 8 )
          FixedArr = args.CallArgs.Data.Data;
        if ( (_S10_0 & 1) == 0 )
        {
          _S10_0 |= 1u;
          v.Flags = 0;
          v.Bonus.pWeakProxy = 0;
          atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
        }
        v13 = v;
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            ++v.Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(&v);
        }
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &value, &args.ArgObject, &v13, arg_count, FixedArr, 0);
        if ( (v13.Flags & 0x1F) > 9 )
        {
          if ( (v13.Flags & 0x200) != 0 )
          {
            v8 = v13.Bonus.pWeakProxy;
            --v13.Bonus.pWeakProxy->RefCount;
            if ( !v8->RefCount )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
              Scaleform::GFx::AS3::Value::~Value(&value);
              goto LABEL_33;
            }
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v13, eCallOfNonFunctionError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v5,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v6 = (Scaleform::GFx::ASStringNode *)v13.Bonus.pWeakProxy;
        --v13.Bonus.pWeakProxy[1].pObject;
        if ( !v6->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      }
    }
    Scaleform::GFx::AS3::Value::~Value(&value);
LABEL_33:
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  }
  Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject(&args);
}
