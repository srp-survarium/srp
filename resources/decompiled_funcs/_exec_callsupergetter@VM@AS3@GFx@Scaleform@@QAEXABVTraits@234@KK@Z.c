void __thiscall Scaleform::GFx::AS3::VM::exec_callsupergetter(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Traits *ot,
        unsigned int method_index,
        unsigned int arg_count)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value v9; // [esp+Ch] [ebp-E0h] BYREF
  Scaleform::GFx::AS3::Value funct_getter; // [esp+1Ch] [ebp-D0h] BYREF
  Scaleform::GFx::AS3::Value funct; // [esp+2Ch] [ebp-C0h] BYREF
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+3Ch] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = *(Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    if ( ot->pParent.pObject )
    {
      funct_getter.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)ot->pParent.pObject;
      funct_getter.value.VS._1.VInt = method_index;
      funct_getter.Flags = 7;
      funct_getter.Bonus.pWeakProxy = 0;
      funct.Flags = 0;
      funct.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &funct_getter, &args.ArgObject, &funct, 0, 0, 0);
      if ( !this->HandleException )
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
        v9 = v;
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            ++v.Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(&v);
        }
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &funct, &args.ArgObject, &v9, arg_count, FixedArr, 1);
        if ( (v9.Flags & 0x1F) > 9 )
        {
          if ( (v9.Flags & 0x200) != 0 )
          {
            pWeakProxy = v9.Bonus.pWeakProxy;
            --v9.Bonus.pWeakProxy->RefCount;
            if ( !pWeakProxy->RefCount )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
          }
        }
      }
      Scaleform::GFx::AS3::Value::~Value(&funct);
      Scaleform::GFx::AS3::Value::~Value(&funct_getter);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v9, eIllegalSuperCallError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v5,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v6 = (Scaleform::GFx::ASStringNode *)v9.Bonus.pWeakProxy;
      --v9.Bonus.pWeakProxy[1].pObject;
      if ( !v6->RefCount )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
        Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
        return;
      }
    }
  }
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
}
