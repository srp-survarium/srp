void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteAttachBitmap(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::DisplayObjContainer *Target; // edi
  Scaleform::GFx::DisplayObjContainer *v4; // esi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::MovieDefImpl *ImageMovieDef; // eax
  Scaleform::GFx::MovieDefImpl *v15; // ebx
  Scaleform::GFx::Sprite *Sprite; // esi
  const Scaleform::Render::Matrix2x4<float> *v17; // eax
  const Scaleform::Render::Cxform *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v25; // [esp-14h] [ebp-148h]
  const Scaleform::Render::Matrix2x4<float> *v26; // [esp-4h] [ebp-138h]
  Scaleform::GFx::AS2::Environment *Env; // [esp+10h] [ebp-124h]
  Scaleform::GFx::AS2::Environment *v28; // [esp+10h] [ebp-124h]
  Scaleform::GFx::ASString result; // [esp+24h] [ebp-110h] BYREF
  Scaleform::GFx::ASString v30; // [esp+28h] [ebp-10Ch] BYREF
  Scaleform::GFx::ASStringManager *pManager; // [esp+2Ch] [ebp-108h]
  Scaleform::GFx::AS2::MovieRoot *pObject; // [esp+30h] [ebp-104h]
  Scaleform::GFx::CharPosInfo v33; // [esp+34h] [ebp-100h] BYREF
  Scaleform::Render::Matrix2x4<float> v34; // [esp+94h] [ebp-A0h] BYREF
  Scaleform::Render::Cxform v35; // [esp+B4h] [ebp-80h] BYREF
  Scaleform::GFx::CharPosInfo v36; // [esp+D4h] [ebp-60h] BYREF

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      v4 = (Scaleform::GFx::DisplayObjContainer *)ThisPtr[1].__vftable;
    else
      v4 = 0;
    Target = v4;
  }
  else
  {
    Target = (Scaleform::GFx::DisplayObjContainer *)fn->Env->Target;
  }
  if ( Target && fn->NArgs >= 2 && (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(Target) >= 8 )
  {
    Env = fn->Env;
    v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v6 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Value::ToObject(v5, Env);
    v7 = v6;
    v30.pNode = v6;
    if ( v6 )
    {
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
      if ( (*(int (__thiscall **)(unsigned int *))(v6->HashFlags + 8))(&v6->HashFlags) == 26 )
      {
        pManager = v7[2].pManager;
        if ( pManager )
        {
          v25 = fn->Env;
          v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          v11 = (int)Scaleform::GFx::AS2::Value::ToNumber(v10, v25);
          Scaleform::GFx::CharPosInfo::CharPosInfo(
            &v33,
            (Scaleform::GFx::ResourceId)1,
            v11 + 0x4000,
            1,
            &Scaleform::Render::Cxform::Identity,
            1,
            &Scaleform::Render::Matrix2x4<float>::Identity,
            0,
            0.0,
            0,
            0,
            Blend_None);
          if ( v33.Depth > 0x7EFFFFFDu )
          {
            Name = Scaleform::GFx::DisplayObject::GetName(Target, &v30);
            Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
              &Target->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
              "%s.attachBitmap() failed - depth (%d) must be >= 0",
              Name->pNode->pData,
              v33.Depth);
            pNode = v30.pNode;
            --v30.pNode->RefCount;
            if ( !pNode->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
          else
          {
            if ( fn->NArgs < 4 )
            {
              LOBYTE(result.pNode) = 0;
            }
            else
            {
              v28 = fn->Env;
              v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
              LOBYTE(result.pNode) = Scaleform::GFx::AS2::Value::ToBool(v12, (int)Target, v28);
            }
            pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
            pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject;
            ImageMovieDef = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                              pMovieImpl,
                              (Scaleform::GFx::ImageResource *)pManager,
                              (bool)result.pNode,
                              (char *)uri,
                              0);
            v15 = ImageMovieDef;
            if ( ImageMovieDef )
            {
              Scaleform::GFx::MovieDataDef::LoadTaskData::SetExtMovieDef(
                ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject,
                (Scaleform::GFx::MovieDef *)v7[2].pLower);
              Sprite = Scaleform::GFx::AS2::MovieRoot::CreateSprite(
                         pObject,
                         (int)v15,
                         (int)Target,
                         v15->pBindData.pObject->pDataDef.pObject,
                         v15,
                         Target,
                         (Scaleform::GFx::ResourceId)65537,
                         1);
              if ( Sprite )
              {
                Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>(&v34);
                v26 = v17;
                Scaleform::Render::Cxform::Cxform(&v35);
                Scaleform::GFx::CharPosInfo::CharPosInfo(
                  &v36,
                  (Scaleform::GFx::ResourceId)1,
                  1,
                  0,
                  v18,
                  1,
                  v26,
                  0,
                  0.0,
                  0,
                  0,
                  Blend_None);
                result.pNode = (Scaleform::GFx::ASStringNode *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
                ++result.pNode->RefCount;
                Scaleform::GFx::InteractiveObject::AddToPlayList(Sprite);
                Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(Sprite);
                Sprite->AddDisplayObject(Sprite, &v36, &result, 0, 0, 1u, 0, 0, 0);
                Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(
                  Target,
                  (Scaleform::GFx::DisplayObjectBase *)&v33,
                  Sprite,
                  &result);
                Target->SetAcceptAnimMoves(Target, 0);
                v19 = result.pNode;
                --result.pNode->RefCount;
                if ( !v19->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v19);
                if ( v36.pFilters.pObject )
                  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v36.pFilters.pObject);
                Scaleform::RefCountNTSImpl::Release(Sprite);
              }
              Scaleform::GFx::Resource::Release(v15);
              v7 = v30.pNode;
            }
          }
          if ( v33.pFilters.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v33.pFilters.pObject);
        }
        else
        {
          v8 = Scaleform::GFx::DisplayObject::GetName(Target, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            &Target->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
            "%s.attachBitmap() failed - no image set in BitmapData.",
            v8->pNode->pData);
          v9 = result.pNode;
          --result.pNode->RefCount;
          if ( !v9->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        }
LABEL_34:
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
        }
        return;
      }
    }
    v22 = Scaleform::GFx::DisplayObject::GetName(Target, &v30);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &Target->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachBitmap() failed - the argument is not a BitmapData.",
      v22->pNode->pData);
    v23 = v30.pNode;
    --v30.pNode->RefCount;
    if ( !v23->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    if ( v7 )
      goto LABEL_34;
  }
}
