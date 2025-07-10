void __thiscall Scaleform::GFx::AS2::NumberCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::NumberCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::NumberObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::NumberObject *)penv->StringContext.pContext->pHeap->Alloc(
                                              penv->StringContext.pContext->pHeap,
                                              72,
                                              0);
  if ( v2 )
    Scaleform::GFx::AS2::NumberObject::NumberObject(v2, penv);
}
