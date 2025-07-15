Scaleform::GFx::AS2::BitmapData *__cdecl Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *linkageId)
{
  const Scaleform::GFx::ASString *v2; // ebx
  Scaleform::GFx::AS2::Environment *v3; // esi
  Scaleform::GFx::ResourceLibBase *Target; // ecx
  Scaleform::GFx::MovieImpl *PinResource; // edi
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::GFx::MovieDef *v9; // edi
  Scaleform::GFx::AS2::BitmapData *v10; // eax
  Scaleform::GFx::AS2::BitmapData *v11; // eax
  Scaleform::GFx::AS2::BitmapData *v12; // ebx
  const __m128i *pData; // [esp-4h] [ebp-10h]

  v2 = linkageId;
  v3 = penv;
  Target = (Scaleform::GFx::ResourceLibBase *)penv->Target;
  PinResource = (Scaleform::GFx::MovieImpl *)Target[2].PinResource;
  pData = (const __m128i *)linkageId->pNode->pData;
  v6 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::ResourceLibBase *))Target->__vftable[16].~Scaleform::GFx::ResourceLibBase)(Target);
  Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(
    PinResource,
    (Scaleform::Ptr<Scaleform::GFx::ImageResource> *)&penv,
    v6,
    pData);
  if ( !penv )
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      v3,
      "BitmapData::LoadBitmap: LoadMovieImageCallback failed to load image \"%s\"",
      v2->pNode->pData);
LABEL_3:
    if ( penv )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)penv);
    return 0;
  }
  v8 = v3->Target->GetResourceMovieDef(v3->Target);
  v9 = (Scaleform::GFx::MovieDef *)v8;
  if ( !v8 )
    goto LABEL_3;
  Scaleform::RefCountImpl::AddRef(v8);
  v10 = (Scaleform::GFx::AS2::BitmapData *)v3->StringContext.pContext->pHeap->Alloc(
                                             v3->StringContext.pContext->pHeap,
                                             60u,
                                             0);
  if ( v10 )
  {
    Scaleform::GFx::AS2::BitmapData::BitmapData(v10, v3);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  Scaleform::GFx::AS2::BitmapData::SetImage(v12, v3, (Scaleform::GFx::ImageResource *)penv, v9);
  Scaleform::GFx::Resource::Release(v9);
  if ( penv )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)penv);
  return v12;
}
