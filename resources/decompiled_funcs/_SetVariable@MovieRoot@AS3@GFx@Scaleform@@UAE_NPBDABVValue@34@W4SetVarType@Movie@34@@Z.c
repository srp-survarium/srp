char __thiscall Scaleform::GFx::AS3::MovieRoot::SetVariable(
        Scaleform::GFx::AS3::MovieRoot *this,
        char *ppathToVar,
        Scaleform::GFx::ASStringNode *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  char *v5; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // edi
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  const Scaleform::GFx::AS3::Value *v17; // eax
  char v18; // bl
  Scaleform::GFx::AS3::ASVM *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // ecx
  Scaleform::GFx::ASStringNode *v21; // eax
  const char *pData; // [esp-4h] [ebp-68h]
  Scaleform::GFx::ASString name; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::ASString path; // [esp+14h] [ebp-50h] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+18h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS3::Value putval; // [esp+1Ch] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value parentVal; // [esp+2Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v28; // [esp+3Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname prop; // [esp+4Ch] [ebp-18h] BYREF

  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s((unsigned int *)&name, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v5 = ppathToVar;
  path.pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++path.pNode->RefCount;
  pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++pNode->RefCount;
  name.pNode = pNode;
  if ( !Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(this, v5, &path, &name) )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, v5);
    v8 = name.pNode;
    v9 = StringNode;
    StringNode->RefCount += 2;
    v10 = v8->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v10 = v9->RefCount-- == 1;
    name.pNode = v9;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v11 = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, "root");
    v11->RefCount += 2;
    v12 = path.pNode;
    --path.pNode->RefCount;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    path.pNode = v11;
    v10 = v11->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  pData = path.pNode->pData;
  parentVal.Flags = 0;
  parentVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &parentVal, pData) )
  {
    pObject = this->pAVM.pObject->PublicNamespace.pObject;
    Scaleform::GFx::AS3::Value::Value(&v28, &name);
    prop.Kind = MN_QName;
    prop.Obj.pObject = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    prop.Name.Flags = 0;
    prop.Name.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&prop, v17);
    Scaleform::GFx::AS3::Value::~Value(&v28);
    putval.Flags = 0;
    putval.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, value, &putval);
    v18 = *(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, char **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)parentVal.value.VS._1.VInt + 12))(
                      parentVal.value.VS._1,
                      &ppathToVar,
                      &prop,
                      &putval);
    if ( !v18 && setType || setType == SV_Permanent )
      Scaleform::GFx::AS3::MovieRoot::AddStickyVariable(this, &path, &name, &putval, setType);
    v19 = this->pAVM.pObject;
    if ( v19->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v19);
    Scaleform::GFx::AS3::Value::~Value(&putval);
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop);
    Scaleform::GFx::AS3::Value::~Value(&parentVal);
    v20 = name.pNode;
    v10 = name.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    v21 = path.pNode;
    --path.pNode->RefCount;
    if ( !v21->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    _controlfp_s((unsigned int *)&ppathToVar, dpg.fpc, 0x30000u);
    return v18;
  }
  else
  {
    Scaleform::GFx::AS3::Value::~Value(&parentVal);
    v13 = name.pNode;
    v10 = name.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v14 = path.pNode;
    --path.pNode->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    _controlfp_s((unsigned int *)&ppathToVar, dpg.fpc, 0x30000u);
    return 0;
  }
}
