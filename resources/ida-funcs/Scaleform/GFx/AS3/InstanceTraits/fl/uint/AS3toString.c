void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toString(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::Value *v6; // esi
  unsigned int v7; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  const Scaleform::GFx::AS3::Value *StringNode; // eax
  Scaleform::GFx::AS3::Value *v10; // ecx
  Scaleform::GFx::ASStringNode *v11; // eax
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int radix; // [esp+4h] [ebp-64h] BYREF
  Scaleform::StringDataPtr r; // [esp+8h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-58h] BYREF
  Scaleform::LongFormatter f; // [esp+18h] [ebp-50h] BYREF

  v6 = _this;
  v7 = _this->Flags & 0x1F;
  if ( v7 != 2 && v7 != 3 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v8);
    goto LABEL_13;
  }
  radix = 10;
  if ( argc && (argv->Flags & 0x1F) != 0 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&_this, &radix)->Result )
      return;
    if ( radix < 2 || radix > 0x10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eInvalidRadixError, vm, radix);
      Scaleform::GFx::AS3::VM::ThrowRangeError(vm, v12);
LABEL_13:
      pNode = v16.Message.pNode;
      --v16.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
  }
  Scaleform::LongFormatter::LongFormatter(&f, v6->value.VS._1.VUInt);
  *((_BYTE *)&f.Scaleform::NumericBase + 6) &= ~1u;
  *((_DWORD *)&f + 7) ^= ((unsigned __int8)radix ^ *((_BYTE *)&f + 28)) & 0x1F;
  f.Convert(&f);
  Scaleform::DoubleFormatter::GetResult((Scaleform::DoubleFormatter *)&f, &r);
  StringNode = (const Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                     vm->StringManagerRef->pStringManager,
                                                     (__m128i *)r.pStr,
                                                     r.Size);
  v10 = result;
  _this = (Scaleform::GFx::AS3::Value *)StringNode;
  ++StringNode->value.VS._2.VObj;
  Scaleform::GFx::AS3::Value::Assign(v10, (const Scaleform::GFx::ASString *)&_this);
  v11 = (Scaleform::GFx::ASStringNode *)_this;
  --_this->value.VS._2.VObj;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::Formatter::~Formatter(&f);
}
