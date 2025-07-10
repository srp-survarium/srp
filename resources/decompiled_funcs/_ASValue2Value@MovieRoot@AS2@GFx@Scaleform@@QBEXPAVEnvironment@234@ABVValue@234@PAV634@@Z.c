void __thiscall Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *value,
        Scaleform::GFx::Value *pdestVal)
{
  Scaleform::GFx::AS2::Value *v4; // ebx
  Scaleform::GFx::Value *v5; // esi
  Scaleform::GFx::Value::ValueType Type; // eax
  __int32 v8; // ebp
  long double v9; // st7
  Scaleform::GFx::ASStringNode *v10; // ebx
  Scaleform::GFx::ASStringNode *v12; // ebx
  unsigned int Length; // eax
  Scaleform::GFx::MovieImpl::WideStringStorage *v14; // eax
  Scaleform::RefCountVImpl *v15; // eax
  Scaleform::RefCountVImpl *v16; // ebx
  Scaleform::GFx::ASStringNode *v17; // eax
  int v18; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v19; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v20; // eax
  Scaleform::GFx::AS2::ObjectInterface *v21; // eax
  Scaleform::GFx::DisplayObject *v22; // eax
  Scaleform::GFx::CharacterHandle *pObject; // eax
  const Scaleform::GFx::AS2::Environment *v24; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v25; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v26; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v27; // [esp-4h] [ebp-1Ch]

  v4 = value;
  v5 = pdestVal;
  Type = pdestVal->Type;
  if ( (Type & 0x80u) == 0 )
  {
    switch ( value->T.Type )
    {
      case 0u:
        v8 = 0;
        break;
      case 1u:
        v8 = 1;
        break;
      case 2u:
        v8 = 2;
        break;
      case 3u:
      case 4u:
        v8 = 5;
        break;
      case 6u:
      case 8u:
        v8 = 8;
        break;
      case 7u:
        v8 = 10;
        break;
      default:
        v8 = 6;
        break;
    }
  }
  else
  {
    v8 = pdestVal->Type & 0xF;
  }
  if ( (Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pdestVal->pObjectInterface->ObjectRelease)(
      pdestVal,
      pdestVal->mValue.IValue);
    v5->pObjectInterface = 0;
  }
  switch ( v8 )
  {
    case 0:
    case 1:
      v5->Type = v8;
      break;
    case 2:
      v24 = penv;
      v5->Type = VT_Boolean;
      v5->mValue.BValue = Scaleform::GFx::AS2::Value::ToBool(v4, v24);
      break;
    case 3:
      v25 = penv;
      v5->Type = VT_Int;
      v5->mValue.IValue = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, v25);
      break;
    case 4:
      v26 = penv;
      v5->Type = VT_UInt;
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v4, v26);
      pdestVal = (Scaleform::GFx::Value *)((unsigned __int16)penv | 0xC00);
      v5->mValue.IValue = (__int64)v9;
      break;
    case 5:
      v27 = penv;
      v5->Type = VT_Number;
      v5->mValue.NValue = Scaleform::GFx::AS2::Value::ToNumber(v4, v27);
      break;
    case 6:
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&penv, penv, -1, 0);
      v10 = (Scaleform::GFx::ASStringNode *)penv;
      v5->Type = VT_String|0x40;
      v5->mValue.IValue = (int)v10;
      v5->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v5, v10);
      if ( v10->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      break;
    case 7:
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&penv, penv, -1, 0);
      v12 = (Scaleform::GFx::ASStringNode *)penv;
      Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&penv);
      v14 = (Scaleform::GFx::MovieImpl::WideStringStorage *)this->pMovieImpl->pHeap->Alloc(
                                                              this->pMovieImpl->pHeap,
                                                              2 * (Length + 1) + 15,
                                                              0);
      v5->Type = VT_StringW|0x40;
      if ( v14 )
      {
        Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(v14, v12);
        v16 = v15;
      }
      else
      {
        v16 = 0;
      }
      v5->mValue.IValue = (int)&v16[1].RefCount;
      v5->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v5, (void *)&v16[1].RefCount);
      if ( v16 )
        Scaleform::RefCountImpl::Release(v16);
      v17 = (Scaleform::GFx::ASStringNode *)penv;
      --penv->Stack.pPageEnd;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      break;
    case 8:
      v18 = 8;
      v19 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, penv);
      if ( (unsigned int)(v19->GetObjectType(v19) - 6) <= 0x26 )
      {
        v20 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(v19);
        if ( ((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))v20[4].pObject->RootIndex)(&v20[4]) == 7 )
          v18 = 9;
      }
      v5->mValue.IValue = (int)v19;
      v5->Type = v18 | 0x40;
      v5->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v5, v19);
      break;
    case 10:
      v21 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, penv);
      v22 = (Scaleform::GFx::DisplayObject *)Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v21);
      v5->Type = VT_DisplayObject|0x40;
      if ( v22->pNameHandle.pObject )
        pObject = v22->pNameHandle.pObject;
      else
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v22);
      v5->mValue.IValue = (int)pObject;
      v5->pObjectInterface = this->pMovieImpl->pObjectInterface;
      this->pMovieImpl->pObjectInterface->ObjectAddRef(this->pMovieImpl->pObjectInterface, v5, pObject);
      break;
    default:
      return;
  }
}
