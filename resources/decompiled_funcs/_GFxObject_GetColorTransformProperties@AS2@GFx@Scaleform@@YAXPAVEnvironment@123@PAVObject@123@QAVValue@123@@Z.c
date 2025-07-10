void __cdecl Scaleform::GFx::AS2::GFxObject_GetColorTransformProperties(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "redMultiplier",
    params);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "greenMultiplier",
    params + 1);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "blueMultiplier",
    params + 2);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "alphaMultiplier",
    params + 3);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "redOffset",
    params + 4);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "greenOffset",
    params + 5);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "blueOffset",
    params + 6);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "alphaOffset",
    params + 7);
}
