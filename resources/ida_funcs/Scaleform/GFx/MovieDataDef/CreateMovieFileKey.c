Scaleform::GFx::ResourceKey *__cdecl Scaleform::GFx::MovieDataDef::CreateMovieFileKey(
        Scaleform::GFx::ResourceKey *result,
        char *pfilename,
        __int64 modifyTime,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::Resource *pimageCreator)
{
  Scaleform::GFx::GFxMovieDataDefFileKeyData *v5; // eax
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::RefCountVImpl *v7; // esi

  v5 = (Scaleform::GFx::GFxMovieDataDefFileKeyData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       32,
                                                       0);
  if ( v5 )
  {
    Scaleform::GFx::GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(
      v5,
      pfilename,
      modifyTime,
      pfileOpener,
      pimageCreator);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  Scaleform::GFx::ResourceKey::ResourceKey(result, &GFxMovieDataDefFileKeyInterface_Instance, v7);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  return result;
}
