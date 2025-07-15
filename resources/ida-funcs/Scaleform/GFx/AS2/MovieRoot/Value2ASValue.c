void __thiscall Scaleform::GFx::AS2::MovieRoot::Value2ASValue(
        Scaleform::GFx::AS2::MovieRoot *this,
        const Scaleform::GFx::Value *gfxVal,
        Scaleform::GFx::AS2::Value *pdestVal)
{
  Scaleform::GFx::Value::ValueType Type; // esi
  Scaleform::GFx::AS2::Value *v4; // esi
  Scaleform::GFx::AS2::Value *v5; // esi
  Scaleform::GFx::AS2::Value *v6; // esi
  bool BValue; // bl
  int IValue; // esi
  Scaleform::GFx::AS2::Value *v9; // ecx
  bool v10; // zf
  Scaleform::GFx::ASString *String; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  wchar_t *v13; // eax
  const Scaleform::GFx::ASString *v14; // eax
  int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASString result; // [esp+10h] [ebp-4h] BYREF

  Type = gfxVal->Type;
  switch ( Type & 0x8F )
  {
    case 0:
      v4 = pdestVal;
      Scaleform::GFx::AS2::Value::DropRefs(pdestVal);
      v4->T.Type = 0;
      break;
    case 1:
      v5 = pdestVal;
      Scaleform::GFx::AS2::Value::DropRefs(pdestVal);
      v5->T.Type = 1;
      break;
    case 2:
      v6 = pdestVal;
      BValue = gfxVal->mValue.BValue;
      Scaleform::GFx::AS2::Value::DropRefs(pdestVal);
      v6->V.BooleanValue = BValue;
      v6->T.Type = 2;
      break;
    case 3:
    case 4:
      Scaleform::GFx::AS2::Value::SetInt(pdestVal, gfxVal->mValue.IValue);
      break;
    case 5:
      Scaleform::GFx::AS2::Value::SetNumber(pdestVal, gfxVal->mValue.NValue);
      break;
    case 6:
      if ( (Type & 0x40) == 0 )
      {
        String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                   &this->BuiltinsMgr,
                   (Scaleform::GFx::ASString *)&v16,
                   (__m128i *)gfxVal->mValue.IValue);
        Scaleform::GFx::AS2::Value::SetString(pdestVal, String);
        pNode = v16;
        goto LABEL_11;
      }
      IValue = gfxVal->mValue.IValue;
      v9 = pdestVal;
      ++*(_DWORD *)(IValue + 12);
      gfxVal = (const Scaleform::GFx::Value *)IValue;
      Scaleform::GFx::AS2::Value::SetString(v9, (const Scaleform::GFx::ASString *)&gfxVal);
      v10 = (*(_DWORD *)(IValue + 12))-- == 1;
      if ( v10 )
        goto LABEL_9;
      break;
    case 7:
      v13 = (wchar_t *)gfxVal->mValue.IValue;
      if ( (Type & 0x40) != 0 )
      {
        IValue = *((_DWORD *)v13 - 1);
        ++*(_DWORD *)(IValue + 12);
        gfxVal = (const Scaleform::GFx::Value *)IValue;
        Scaleform::GFx::AS2::Value::SetString(pdestVal, (const Scaleform::GFx::ASString *)&gfxVal);
        v10 = (*(_DWORD *)(IValue + 12))-- == 1;
        if ( v10 )
LABEL_9:
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)IValue);
      }
      else
      {
        v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                &this->BuiltinsMgr,
                &result,
                v13,
                -1);
        Scaleform::GFx::AS2::Value::SetString(pdestVal, v14);
        pNode = result.pNode;
LABEL_11:
        if ( !--pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      break;
    case 8:
    case 9:
      v15 = gfxVal->mValue.IValue;
      if ( v15 )
        Scaleform::GFx::AS2::Value::SetAsObject(pdestVal, (Scaleform::GFx::AS2::Object *)(v15 - 16));
      else
        Scaleform::GFx::AS2::Value::SetAsObject(pdestVal, 0);
      break;
    case 0xA:
      Scaleform::GFx::AS2::Value::SetAsCharacterHandle(
        pdestVal,
        (Scaleform::GFx::CharacterHandle *)gfxVal->mValue.IValue);
      break;
    default:
      return;
  }
}
