void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  char v6; // cl
  unsigned int v7; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  double val; // st7
  Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v12; // eax
  Scaleform::GFx::ASStringNode *Size; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::AS3::CheckResult v15; // [esp+Fh] [ebp-8Dh] BYREF
  int v; // [esp+10h] [ebp-8Ch] BYREF
  Scaleform::StringDataPtr r; // [esp+14h] [ebp-88h] BYREF
  unsigned int radix; // [esp+1Ch] [ebp-80h] BYREF
  Scaleform::GFx::ASString v19; // [esp+20h] [ebp-7Ch] BYREF
  Scaleform::LongFormatter f; // [esp+24h] [ebp-78h] BYREF
  char buffer[40]; // [esp+74h] [ebp-28h] BYREF

  v6 = _this->Flags & 0x1F;
  v7 = 10;
  radix = 10;
  if ( v6 != 4 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v8);
LABEL_17:
    Size = (Scaleform::GFx::ASStringNode *)r.Size;
LABEL_18:
    if ( !--Size->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(Size);
    return;
  }
  if ( argc && (argv->Flags & 0x1F) != 0 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &v15, &radix)->Result )
      return;
    v7 = radix;
    if ( radix < 2 || radix > 0x24 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&r, eInvalidRadixError, vm);
      Scaleform::GFx::AS3::VM::ThrowRangeError(vm, v14);
      goto LABEL_17;
    }
  }
  val = _this->value.VNumber;
  *(double *)&r = val;
  if ( v7 == 10 )
  {
LABEL_15:
    v12 = Scaleform::GFx::AS3::SF_ECMA_dtostr(buffer, 40, val);
    v = (int)Scaleform::GFx::ASStringManager::CreateStringNode(vm->StringManagerRef->pStringManager, buffer, v12);
    ++*(_DWORD *)(v + 12);
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&v);
    Size = (Scaleform::GFx::ASStringNode *)v;
    goto LABEL_18;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(val) )
  {
    val = *(double *)&r;
    goto LABEL_15;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(_this, &v15, &v)->Result )
  {
    Scaleform::LongFormatter::LongFormatter(&f, v);
    *((_BYTE *)&f.Scaleform::NumericBase + 6) &= ~1u;
    *((_DWORD *)&f + 7) ^= ((unsigned __int8)radix ^ *((_BYTE *)&f + 28)) & 0x1F;
    f.Convert(&f);
    Scaleform::DoubleFormatter::GetResult((Scaleform::DoubleFormatter *)&f, &r);
    v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
            vm->StringManagerRef,
            &v19,
            (char *)r.pStr,
            r.Size);
    Scaleform::GFx::AS3::Value::operator=(result, v10);
    pNode = v19.pNode;
    --v19.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Formatter::~Formatter(&f);
  }
}
