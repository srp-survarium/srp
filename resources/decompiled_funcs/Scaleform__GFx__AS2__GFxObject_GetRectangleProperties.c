void __usercall Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(
        Scaleform::GFx::AS2::Environment *penv@<eax>,
        Scaleform::GFx::AS2::Object *pobj@<ecx>,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v4; // edi

  p_StringContext = &penv->StringContext;
  v4 = &pobj->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    "x",
    params);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v4, p_StringContext, "y", params + 1);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v4, p_StringContext, "width", params + 2);
  Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v4, p_StringContext, "height", params + 3);
}
