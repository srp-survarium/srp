void __thiscall Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASStringNode *gfxVal,
        Scaleform::GFx::AS3::Value *pdestVal)
{
  Scaleform::GFx::Value::ValueType pManager; // esi
  Scaleform::GFx::ASString *v; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  wchar_t *pLower; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  const Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::AS3::Instances::Function *v10; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  unsigned int v12; // ecx
  unsigned int HashFlags; // edx
  __m128i *v_4; // [esp+4h] [ebp-20h]
  Scaleform::GFx::ASString str; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::ASString result; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+14h] [ebp-10h] BYREF

  pManager = (Scaleform::GFx::Value::ValueType)gfxVal->pManager;
  switch ( pManager & 0x8F )
  {
    case 0:
      Scaleform::GFx::AS3::Value::SetUndefined(pdestVal);
      break;
    case 1:
      Scaleform::GFx::AS3::Value::SetNull(pdestVal);
      break;
    case 2:
      Scaleform::GFx::AS3::Value::SetBool(pdestVal, (bool)gfxVal->pLower);
      break;
    case 3:
      Scaleform::GFx::AS3::Value::SetSInt32(pdestVal, (int)gfxVal->pLower);
      break;
    case 4:
      Scaleform::GFx::AS3::Value::SetUInt32(pdestVal, (unsigned int)gfxVal->pLower);
      break;
    case 5:
      Scaleform::GFx::AS3::Value::SetNumber(pdestVal, *(double *)&gfxVal->pLower);
      break;
    case 6:
      v_4 = (__m128i *)gfxVal->pLower;
      if ( (pManager & 0x40) == 0 )
      {
        v = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
              &this->BuiltinsMgr,
              (Scaleform::GFx::ASString *)&gfxVal,
              v_4);
        Scaleform::GFx::AS3::Value::operator=(pdestVal, v);
        pNode = gfxVal;
        goto LABEL_15;
      }
      Scaleform::GFx::AS3::Value::operator=(pdestVal, (Scaleform::GFx::ASStringNode *)v_4);
      break;
    case 7:
      pLower = (wchar_t *)gfxVal->pLower;
      if ( (pManager & 0x40) != 0 )
      {
        v7 = (Scaleform::GFx::ASStringNode *)*((_DWORD *)pLower - 1);
        ++v7->RefCount;
        str.pNode = v7;
        Scaleform::GFx::AS3::Value::Assign(pdestVal, &str);
        v8 = v7->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      }
      else
      {
        v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
               &this->BuiltinsMgr,
               &result,
               pLower,
               -1);
        Scaleform::GFx::AS3::Value::operator=(pdestVal, v9);
        pNode = result.pNode;
LABEL_15:
        if ( !--pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      break;
    case 8:
    case 9:
    case 0xA:
      v10 = (Scaleform::GFx::AS3::Instances::Function *)gfxVal->pLower;
      if ( v10
        && (pObject = v10->pTraits.pObject, pObject->TraitsType == Traits_Function)
        && (pObject->Flags & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Value::operator=(pdestVal, v10);
      }
      else
      {
        Scaleform::GFx::AS3::Value::Assign(pdestVal, v10);
      }
      break;
    case 0xB:
      v12 = (int)gfxVal->pLower & 0xFFFFFFFD;
      v8 = ((int)gfxVal->pLower & 2) == 0;
      HashFlags = gfxVal->HashFlags;
      other.Bonus.pWeakProxy = 0;
      *(_QWORD *)&other.value.VNumber = __PAIR64__(v12, HashFlags);
      if ( v8 )
      {
        other.Flags = 16;
        if ( v12 )
          *(_DWORD *)(v12 + 16) = (*(_DWORD *)(v12 + 16) + 1) & 0x8FBFFFFF;
      }
      else
      {
        if ( v12 )
          *(_DWORD *)(v12 + 16) = (*(_DWORD *)(v12 + 16) + 1) & 0x8FBFFFFF;
        other.Flags = 17;
      }
      Scaleform::GFx::AS3::Value::Assign(pdestVal, &other);
      Scaleform::GFx::AS3::Value::~Value(&other);
      break;
    default:
      return;
  }
}
