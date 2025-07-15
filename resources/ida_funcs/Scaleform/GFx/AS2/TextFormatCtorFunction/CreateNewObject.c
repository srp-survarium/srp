void __thiscall Scaleform::GFx::AS2::TextFormatCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::TextFormatCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::TextFormatObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::TextFormatObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                  penv->StringContext.pContext->pHeap,
                                                  112,
                                                  0);
  if ( v2 )
    Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v2, penv);
}
