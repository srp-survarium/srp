void __thiscall Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::LoadVarsObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::LoadVarsObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                penv->StringContext.pContext->pHeap,
                                                72,
                                                0);
  if ( v2 )
    Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(v2, penv);
}
