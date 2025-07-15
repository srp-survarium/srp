void __thiscall Scaleform::GFx::AS2::BitmapData::SetImage(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ImageResource *pimg,
        Scaleform::GFx::MovieDef *pmovieDef)
{
  Scaleform::GFx::ImageResource *v4; // esi
  Scaleform::GFx::ImageResource *pObject; // ecx
  Scaleform::GFx::MovieDef *v7; // edi
  Scaleform::GFx::MovieDef *v8; // ecx
  Scaleform::GFx::AS2::RectangleObject *v9; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v11; // ebx
  const Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *v15; // esi
  int i; // edi
  Scaleform::GFx::AS2::Value v; // [esp+14h] [ebp-60h] BYREF
  Scaleform::Render::Rect<unsigned long> dims; // [esp+24h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value params[4]; // [esp+34h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+74h] [ebp+0h] BYREF

  v4 = pimg;
  if ( pimg )
    Scaleform::RefCountImpl::AddRef(pimg);
  pObject = this->pImageRes.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v7 = pmovieDef;
  this->pImageRes.pObject = v4;
  if ( v7 )
    Scaleform::RefCountImpl::AddRef(v7);
  v8 = this->pMovieDef.pObject;
  if ( v8 )
    Scaleform::GFx::Resource::Release(v8);
  this->pMovieDef.pObject = v7;
  v4->pImage->GetRect(v4->pImage, &dims);
  params[0].T.Type = 0;
  params[1].T.Type = 0;
  params[2].T.Type = 0;
  params[3].T.Type = 0;
  v.T.Type = 4;
  v.NV.Int32Value = 0;
  Scaleform::GFx::AS2::Value::operator=(params, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 4;
  v.NV.Int32Value = 0;
  Scaleform::GFx::AS2::Value::operator=(&params[1], &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  pimg = (Scaleform::GFx::ImageResource *)(dims.x2 - dims.x1);
  v.NV.NumberValue = (double)(dims.x2 - dims.x1);
  Scaleform::GFx::AS2::Value::operator=(&params[2], &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  pimg = (Scaleform::GFx::ImageResource *)(dims.y2 - dims.y1);
  v.NV.NumberValue = (double)(dims.y2 - dims.y1);
  Scaleform::GFx::AS2::Value::operator=(&params[3], &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v9 = (Scaleform::GFx::AS2::RectangleObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                 penv,
                                                 penv->StringContext.pContext->FlashGeomPackage,
                                                 (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[11].RefCount,
                                                 0,
                                                 -1);
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, &penv->StringContext, params);
  pContext = penv->StringContext.pContext;
  LOBYTE(pimg) = 4;
  pmovieDef = (Scaleform::GFx::MovieDef *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                            "rectangle",
                                            9u,
                                            0);
  ++pmovieDef->Scaleform::GFx::StateBag::__vftable;
  v11 = this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  Scaleform::GFx::AS2::Value::Value(&v, v9);
  v11->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&pmovieDef,
    v12,
    (const Scaleform::GFx::AS2::PropFlags *)&pimg);
  v13 = (Scaleform::GFx::ASStringNode *)pmovieDef;
  --pmovieDef->Scaleform::GFx::StateBag::__vftable;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v9 )
  {
    RefCount = v9->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v9->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  v15 = (Scaleform::GFx::AS2::Value *)&retaddr;
  for ( i = 3; i >= 0; --i )
  {
    --v15;
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
  }
}
