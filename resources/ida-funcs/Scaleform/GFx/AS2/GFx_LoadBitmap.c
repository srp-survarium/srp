Scaleform::GFx::AS2::BitmapData *__cdecl Scaleform::GFx::AS2::GFx_LoadBitmap<Scaleform::GFx::ASString>(
        Scaleform::GFx::ImageResource *penv,
        const Scaleform::GFx::ASString *linkageId)
{
  const Scaleform::GFx::ASString *v2; // ebx
  Scaleform::GFx::AS2::Environment *v3; // esi
  Scaleform::GFx::InteractiveObject *pLib; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::GFx::MovieDef *v9; // edi
  Scaleform::GFx::AS2::BitmapData *v10; // eax
  Scaleform::GFx::AS2::BitmapData *v11; // eax
  Scaleform::GFx::AS2::BitmapData *v12; // ebx
  char *pData; // [esp-4h] [ebp-10h]

  v2 = linkageId;
  v3 = (Scaleform::GFx::AS2::Environment *)penv;
  pLib = (Scaleform::GFx::InteractiveObject *)penv[2].pLib;
  pMovieImpl = pLib->pASRoot->pMovieImpl;
  pData = (char *)linkageId->pNode->pData;
  v6 = (Scaleform::RefCountVImpl *)pLib->GetResourceMovieDef(pLib);
  Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(
    pMovieImpl,
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
      Scaleform::GFx::Resource::Release(penv);
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
  Scaleform::GFx::AS2::BitmapData::SetImage(v12, v3, penv, v9);
  Scaleform::GFx::Resource::Release(v9);
  if ( penv )
    Scaleform::GFx::Resource::Release(penv);
  return v12;
}
