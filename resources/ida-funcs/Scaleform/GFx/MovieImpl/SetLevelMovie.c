char __thiscall Scaleform::GFx::MovieImpl::SetLevelMovie(
        Scaleform::GFx::MovieImpl *this,
        int level,
        Scaleform::GFx::DisplayObjContainer *psprite)
{
  unsigned int v4; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edx
  Scaleform::GFx::MovieImpl::LevelInfo *v6; // ecx
  Scaleform::GFx::MovieDefImpl *v7; // eax
  Scaleform::GFx::MovieDefImpl *v8; // ebx
  Scaleform::GFx::MovieDefImpl *pObject; // ecx
  Scaleform::GFx::MovieDefImpl *v10; // ecx
  Scaleform::GFx::AMP::ViewStats *v11; // ebx
  const char *v12; // eax
  Scaleform::GFx::Resource *v13; // ebx
  Scaleform::RefCountVImpl **p_pDelegate; // ebp
  Scaleform::GFx::MovieDef *v15; // eax
  double v16; // st7
  bool v17; // zf
  double v18; // st7
  Scaleform::GFx::MovieDefImpl *v19; // edi
  int v20; // ebp
  int v21; // ebx
  int v22; // eax
  Scaleform::GFx::MovieImpl_vtbl *v23; // edx
  void (__thiscall *SetViewport)(Scaleform::GFx::Movie *, const Scaleform::GFx::Viewport *); // edx
  Scaleform::GFx::InteractiveObject *v25; // ecx
  Scaleform::GFx::MovieImpl::LevelInfo li; // [esp+8h] [ebp-3Ch] BYREF
  Scaleform::GFx::Viewport desc; // [esp+10h] [ebp-34h] BYREF
  int levela; // [esp+48h] [ebp+4h]

  v4 = 0;
  if ( this->MovieLevels.Data.Size )
  {
    Data = this->MovieLevels.Data.Data;
    v6 = Data;
    while ( v6->Level < level )
    {
      ++v4;
      ++v6;
      if ( v4 >= this->MovieLevels.Data.Size )
        goto LABEL_5;
    }
    if ( Data[v4].Level == level )
      return 0;
  }
LABEL_5:
  this->Flags |= 0x100u;
  li.Level = level;
  if ( psprite )
    ++psprite->RefCount;
  li.pSprite.pObject = psprite;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->MovieLevels,
    v4,
    &li);
  psprite->OnInsertionAsLevel(psprite, level);
  if ( !level )
  {
    this->pMainMovie = psprite;
    v7 = psprite->GetResourceMovieDef(psprite);
    v8 = v7;
    if ( v7 )
      Scaleform::RefCountImpl::AddRef(v7);
    pObject = this->pMainMovieDef.pObject;
    if ( pObject )
      Scaleform::GFx::Resource::Release(pObject);
    v10 = v8;
    this->pMainMovieDef.pObject = v8;
    if ( v8 )
    {
      v11 = this->AdvanceStats.pObject;
      if ( v11 )
      {
        v12 = v10->GetFileURL(v10);
        Scaleform::GFx::AMP::ViewStats::SetName(v11, v12);
      }
    }
    v13 = (Scaleform::GFx::Resource *)this->pMainMovieDef.pObject->pStateBag.pObject;
    p_pDelegate = (Scaleform::RefCountVImpl **)&this->pStateBag.pObject->pDelegate;
    if ( v13 )
      Scaleform::RefCountImpl::AddRef(v13);
    if ( *p_pDelegate )
      Scaleform::RefCountImpl::Release(*p_pDelegate);
    *p_pDelegate = (Scaleform::RefCountVImpl *)v13;
    v15 = this->GetMovieDef(this);
    v16 = ((double (__thiscall *)(Scaleform::GFx::MovieDef *))v15->GetFrameRate)(v15);
    v17 = (this->Flags & 1) == 0;
    v18 = 1.0 / v16;
    this->FrameTime = v18;
    if ( v17 )
    {
      v19 = psprite->GetResourceMovieDef(psprite);
      v19->GetHeight(v19);
      v20 = (int)v18;
      v19->GetWidth(v19);
      v21 = (int)v18;
      v19->GetHeight(v19);
      levela = (int)v18;
      v22 = (int)v19->GetWidth(v19);
      desc.AspectRatio = 1.0;
      v23 = this->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
      desc.Scale = 1.0;
      SetViewport = v23->SetViewport;
      desc.BufferWidth = v22;
      desc.Left = 0;
      desc.Top = 0;
      memset(&desc.ScissorLeft, 0, 20);
      desc.BufferHeight = levela;
      desc.Width = v21;
      desc.Height = v20;
      SetViewport(this, &desc);
    }
  }
  v25 = li.pSprite.pObject;
  this->Flags |= 0x80u;
  if ( v25 )
    Scaleform::RefCountNTSImpl::Release(v25);
  return 1;
}
