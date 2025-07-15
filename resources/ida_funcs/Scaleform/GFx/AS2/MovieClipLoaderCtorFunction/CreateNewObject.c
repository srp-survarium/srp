void __userpurge Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::MovieClipLoaderCtorFunction *this@<ecx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::MovieClipLoader *v3; // eax

  v3 = (Scaleform::GFx::AS2::MovieClipLoader *)penv->StringContext.pContext->pHeap->Alloc(
                                                 penv->StringContext.pContext->pHeap,
                                                 56,
                                                 0);
  if ( v3 )
    Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(v3, a2, penv);
}
