void __thiscall Scaleform::GFx::AS2::ObjectCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *v2; // eax

  v2 = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap->Alloc(
                                        penv->StringContext.pContext->pHeap,
                                        52,
                                        0);
  if ( v2 )
    Scaleform::GFx::AS2::Object::Object(v2, penv);
}
