void __thiscall Scaleform::GFx::AS2::PointCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::PointCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::PointObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::PointObject *)penv->StringContext.pContext->pHeap->Alloc(
                                             penv->StringContext.pContext->pHeap,
                                             52,
                                             0);
  if ( v2 )
    Scaleform::GFx::AS2::PointObject::PointObject(v2, penv);
}
