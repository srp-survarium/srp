void __thiscall Scaleform::GFx::AS2::BevelFilterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::BevelFilterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::BevelFilterObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::BevelFilterObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                   penv->StringContext.pContext->pHeap,
                                                   56,
                                                   0);
  if ( v2 )
    Scaleform::GFx::AS2::BevelFilterObject::BevelFilterObject(v2, penv);
}
