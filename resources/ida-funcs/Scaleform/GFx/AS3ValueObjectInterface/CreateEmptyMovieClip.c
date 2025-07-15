char __thiscall Scaleform::GFx::AS3ValueObjectInterface::CreateEmptyMovieClip(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        Scaleform::GFx::Value *pmc,
        char *instanceName,
        Scaleform::Render::TreeNode *depth)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  unsigned int Size; // ecx
  const char *v8; // ebp
  Scaleform::GFx::AS3::ASVM *v9; // esi
  bool v10; // al
  Scaleform::GFx::AS3::Value::V1U v11; // esi
  int v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  int v14; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v15; // ecx
  Scaleform::Render::TreeNode *v16; // eax
  Scaleform::GFx::AS3::Value asObj; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value undefVal; // [esp+14h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  Size = pdata->Size;
  if ( (unsigned int)(*(_DWORD *)(Size + 60) - 23) >= 6 || (*(_DWORD *)(Size + 56) & 0x20) != 0 )
    return 0;
  v8 = pdata[2].pData;
  asObj.Flags = 0;
  asObj.Bonus.pWeakProxy = 0;
  v9 = pObject->pAVM.pObject;
  v10 = Scaleform::GFx::AS3::VM::Construct(
          v9,
          "flash.display.Sprite",
          (Scaleform::GFx::ASStringNode *)v9->CurrentDomain,
          &asObj,
          0,
          0,
          0);
  if ( v9->HandleException )
    goto LABEL_10;
  if ( v10 )
    Scaleform::GFx::AS3::VM::ExecuteCode(v9, 1u);
  if ( v9->HandleException
    || (v11 = asObj.value.VS._1,
        v12 = *(_DWORD *)(asObj.value.VS._1.VInt + 20),
        (unsigned int)(*(_DWORD *)(v12 + 60) - 17) >= 0xC)
    || (*(_DWORD *)(v12 + 56) & 0x20) != 0 )
  {
LABEL_10:
    Scaleform::GFx::AS3::Value::~Value(&asObj);
    return 0;
  }
  else
  {
    undefVal.Flags = 0;
    undefVal.Bonus.pWeakProxy = 0;
    pdata = Scaleform::GFx::ASStringManager::CreateStringNode(pObject->BuiltinsMgr.pStringManager, instanceName);
    ++pdata->RefCount;
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v11.VInt,
      &undefVal,
      (const Scaleform::GFx::ASString *)&pdata);
    v13 = pdata;
    --pdata->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    if ( v8
      && (v14 = (*(int (__thiscall **)(const char *))(*(_DWORD *)&v8[4 * *((unsigned __int8 *)v8 + 65)] + 20))(&v8[4 * *((unsigned __int8 *)v8 + 65)])) != 0 )
    {
      v15 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v14 - 36);
    }
    else
    {
      v15 = 0;
    }
    v16 = depth;
    if ( (int)depth < 0 )
      v16 = v15->pDispObj[1].pRenNode.pObject;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
      v15,
      *(Scaleform::GFx::InteractiveObject **)(v11.VInt + 48),
      v16);
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asObj, (Scaleform::GFx::ASStringNode *)pmc);
    Scaleform::GFx::AS3::Value::~Value(&undefVal);
    Scaleform::GFx::AS3::Value::~Value(&asObj);
    return 1;
  }
}
