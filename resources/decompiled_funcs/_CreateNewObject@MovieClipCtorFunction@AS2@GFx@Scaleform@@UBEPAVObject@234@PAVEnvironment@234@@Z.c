void __thiscall Scaleform::GFx::AS2::MovieClipCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::MovieClipCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::MovieClipObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::MovieClipObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                 penv->StringContext.pContext->pHeap,
                                                 60,
                                                 0);
  if ( v2 )
    Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(v2, penv);
}
