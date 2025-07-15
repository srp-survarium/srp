void __thiscall Scaleform::GFx::AS2::ArrayCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ArrayCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ArrayObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::ArrayObject *)penv->StringContext.pContext->pHeap->Alloc(
                                             penv->StringContext.pContext->pHeap,
                                             80,
                                             0);
  if ( v2 )
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v2, penv);
}
