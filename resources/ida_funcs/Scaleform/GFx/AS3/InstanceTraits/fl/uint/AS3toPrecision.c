void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toPrecision(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  char *pStr; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  const Scaleform::GFx::AS3::Instances::fl::Namespace *CurrNamespace; // eax
  Scaleform::GFx::ASStringNode *ID; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult v12; // [esp+13h] [ebp-19Dh] BYREF
  unsigned int precision; // [esp+14h] [ebp-19Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v; // [esp+18h] [ebp-198h] BYREF
  Scaleform::StringDataPtr v15; // [esp+20h] [ebp-190h] BYREF
  Scaleform::DoubleFormatter f; // [esp+28h] [ebp-188h] BYREF

  precision = 0;
  if ( !argc )
    goto LABEL_8;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &v12, &precision)->Result )
    return;
  if ( precision && precision <= 0x15 )
  {
    Scaleform::DoubleFormatter::DoubleFormatter(&f, (double)_this->value.VS._1.VUInt);
    f.Type = FmtSignificant;
    *(_DWORD *)&f.Scaleform::NumericBase ^= ((unsigned __int8)precision ^ *(_BYTE *)&f.Scaleform::NumericBase) & 0x1F;
    f.Convert(&f);
    pStr = (char *)Scaleform::DoubleFormatter::GetResult(&f, &v15)->pStr;
    StringManagerRef = vm->StringManagerRef;
    CurrNamespace = Scaleform::GFx::AS3::Instances::fl::XMLElement::GetCurrNamespace((Scaleform::GFx::AS3::Instances::fl::XMLAttr *)&f);
    v.ID = (Scaleform::GFx::AS3::VM::ErrorID)Scaleform::GFx::ASStringManager::CreateStringNode(
                                               StringManagerRef->pStringManager,
                                               pStr,
                                               (unsigned int)CurrNamespace);
    ++*(_DWORD *)(v.ID + 12);
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&v);
    ID = (Scaleform::GFx::ASStringNode *)v.ID;
    --*(_DWORD *)(v.ID + 12);
    if ( !ID->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(ID);
    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Formatter::~Formatter(&f);
  }
  else
  {
LABEL_8:
    Scaleform::GFx::AS3::VM::Error::Error(&v, eInvalidPrecisionError, vm);
    Scaleform::GFx::AS3::VM::ThrowRangeError(vm, v10);
    pNode = v.Message.pNode;
    --v.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
