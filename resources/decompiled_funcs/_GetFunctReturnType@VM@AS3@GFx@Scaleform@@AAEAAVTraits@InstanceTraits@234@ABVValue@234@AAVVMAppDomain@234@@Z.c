Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::VM::GetFunctReturnType(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value::V1U v5; // esi
  Scaleform::GFx::AS3::Abc::Multiname *ReturnType; // eax
  _DWORD *v7; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // eax
  Scaleform::GFx::AS3::Value *v9; // esi
  Scaleform::GFx::AS3::Value::V1U v10; // ebx
  Scaleform::GFx::AS3::VMFile *v11; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v12; // eax
  Scaleform::GFx::AS3::Value::V1U v13; // ebx
  Scaleform::GFx::AS3::VMFile *v14; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v15; // eax

  v3 = value->Flags & 0x1F;
  switch ( v3 )
  {
    case 5u:
    case 0x10u:
      result = Scaleform::GFx::AS3::VM::GetFunctReturnType(this, value->value.VS._1.VStr, appDomain);
      break;
    case 6u:
      v13 = value->value.VS._1;
      v14 = (Scaleform::GFx::AS3::VMFile *)((int (__thiscall *)(_DWORD))value->value.VS._2.VObj->Call)((Scaleform::GFx::AS3::Value::V2U)value->value.VS._2.VObj);
      v15 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
              this,
              v14,
              (Scaleform::GFx::AS3::Abc::Multiname *)v14[1].__vftable[2].MakeInternedNamespace
            + *(_DWORD *)(*((_DWORD *)v14[1].__vftable[3].~Scaleform::GFx::AS3::VMFile + v13.VInt) + 4));
      if ( !v15 )
        goto LABEL_3;
      result = v15->ITraits.pObject;
      break;
    case 7u:
    case 0x11u:
      v9 = &Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)value->value.VS._2.VObj)->VTMethods.Data.Data[value->value.VS._1.VInt];
      if ( (v9->Flags & 0x1F) == 6 )
      {
        v10 = v9->value.VS._1;
        v11 = (Scaleform::GFx::AS3::VMFile *)((int (__thiscall *)(_DWORD))v9->value.VS._2.VObj->Call)((Scaleform::GFx::AS3::Value::V2U)v9->value.VS._2.VObj);
        v12 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                this,
                v11,
                (Scaleform::GFx::AS3::Abc::Multiname *)v11[1].__vftable[2].MakeInternedNamespace
              + *(_DWORD *)(*((_DWORD *)v11[1].__vftable[3].~Scaleform::GFx::AS3::VMFile + v10.VInt) + 4));
        if ( !v12 )
          goto LABEL_3;
        result = v12->ITraits.pObject;
      }
      else
      {
        if ( v3 != 7 && v3 != 17 )
          goto LABEL_3;
        result = Scaleform::GFx::AS3::VM::GetFunctReturnType(this, v9->value.VS._1.VStr, appDomain);
      }
      break;
    case 0xEu:
      v5 = value->value.VS._1;
      ReturnType = (Scaleform::GFx::AS3::Abc::Multiname *)Scaleform::GFx::AS3::InstanceTraits::Function::GetReturnType(*(Scaleform::GFx::AS3::InstanceTraits::Function **)(v5.VInt + 20));
      v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
             this,
             *(Scaleform::GFx::AS3::VMFile **)(*(_DWORD *)(v5.VInt + 20) + 124),
             ReturnType);
      if ( v7 )
        goto LABEL_4;
      goto LABEL_3;
    case 0xFu:
      result = Scaleform::GFx::AS3::VM::GetFunctReturnType(
                 this,
                 *(Scaleform::GFx::ASStringNode **)(value->value.VS._1.VInt + 36),
                 appDomain);
      break;
    default:
LABEL_3:
      v7 = &this->TraitsObject.pObject->__vftable;
LABEL_4:
      result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v7[25];
      break;
  }
  return result;
}
