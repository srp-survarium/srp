void __thiscall Scaleform::GFx::AS2::DateCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::DateCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::DateObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::DateObject *)penv->StringContext.pContext->pHeap->Alloc(
                                            penv->StringContext.pContext->pHeap,
                                            104,
                                            0);
  if ( v2 )
    Scaleform::GFx::AS2::DateObject::DateObject(v2, penv);
}
