void __thiscall Scaleform::GFx::AS2::AvmSprite::SetLevel(Scaleform::GFx::AS2::AvmSprite *this, int level)
{
  int v2; // ebp
  Scaleform::GFx::InteractiveObject *pDispObj; // ecx
  Scaleform::GFx::ASMovieRootBase *pASRoot; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int Size; // eax
  unsigned int v8; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // ebx
  Scaleform::Render::TreeContainer *v10; // ebx
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::GFx::InteractiveObject *v12; // edi
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *StringNode; // [esp+10h] [ebp-350h] BYREF
  Scaleform::MsgFormat::Sink r; // [esp+14h] [ebp-34Ch] BYREF
  __m128i v16[4]; // [esp+20h] [ebp-340h] BYREF
  Scaleform::MsgFormat v17; // [esp+60h] [ebp-300h] BYREF

  v2 = level;
  pDispObj = this->pDispObj;
  pASRoot = pDispObj->pASRoot;
  pMovieImpl = pASRoot->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v8 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    do
    {
      if ( Data->Level > level )
        break;
      ++v8;
      ++Data;
    }
    while ( v8 < Size );
  }
  v10 = (Scaleform::Render::TreeContainer *)pASRoot[1].__vftable;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pDispObj);
  Scaleform::Render::TreeContainer::Insert(v10, v8, RenderNode);
  this->Level = v2;
  memset(v16, 0, sizeof(v16));
  r.SinkData.pStr = (Scaleform::String *)v16;
  r.Type = tDataPtr;
  r.SinkData.DataPtr.Size = 64;
  Scaleform::MsgFormat::MsgFormat(&v17, &r);
  Scaleform::MsgFormat::Parse(&v17, "_level{0}");
  Scaleform::MsgFormat::FormatD1<int>(&v17, &level);
  Scaleform::MsgFormat::FinishFormatD(&v17);
  Scaleform::MsgFormat::~MsgFormat(&v17);
  v12 = this->pDispObj;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)this->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 v16);
  ++StringNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ASStringNode **))v12->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetProjectionMatrix3D)(
    v12,
    &StringNode);
  v13 = StringNode;
  --StringNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}
