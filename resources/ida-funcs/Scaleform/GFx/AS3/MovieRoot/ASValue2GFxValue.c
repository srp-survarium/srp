void __thiscall Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::ASStringNode *pdestVal)
{
  Scaleform::GFx::AS3::Value *v3; // ebp
  Scaleform::GFx::Value *v4; // esi
  Scaleform::GFx::Value::ValueType pManager; // eax
  int v7; // edi
  unsigned int v8; // ecx
  int v9; // edi
  int v10; // edi
  Scaleform::GFx::AS3::Value::V1U *p_mValue; // esi
  Scaleform::GFx::AS3::CheckResult *v12; // eax
  bool v13; // zf
  Scaleform::GFx::Value *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // edi
  unsigned int Length; // eax
  Scaleform::GFx::MovieImpl::WideStringStorage *v18; // eax
  Scaleform::RefCountVImpl *v19; // eax
  Scaleform::RefCountVImpl *v20; // edi
  Scaleform::GFx::AS3::Object *VObj; // ebp
  int v22; // edi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  void *v24; // eax
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+10h] [ebp-8h] BYREF
  int closureType; // [esp+14h] [ebp-4h]

  v3 = value;
  v4 = (Scaleform::GFx::Value *)pdestVal;
  pManager = (Scaleform::GFx::Value::ValueType)pdestVal->pManager;
  closureType = 0;
  if ( (pManager & 0x80u) == 0 )
  {
    v8 = value->Flags & 0x1F;
    switch ( v8 )
    {
      case 0u:
        v7 = 0;
        break;
      case 1u:
        v7 = 2;
        break;
      case 2u:
        v7 = 3;
        break;
      case 3u:
        v7 = 4;
        break;
      case 4u:
        v7 = 5;
        break;
      case 0xCu:
      case 0xDu:
      case 0xEu:
      case 0xFu:
        v7 = value->value.VS._1.VInt != 0 ? 8 : 1;
        break;
      case 0x10u:
        v9 = value->value.VS._2.VObj != 0 ? 0xA : 0;
        closureType = 0;
        v7 = v9 + 1;
        break;
      case 0x11u:
        v10 = value->value.VS._2.VObj != 0 ? 0xA : 0;
        closureType = 1;
        v7 = v10 + 1;
        break;
      default:
        v7 = 6;
        break;
    }
    if ( v8 - 12 <= 3 && !value->value.VS._1.VInt )
      v7 = 1;
  }
  else
  {
    v7 = pManager & 0xF;
  }
  if ( (pManager & 0x40) != 0 )
  {
    (*(void (__stdcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASStringNode *))(*(_DWORD *)pdestVal->pData
                                                                                          + 8))(
      pdestVal,
      pdestVal->pLower);
    v4->pObjectInterface = 0;
  }
  switch ( v7 )
  {
    case 0:
    case 1:
      v4->Type = v7;
      return;
    case 2:
      v4->Type = VT_Boolean;
      v4->mValue.BValue = v3->value.VS._1.VBool;
      return;
    case 3:
      v4->Type = VT_Int;
      p_mValue = (Scaleform::GFx::AS3::Value::V1U *)&v4->mValue;
      v12 = Scaleform::GFx::AS3::Value::Convert2Int32(v3, (Scaleform::GFx::AS3::CheckResult *)&value, p_mValue);
      goto LABEL_22;
    case 4:
      v4->Type = VT_UInt;
      p_mValue = (Scaleform::GFx::AS3::Value::V1U *)&v4->mValue;
      v12 = Scaleform::GFx::AS3::Value::Convert2UInt32(v3, &result[1], p_mValue);
LABEL_22:
      v13 = !v12->Result;
      goto LABEL_23;
    case 5:
      v4->Type = VT_Number;
      p_mValue = (Scaleform::GFx::AS3::Value::V1U *)&v4->mValue;
      Scaleform::GFx::AS3::Value::Convert2NumberInline(
        v3,
        (Scaleform::GFx::AS3::CheckResult *)&pdestVal,
        (long double *)p_mValue);
      v13 = (_BYTE)pdestVal == 0;
LABEL_23:
      if ( v13 )
      {
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(this->pAVM.pObject);
        *(double *)&p_mValue->VBool = Scaleform::GFx::NumberUtil::NaN();
      }
      return;
    case 6:
      pdestVal = this->pAVM.pObject->StringManagerRef->Builtins[0].pNode;
      ++pdestVal->RefCount;
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v3, &result[2], (Scaleform::GFx::ASString *)&pdestVal)->Result )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(this->pAVM.pObject);
      v14 = (Scaleform::GFx::Value *)pdestVal;
      v4->mValue.IValue = (int)pdestVal;
      v4->Type = VT_String|0x40;
      v4->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v4, v14);
      goto LABEL_30;
    case 7:
      pdestVal = this->pAVM.pObject->StringManagerRef->Builtins[0].pNode;
      ++pdestVal->RefCount;
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v3, &result[3], (Scaleform::GFx::ASString *)&pdestVal)->Result )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(this->pAVM.pObject);
      v16 = pdestVal;
      Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&pdestVal);
      v18 = (Scaleform::GFx::MovieImpl::WideStringStorage *)this->pMovieImpl->pHeap->Alloc(
                                                              this->pMovieImpl->pHeap,
                                                              2 * (Length + 1) + 15,
                                                              0);
      v4->Type = VT_StringW|0x40;
      if ( v18 )
      {
        Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(v18, v16);
        v20 = v19;
      }
      else
      {
        v20 = 0;
      }
      v4->mValue.IValue = (int)&v20[1].RefCount;
      v4->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v4, (void *)&v20[1].RefCount);
      if ( v20 )
        Scaleform::RefCountImpl::Release(v20);
LABEL_30:
      v15 = pdestVal;
      --pdestVal->RefCount;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      break;
    case 8:
      VObj = v3->value.VS._1.VObj;
      v22 = 8;
      if ( Scaleform::GFx::AS3::AreDisplayObjectTraits(VObj) )
      {
        v22 = 10;
      }
      else
      {
        pObject = VObj->pTraits.pObject;
        if ( pObject->TraitsType == Traits_Array && (pObject->Flags & 0x20) == 0 )
          v22 = 9;
      }
      v4->Type = v22 | 0x40;
      v4->mValue.IValue = (int)VObj;
      v4->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v4, VObj);
      break;
    case 11:
      v24 = (void *)((int)v3->value.VS._2.VObj | (closureType != 0 ? 2 : 0));
      v4->Type = VT_Closure|0x40;
      v4->mValue.IValue = (int)v24;
      v4->DataAux = v3->value.VS._1.VUInt;
      v4->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v4, v24);
      break;
    default:
      return;
  }
}
