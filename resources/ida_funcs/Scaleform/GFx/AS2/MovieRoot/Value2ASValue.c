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
  Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const wchar_t *pStringW; // eax
  const Scaleform::GFx::ASString *v14; // eax
  int v15; // eax
  Scaleform::GFx::ASString result; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASString v17; // [esp+10h] [ebp-4h] BYREF

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
      Scaleform::GFx::AS2::Value::SetInt(pdestVal, gfxVal->mValue.UIValue);
      break;
    case 5:
      Scaleform::GFx::AS2::Value::SetNumber(pdestVal, gfxVal->mValue.NValue);
      break;
    case 6:
      if ( (Type & 0x40) == 0 )
      {
        v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                &this->BuiltinsMgr,
                &result,
                (char *)gfxVal->mValue.IValue);
        Scaleform::GFx::AS2::Value::SetString(pdestVal, v11);
        pNode = result.pNode;
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
      pStringW = gfxVal->mValue.pStringW;
      if ( (Type & 0x40) != 0 )
      {
        IValue = *((_DWORD *)pStringW - 1);
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
                &v17,
                pStringW,
                -1);
        Scaleform::GFx::AS2::Value::SetString(pdestVal, v14);
        pNode = v17.pNode;
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
