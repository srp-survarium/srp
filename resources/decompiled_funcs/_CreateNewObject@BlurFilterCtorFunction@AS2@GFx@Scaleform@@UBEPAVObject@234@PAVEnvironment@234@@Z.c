void __thiscall Scaleform::GFx::AS2::BlurFilterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::BlurFilterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::BlurFilterObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::BlurFilterObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                  penv->StringContext.pContext->pHeap,
                                                  56,
                                                  0);
  if ( v2 )
    Scaleform::GFx::AS2::BlurFilterObject::BlurFilterObject(v2, penv);
}
