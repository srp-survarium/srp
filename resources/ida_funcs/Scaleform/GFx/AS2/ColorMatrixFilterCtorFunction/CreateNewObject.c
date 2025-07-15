void __thiscall Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ColorMatrixFilterObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::ColorMatrixFilterObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                         penv->StringContext.pContext->pHeap,
                                                         56,
                                                         0);
  if ( v2 )
    Scaleform::GFx::AS2::ColorMatrixFilterObject::ColorMatrixFilterObject(v2, penv);
}
