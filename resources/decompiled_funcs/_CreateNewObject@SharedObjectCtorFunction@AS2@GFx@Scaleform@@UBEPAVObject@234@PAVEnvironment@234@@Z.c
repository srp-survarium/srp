void __thiscall Scaleform::GFx::AS2::SharedObjectCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::SharedObjectCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::SharedObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::SharedObject *)penv->StringContext.pContext->pHeap->Alloc(
                                              penv->StringContext.pContext->pHeap,
                                              60,
                                              0);
  if ( v2 )
    Scaleform::GFx::AS2::SharedObject::SharedObject(v2, penv);
}
