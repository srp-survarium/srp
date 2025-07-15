Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::ExecutePropertyUnsafe(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *resulta,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  __int16 Flags; // ax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult v12; // [esp+Fh] [ebp-31h] BYREF
  Scaleform::GFx::AS3::VM::Error v13; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value funct; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+28h] [ebp-18h] BYREF

  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::FindObjProperty(&prop, vm, _this, prop_name, FindGet);
  Flags = prop.This.Flags;
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
  {
    funct.Flags = 0;
    funct.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &v12, vm, &funct, valGet)->Result )
    {
      if ( (funct.Flags & 0x1F) != 0 && ((funct.Flags & 0x1F) - 12 > 3 || funct.value.VS._1.VInt) )
      {
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &funct, _this, resulta, argc, argv, 0);
        result->Result = !vm->HandleException;
        Scaleform::GFx::AS3::Value::~Value(&funct);
        Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
        return result;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v13, eConvertNullToObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v8,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v13.Message.pNode;
      --v13.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::GFx::AS3::Value::~Value(&funct);
    Flags = prop.This.Flags;
  }
  result->Result = 0;
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = prop.This.Bonus.pWeakProxy;
      --prop.This.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return result;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
    }
  }
  return result;
}
