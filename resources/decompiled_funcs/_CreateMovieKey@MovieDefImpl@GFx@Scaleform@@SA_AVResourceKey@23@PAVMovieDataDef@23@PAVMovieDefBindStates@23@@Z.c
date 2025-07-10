Scaleform::GFx::ResourceKey *__cdecl Scaleform::GFx::MovieDefImpl::CreateMovieKey(
        Scaleform::GFx::ResourceKey *result,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::Resource *pbindStates)
{
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::RefCountVImpl *v4; // esi

  v3 = (Scaleform::RefCountVImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
  v4 = v3;
  if ( v3 )
  {
    v3->__vftable = (Scaleform::RefCountVImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v3->RefCount = 1;
    v3->__vftable = (Scaleform::RefCountVImpl_vtbl *)&Scaleform::GFx::GFxMovieDefImplKey::`vftable';
    if ( pdataDef )
      Scaleform::RefCountImpl::AddRef(pdataDef);
    v4[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)pdataDef;
    if ( pbindStates )
      Scaleform::RefCountImpl::AddRef(pbindStates);
    v4[1].RefCount = (volatile int)pbindStates;
  }
  else
  {
    v4 = 0;
  }
  Scaleform::GFx::ResourceKey::ResourceKey(result, &GFxMovieDefImplKeyInterface_Instance, v4);
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  return result;
}
