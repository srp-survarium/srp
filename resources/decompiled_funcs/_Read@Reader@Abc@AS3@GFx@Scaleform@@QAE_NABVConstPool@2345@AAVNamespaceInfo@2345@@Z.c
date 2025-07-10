bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::NamespaceInfo *obj)
{
  const unsigned __int8 *v3; // eax
  unsigned __int8 v4; // bl
  bool result; // al
  Scaleform::StringDataPtr zero_val; // [esp+8h] [ebp-8h] BYREF

  v3 = this->CP;
  v4 = *v3;
  this->CP = v3 + 1;
  zero_val.pStr = (const char *)&buf;
  zero_val.Size = 0;
  result = Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->NameURI, &zero_val) != 0;
  switch ( v4 )
  {
    case 5u:
      obj->Kind = NS_Private;
      break;
    case 8u:
    case 0x16u:
      obj->Kind = NS_Public;
      break;
    case 0x17u:
      obj->Kind = NS_PackageInternal;
      break;
    case 0x18u:
      obj->Kind = NS_Protected;
      break;
    case 0x19u:
      obj->Kind = NS_Explicit;
      break;
    case 0x1Au:
      obj->Kind = NS_StaticProtected;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
