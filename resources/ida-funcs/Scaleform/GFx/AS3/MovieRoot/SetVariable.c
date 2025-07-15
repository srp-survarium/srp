char __userpurge Scaleform::GFx::AS3::MovieRoot::SetVariable@<al>(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        char a2@<bl>,
        __m128i *ppathToVar,
        Scaleform::GFx::ASStringNode *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  __m128i *v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // edi
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // edi
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  const Scaleform::GFx::AS3::Value *v18; // eax
  char v19; // bl
  Scaleform::GFx::AS3::ASVM *v20; // ecx
  Scaleform::GFx::ASStringNode *v21; // ecx
  Scaleform::GFx::ASStringNode *v22; // eax
  const char *pData; // [esp-4h] [ebp-68h]
  Scaleform::GFx::ASString name; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::ASString path; // [esp+14h] [ebp-50h] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+18h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS3::Value putval; // [esp+1Ch] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value parentVal; // [esp+2Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v29; // [esp+3Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname prop; // [esp+4Ch] [ebp-18h] BYREF

  _controlfp_s(a2, &dpg.fpc, 0, 0);
  _controlfp_s(a2, (unsigned int *)&name, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v6 = ppathToVar;
  path.pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++path.pNode->RefCount;
  pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++pNode->RefCount;
  name.pNode = pNode;
  if ( !Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(this, v6, &path, &name) )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, v6);
    v9 = name.pNode;
    v10 = StringNode;
    a2 = 2;
    StringNode->RefCount += 2;
    v11 = v9->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v11 = v10->RefCount-- == 1;
    name.pNode = v10;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v12 = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, (__m128i *)"root");
    v12->RefCount += 2;
    v13 = path.pNode;
    --path.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    path.pNode = v12;
    v11 = v12->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  pData = path.pNode->pData;
  parentVal.Flags = 0;
  parentVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &parentVal, pData) )
  {
    pObject = this->pAVM.pObject->PublicNamespace.pObject;
    Scaleform::GFx::AS3::Value::Value(&v29, &name);
    prop.Kind = MN_QName;
    prop.Obj.pObject = &pObject->Scaleform::GFx::AS3::GASRefCountBase;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    prop.Name.Flags = 0;
    prop.Name.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&prop, v18);
    Scaleform::GFx::AS3::Value::~Value(&v29);
    putval.Flags = 0;
    putval.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, value, &putval);
    v19 = *(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, __m128i **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)parentVal.value.VS._1.VInt + 24))(
                      parentVal.value.VS._1,
                      &ppathToVar,
                      &prop,
                      &putval);
    if ( !v19 && setType || setType == SV_Permanent )
      Scaleform::GFx::AS3::MovieRoot::AddStickyVariable(this, &path, &name, &putval, setType);
    v20 = this->pAVM.pObject;
    if ( v20->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v20);
    Scaleform::GFx::AS3::Value::~Value(&putval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop);
    Scaleform::GFx::AS3::Value::~Value(&parentVal);
    v21 = name.pNode;
    v11 = name.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    v22 = path.pNode;
    --path.pNode->RefCount;
    if ( !v22->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    _controlfp_s(v19, (unsigned int *)&ppathToVar, dpg.fpc, (unsigned int)&loc_30000);
    return v19;
  }
  else
  {
    Scaleform::GFx::AS3::Value::~Value(&parentVal);
    v14 = name.pNode;
    v11 = name.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = path.pNode;
    --path.pNode->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    _controlfp_s(a2, (unsigned int *)&ppathToVar, dpg.fpc, (unsigned int)&loc_30000);
    return 0;
  }
}
