void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::currentLabelsGet(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_display::Scene *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Scene> scene; // [esp+0h] [ebp-4h] BYREF

  scene.pObject = 0;
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::currentSceneGet(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&scene);
  Scaleform::GFx::AS3::Instances::fl_display::Scene::labelsGet(scene.pObject, result);
  if ( scene.pObject && ((int)scene.pObject & 1) == 0 )
  {
    RefCount = scene.pObject->RefCount;
    pObject = scene.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      scene.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
