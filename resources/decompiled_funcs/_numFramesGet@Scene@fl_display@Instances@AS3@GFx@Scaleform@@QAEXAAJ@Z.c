void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Scene::numFramesGet(
        Scaleform::GFx::AS3::Instances::fl_display::Scene *this,
        int *result)
{
  const Scaleform::GFx::MovieDataDef::SceneInfo *SceneInfo; // eax

  SceneInfo = this->SceneInfo;
  if ( SceneInfo )
    *result = SceneInfo->NumFrames;
  else
    *result = this->SpriteObj.pObject->pDef.pObject->GetFrameCount(this->SpriteObj.pObject->pDef.pObject);
}
