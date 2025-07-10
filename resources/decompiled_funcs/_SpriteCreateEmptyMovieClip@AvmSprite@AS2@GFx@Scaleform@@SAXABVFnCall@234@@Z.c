void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteCreateEmptyMovieClip(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  int v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  int v7; // eax
  Scaleform::GFx::InteractiveObject *v8; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Environment *pos_56; // [esp+38h] [ebp-98h]
  Scaleform::GFx::AS2::Environment *pos_84; // [esp+54h] [ebp-7Ch]
  Scaleform::GFx::ASString result; // [esp+6Ch] [ebp-64h] BYREF
  Scaleform::GFx::CharPosInfo v13; // [esp+70h] [ebp-60h] BYREF

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target && fn->NArgs >= 2 )
  {
    pos_56 = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, pos_56);
    Scaleform::GFx::CharPosInfo::CharPosInfo(
      &v13,
      (Scaleform::GFx::ResourceId)65537,
      v5 + 0x4000,
      1,
      &Scaleform::Render::Cxform::Identity,
      1,
      &Scaleform::Render::Matrix2x4<float>::Identity,
      0,
      0.0,
      0,
      0,
      Blend_None);
    if ( v13.Depth <= 0x7EFFFFFDu )
    {
      pos_84 = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v6, &result, pos_84, -1, 0);
      v7 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASString *, _DWORD, _DWORD, int, int, _DWORD, _DWORD))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
             Target,
             &v13,
             &result,
             0,
             0,
             -1,
             1,
             0,
             0);
      v8 = (Scaleform::GFx::InteractiveObject *)v7;
      if ( v7 )
        ++*(_DWORD *)(v7 + 4);
      pNode = result.pNode;
      --result.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v8 )
      {
        v8->SetAcceptAnimMoves(v8, 0);
        Scaleform::GFx::AS2::Value::SetAsCharacter(
          fn->Result,
          LOBYTE(v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v8 : 0);
        Scaleform::RefCountNTSImpl::Release(v8);
      }
    }
    if ( v13.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v13.pFilters.pObject);
  }
}
