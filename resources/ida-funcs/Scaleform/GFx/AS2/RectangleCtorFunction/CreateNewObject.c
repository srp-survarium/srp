void __thiscall Scaleform::GFx::AS2::RectangleCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::RectangleCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::RectangleObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::RectangleObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                 penv->StringContext.pContext->pHeap,
                                                 52,
                                                 0);
  if ( v2 )
    Scaleform::GFx::AS2::RectangleObject::RectangleObject(v2, penv);
}
