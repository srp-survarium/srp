void __thiscall Scaleform::GFx::AS2::TransformCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::TransformCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::TransformObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::TransformObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                 penv->StringContext.pContext->pHeap,
                                                 72,
                                                 0);
  if ( v2 )
    Scaleform::GFx::AS2::TransformObject::TransformObject(v2, penv, 0);
}
