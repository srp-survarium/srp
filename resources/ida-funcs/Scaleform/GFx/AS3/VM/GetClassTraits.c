const Scaleform::GFx::AS3::ClassTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::GetClassTraits(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Value *v)
{
  const Scaleform::GFx::AS3::ClassTraits::Traits *result; // eax
  Scaleform::GFx::AS3::Value::V1U v3; // eax
  _DWORD *v4; // esi

  switch ( v->Flags & 0x1F )
  {
    case 1u:
      result = this->TraitsBoolean.pObject;
      break;
    case 2u:
      result = this->TraitsInt.pObject;
      break;
    case 3u:
      result = this->TraitsUint.pObject;
      break;
    case 4u:
      result = this->TraitsNumber.pObject;
      break;
    case 5u:
    case 7u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      result = this->TraitsFunction.pObject;
      break;
    case 9u:
      result = v->value.VS._1.CTr;
      break;
    case 0xAu:
      if ( !v->value.VS._1.VInt )
        goto LABEL_16;
      result = this->TraitsString.pObject;
      break;
    case 0xBu:
      result = this->TraitsNamespace.pObject;
      break;
    case 0xDu:
      result = *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(v->value.VS._1.VInt + 20);
      break;
    default:
      v3 = v->value.VS._1;
      if ( v3.VInt )
      {
        v4 = *(_DWORD **)(v3.VInt + 20);
        if ( !v4[17] )
          (*(void (__thiscall **)(_DWORD *))(*v4 + 56))(v4);
        result = *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(v4[17] + 20);
      }
      else
      {
LABEL_16:
        result = this->TraitsObject.pObject;
      }
      break;
  }
  return result;
}
