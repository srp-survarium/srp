Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::GetInstanceTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // eax

  v2 = v->Flags & 0x1F;
  switch ( v2 )
  {
    case 1u:
      result = this->TraitsBoolean.pObject->ITraits.pObject;
      break;
    case 2u:
      result = this->TraitsInt.pObject->ITraits.pObject;
      break;
    case 3u:
      result = this->TraitsUint.pObject->ITraits.pObject;
      break;
    case 4u:
      result = this->TraitsNumber.pObject->ITraits.pObject;
      break;
    case 5u:
    case 0x10u:
      result = this->TraitsFunction.pObject->ThunkTraits.pObject;
      break;
    case 7u:
    case 0x11u:
      result = this->TraitsFunction.pObject->VTableTraits.pObject;
      break;
    case 8u:
      result = v->value.VS._1.ITr;
      break;
    case 9u:
      result = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v->value.VS._1.VInt + 100);
      if ( !result )
        goto LABEL_22;
      break;
    case 0xAu:
      if ( v->value.VS._1.VInt )
        result = this->TraitsString.pObject->ITraits.pObject;
      else
        result = this->TraitsObject.pObject->ITraits.pObject;
      break;
    case 0xBu:
      result = this->TraitsNamespace.pObject->ITraits.pObject;
      break;
    case 0xCu:
    case 0xEu:
    case 0xFu:
      if ( v2 - 12 > 3 || v->value.VS._1.VInt )
        result = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v->value.VS._1.VInt + 20);
      else
        result = this->TraitsObject.pObject->ITraits.pObject;
      break;
    case 0xDu:
      if ( v2 - 12 > 3 || v->value.VS._1.VInt )
        result = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_DWORD *)(v->value.VS._1.VInt + 20) + 100);
      else
        result = this->TraitsObject.pObject->ITraits.pObject;
      break;
    default:
LABEL_22:
      result = this->TraitsVoid.pObject;
      break;
  }
  return result;
}
