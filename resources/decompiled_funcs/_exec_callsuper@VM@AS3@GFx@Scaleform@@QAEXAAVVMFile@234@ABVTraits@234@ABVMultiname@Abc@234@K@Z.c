void __thiscall Scaleform::GFx::AS3::VM::exec_callsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-E9h] BYREF
  Scaleform::GFx::AS3::Value v11; // [esp+14h] [ebp-E8h] BYREF
  Scaleform::GFx::AS3::Value func; // [esp+24h] [ebp-D8h] BYREF
  Scaleform::GFx::AS3::ReadArgsMnObject args; // [esp+34h] [ebp-C8h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    func.Flags = 0;
    func.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::GetSuperProperty(
           &result,
           this,
           ot,
           &func,
           (Scaleform::GFx::AS3::Value *)&args.ArgObject,
           (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
           valExecute)->Result )
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
      v11 = v;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          ++v.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &func, &args.ArgObject, &v11, arg_count, FixedArr, 1);
      if ( (v11.Flags & 0x1F) > 9 )
      {
        if ( (v11.Flags & 0x200) != 0 )
        {
          pWeakProxy = v11.Bonus.pWeakProxy;
          --v11.Bonus.pWeakProxy->RefCount;
          if ( !pWeakProxy->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v11, eCallNotFoundError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v6,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v7 = (Scaleform::GFx::ASStringNode *)v11.Bonus.pWeakProxy;
      --v11.Bonus.pWeakProxy[1].pObject;
      if ( !v7->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
    Scaleform::GFx::AS3::Value::~Value(&func);
  }
  Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject(&args);
}
