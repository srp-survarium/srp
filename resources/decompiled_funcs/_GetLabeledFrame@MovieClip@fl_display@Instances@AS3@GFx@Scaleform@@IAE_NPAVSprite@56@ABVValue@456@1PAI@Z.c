char __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetLabeledFrame(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::ASStringNode *spr,
        const Scaleform::GFx::AS3::Value *frame,
        Scaleform::GFx::AS3::Value *scene,
        unsigned int *targetFrame)
{
  unsigned int *v5; // ebx
  Scaleform::GFx::Sprite *v6; // ebp
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::GFx::AS3::Value *v10; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfoByName; // edi
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  unsigned int v20; // eax
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfo; // edi
  Scaleform::GFx::AS3::VM *v22; // esi
  const Scaleform::GFx::AS3::VM::Error *v23; // eax
  Scaleform::GFx::AS3::VM::Error v24; // [esp+10h] [ebp-8h] BYREF

  v5 = targetFrame;
  v6 = (Scaleform::GFx::Sprite *)spr;
  VStr = frame->value.VS._1.VStr;
  ++VStr->RefCount;
  v6->GetLabeledFrame(v6, VStr->pData, v5, 1);
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
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v24, eSceneNotFound, pVM);
LABEL_8:
      Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v15);
      pNode = v24.Message.pNode;
      --v24.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v17 = spr;
      goto LABEL_11;
    }
    if ( SceneInfoByName != Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, *v5) )
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v24, eFrameLabelNotFoundInScene, pVM);
      goto LABEL_8;
    }
    v19 = spr;
    --spr->RefCount;
    if ( !v19->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    return 1;
  }
  v20 = v6->GetCurrentFrame(v6);
  SceneInfo = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, v20);
  if ( !SceneInfo || SceneInfo == Scaleform::GFx::AS3::Instances::fl_display::MovieClip::GetSceneInfo(this, *v5) )
    return 1;
  v22 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v24, eFrameLabelNotFoundInScene, v22);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v22, v23);
  v17 = v24.Message.pNode;
LABEL_11:
  if ( !--v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  return 0;
}
