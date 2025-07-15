void __thiscall Scaleform::GFx::AS2::DropShadowFilterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::DropShadowFilterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::DropShadowFilterObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::DropShadowFilterObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                        penv->StringContext.pContext->pHeap,
                                                        56,
                                                        0);
  if ( v2 )
    Scaleform::GFx::AS2::DropShadowFilterObject::DropShadowFilterObject(v2, penv);
}
