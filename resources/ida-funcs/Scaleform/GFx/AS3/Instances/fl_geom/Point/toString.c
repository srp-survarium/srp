void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::toString(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::Traits *v5; // edx
  Scaleform::GFx::AS3::VM *v6; // esi
  const Scaleform::GFx::ASString *v7; // eax
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  const Scaleform::GFx::ASString *v24; // [esp-Ch] [ebp-60h]
  Scaleform::GFx::ASString v25; // [esp+8h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASString str; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::GFx::ASString v27; // [esp+10h] [ebp-44h] BYREF
  Scaleform::GFx::ASString v28; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::ASString v29; // [esp+18h] [ebp-3Ch] BYREF
  Scaleform::GFx::ASString v30; // [esp+1Ch] [ebp-38h] BYREF
  Scaleform::GFx::ASString v31; // [esp+20h] [ebp-34h] BYREF
  Scaleform::GFx::ASString v32; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::ASString v33; // [esp+28h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString v34; // [esp+2Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASString v35; // [esp+30h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Value v36; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+44h] [ebp-10h] BYREF

  v28.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                ")",
                1u,
                0);
  ++v28.pNode->RefCount;
  pObject = this->pTraits.pObject;
  value.value.VNumber = this->y;
  value.Flags = 4;
  value.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v27.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "y=", 2u, 0);
  ++v27.pNode->RefCount;
  str.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++str.pNode->RefCount;
  v5 = this->pTraits.pObject;
  v36.value.VNumber = this->x;
  v36.Flags = 4;
  v36.Bonus.pWeakProxy = 0;
  v6 = v5->pVM;
  v25.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v6->StringManagerRef->pStringManager, "(x=", 3u, 0);
  ++v25.pNode->RefCount;
  v24 = Scaleform::GFx::AS3::VM::AsString(pVM, &v35, &value);
  v7 = Scaleform::GFx::AS3::VM::AsString(v6, &v34, &v36);
  v8 = Scaleform::GFx::ASString::operator+(&v25, &v33, v7);
  v9 = Scaleform::GFx::ASString::operator+(v8, &v32, &str);
  v10 = Scaleform::GFx::ASString::operator+(v9, &v31, &v27);
  v11 = Scaleform::GFx::ASString::operator+(v10, &v30, v24);
  v12 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::ASString::operator+(v11, &v29, &v28);
  Scaleform::GFx::ASString::Append(result, v12);
  pNode = v29.pNode;
  --v29.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v14 = v30.pNode;
  --v30.pNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = v31.pNode;
  --v31.pNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = v32.pNode;
  --v32.pNode->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = v33.pNode;
  --v33.pNode->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = v25.pNode;
  --v25.pNode->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = v34.pNode;
  --v34.pNode->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( (v36.Flags & 0x1F) > 9 )
  {
    if ( (v36.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v36);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v36);
  }
  v20 = str.pNode;
  --str.pNode->RefCount;
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = v27.pNode;
  --v27.pNode->RefCount;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  v22 = v35.pNode;
  --v35.pNode->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
  }
  v23 = v28.pNode;
  --v28.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}
