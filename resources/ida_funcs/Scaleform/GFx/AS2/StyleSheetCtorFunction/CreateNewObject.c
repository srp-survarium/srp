void __userpurge Scaleform::GFx::AS2::StyleSheetCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::StyleSheetCtorFunction *this@<ecx>,
        int a2@<edi>,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::StyleSheetObject *v3; // eax

  v3 = (Scaleform::GFx::AS2::StyleSheetObject *)penv->StringContext.pContext->pHeap->Alloc(
                                                  penv->StringContext.pContext->pHeap,
                                                  76,
                                                  0);
  if ( v3 )
    Scaleform::GFx::AS2::StyleSheetObject::StyleSheetObject(v3, a2, penv);
}
