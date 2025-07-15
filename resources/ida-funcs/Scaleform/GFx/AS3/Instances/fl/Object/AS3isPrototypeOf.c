void __cdecl Scaleform::GFx::AS3::Instances::fl::Object::AS3isPrototypeOf(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::StringDataPtr v14; // [esp-14h] [ebp-24h]
  Scaleform::GFx::AS3::VM::Error v15; // [esp+8h] [ebp-8h] BYREF

  if ( (_this->Flags & 0x1F) != 0 && ((_this->Flags & 0x1F) - 12 > 3 || _this->value.VS._1.VInt) )
  {
    if ( argc )
    {
      if ( (argv->Flags & 0x1F) != 0
        && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt)
        && (VObj = _this->value.VS._1.VObj, (pObject = Scaleform::GFx::AS3::VM::GetValueTraits(vm, argv)) != 0) )
      {
        while ( 1 )
        {
          Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
          if ( Scaleform::GFx::AS3::Class::GetPrototype(Constructor) == VObj )
            break;
          pObject = pObject->pParent.pObject;
          if ( !pObject )
            goto LABEL_15;
        }
        Scaleform::GFx::AS3::Value::SetBool(result, 1);
      }
      else
      {
LABEL_15:
        Scaleform::GFx::AS3::Value::SetBool(result, 0);
      }
    }
    else
    {
      v14.pStr = "Object::AS3isPrototypeOf";
      v14.Size = 24;
      Scaleform::GFx::AS3::VM::Error::Error(&v15, eWrongArgumentCountError, vm, v14, 1, 1, 0);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(vm, v9);
      pNode = v15.Message.pNode;
      --v15.Message.pNode->RefCount;
      v8 = pNode;
      if ( !pNode->RefCount )
        goto LABEL_5;
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v6);
    v7 = v15.Message.pNode;
    --v15.Message.pNode->RefCount;
    v8 = v7;
    if ( !v7->RefCount )
LABEL_5:
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}
