void __thiscall Scaleform::GFx::AS2::XmlCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::XmlCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::XmlObject *v2; // eax

  v2 = (Scaleform::GFx::AS2::XmlObject *)penv->StringContext.pContext->pHeap->Alloc(
                                           penv->StringContext.pContext->pHeap,
                                           80,
                                           0);
  if ( v2 )
    Scaleform::GFx::AS2::XmlObject::XmlObject(v2, penv);
}
