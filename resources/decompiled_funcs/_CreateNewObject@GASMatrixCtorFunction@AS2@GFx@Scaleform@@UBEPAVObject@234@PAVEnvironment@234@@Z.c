void __thiscall Scaleform::GFx::AS2::GASMatrixCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::GASMatrixCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::MatrixObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::MatrixObject *)penv->StringContext.pContext->pHeap->Alloc(
                                              penv->StringContext.pContext->pHeap,
                                              52,
                                              0);
  if ( v2 )
    Scaleform::GFx::AS2::MatrixObject::MatrixObject(v2, penv);
}
