void __cdecl Scaleform::GFx::AS3::Instances::fl::XMLList::AS3hasOwnProperty(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *VInt; // edi
  bool rc; // [esp+Ch] [ebp-1Ch]
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+10h] [ebp-18h] BYREF

  if ( argc && (_this->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(_this->value.VS._1.VObj) )
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl::XMLList *)_this->value.VS._1.VInt;
    Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, vm, argv);
    rc = Scaleform::GFx::AS3::Instances::fl::XMLList::HasProperty(VInt, &prop_name);
    if ( rc )
    {
      Scaleform::GFx::AS3::Value::SetBool(result, rc);
      Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
      return;
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  }
  Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);
}
