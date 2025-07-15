void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3propertyIsEnumerable(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  long double v5; // [esp+4h] [ebp-20h]
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+Ch] [ebp-18h] BYREF

  if ( argc && (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, this->pTraits.pObject->pVM, argv);
    if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&argc, &prop_name, (unsigned int *)&argv)->Result
      && (unsigned int)argv < this->List.Data.Size )
    {
      Scaleform::GFx::AS3::Value::SetBool(result, 1);
      Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
      return;
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  }
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  LOBYTE(v5) = 0;
  result->Flags = result->Flags & 0xFFFFFFE0 | 1;
  result->value.VNumber = v5;
}
