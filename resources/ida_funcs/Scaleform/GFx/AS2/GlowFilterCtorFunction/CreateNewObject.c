void __thiscall Scaleform::GFx::AS2::GlowFilterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::GlowFilterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::GlowFilterObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::GlowFilterObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                  penv->StringContext.pContext->pHeap,
                                                  56,
                                                  0);
  if ( v2 )
    Scaleform::GFx::AS2::GlowFilterObject::GlowFilterObject(v2, penv);
}
