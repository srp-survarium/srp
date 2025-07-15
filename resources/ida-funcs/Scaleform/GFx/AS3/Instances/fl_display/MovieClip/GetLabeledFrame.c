char __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetLabeledFrame(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::ASStringNode *spr,
        const Scaleform::GFx::AS3::Value *frame,
        Scaleform::GFx::AS3::Value *scene,
        unsigned int *targetFrame)
{
  const Scaleform::GFx::AS3::Value *v5; // ebx
  Scaleform::GFx::Sprite *v6; // ebp
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::GFx::AS3::Value *v10; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfoByName; // edi
  unsigned int v14; // eax
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::VM *v20; // esi
  Scaleform::GFx::ASStringNode *v21; // eax
  unsigned int v22; // eax
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfo; // edi
  const char *v24; // eax
  unsigned int v25; // eax
  const Scaleform::GFx::AS3::VM::Error *v26; // eax
  Scaleform::StringDataPtr v27; // [esp-8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v28; // [esp+10h] [ebp-8h] BYREF

  v5 = frame;
  v6 = (Scaleform::GFx::Sprite *)spr;
  VStr = frame->value.VS._1.VStr;
  ++VStr->RefCount;
  v6->GetLabeledFrame(v6, VStr->pData, targetFrame, 1);
  if ( VStr->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  v10 = scene;
  v11 = scene->Flags & 0x1F;
  if ( (v11 - 12 > 3 || scene->value.VS._1.VInt) && v11 )
  {
    pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
    spr = &pStringManager->EmptyStringNode;
    ++pStringManager->EmptyStringNode.RefCount;
    Scaleform::GFx::AS3::Value::Convert2String(
      v10,
      (Scaleform::GFx::AS3::CheckResult *)&frame,
      (Scaleform::GFx::ASString *)&spr);
    SceneInfoByName = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfoByName(
                        this,
                        (const Scaleform::GFx::ASString *)&spr);
    if ( !SceneInfoByName )
    {
      v27.pStr = spr->pData;
      if ( v27.pStr )
        v14 = strlen(v27.pStr);
      else
        v14 = 0;
      v27.Size = v14;
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eSceneNotFound, this->pTraits.pObject->pVM, v27);
      pVM = this->pTraits.pObject->pVM;
      goto LABEL_11;
    }
    if ( SceneInfoByName != Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, *targetFrame) )
    {
      v20 = this->pTraits.pObject->pVM;
      Scaleform::StringDataPtr::StringDataPtr(&v27, spr->pData);
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eFrameLabelNotFoundInScene, v20, v5, v27);
      pVM = v20;
LABEL_11:
      Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v15);
      pNode = v28.Message.pNode;
      --v28.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v18 = spr;
      goto LABEL_14;
    }
    v21 = spr;
    --spr->RefCount;
    if ( !v21->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    return 1;
  }
  v22 = v6->GetCurrentFrame(v6);
  SceneInfo = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, v22);
  if ( !SceneInfo
    || SceneInfo == Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, *targetFrame) )
  {
    return 1;
  }
  v24 = (const char *)((SceneInfo->Name.HeapTypeBits & 0xFFFFFFFC) + 8);
  v27.pStr = v24;
  if ( v24 )
    v25 = strlen(v24);
  else
    v25 = 0;
  v27.Size = v25;
  Scaleform::GFx::AS3::VM::Error::Error(&v28, eFrameLabelNotFoundInScene, this->pTraits.pObject->pVM, v5, v27);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v26);
  v18 = v28.Message.pNode;
LABEL_14:
  if ( !--v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  return 0;
}
