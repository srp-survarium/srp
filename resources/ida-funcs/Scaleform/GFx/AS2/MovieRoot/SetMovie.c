void __thiscall Scaleform::GFx::AS2::MovieRoot::SetMovie(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::MovieImpl *pmovie)
{
  Scaleform::GFx::AS2::GlobalContext *v3; // eax
  Scaleform::GFx::AS2::GlobalContext *v4; // esi
  Scaleform::GFx::AS2::GlobalContext *pObject; // ecx

  this->pMovieImpl = pmovie;
  v3 = (Scaleform::GFx::AS2::GlobalContext *)pmovie->pHeap->Alloc(pmovie->pHeap, 60, 0);
  v4 = v3;
  if ( v3 )
  {
    v3->RefCount = 1;
    v3->__vftable = (Scaleform::GFx::AS2::GlobalContext_vtbl *)&Scaleform::GFx::AS2::GlobalContext::`vftable';
    v3->Prototypes.mHash.pTable = 0;
    v3->RegisteredClasses.mHash.pTable = 0;
    v3->BuiltinClassesRegistry.mHash.pTable = 0;
    v3->pGlobal.pObject = 0;
    v3->GFxExtensions.Value = 0;
    v3->StandardMemberMap.mHash.pTable = 0;
    Scaleform::GFx::AS2::GlobalContext::Init(v3, pmovie);
  }
  else
  {
    v4 = 0;
  }
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pGlobalContext.pObject = v4;
}
