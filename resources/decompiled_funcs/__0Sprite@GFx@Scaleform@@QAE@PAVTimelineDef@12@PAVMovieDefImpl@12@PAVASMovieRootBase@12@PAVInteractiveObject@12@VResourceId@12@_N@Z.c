void __thiscall Scaleform::GFx::Sprite::Sprite(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::TimelineDef *pdef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::ASMovieRootBase *pr,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id,
        bool loadedSeparately)
{
  float *p_rect; // eax
  bool v9; // dl
  unsigned __int8 v10; // al
  unsigned __int8 v11; // al
  float v12; // [esp+30h] [ebp-1Ch]
  float v13; // [esp+34h] [ebp-18h]
  float v14; // [esp+38h] [ebp-14h]
  Scaleform::Render::Rect<float> rect; // [esp+3Ch] [ebp-10h] BYREF

  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(this, pdefImpl, pr, pparent, id);
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::Sprite_vtbl *)&Scaleform::GFx::Sprite::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::Sprite::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pdef )
    Scaleform::RefCountImpl::AddRef(pdef);
  this->pDef.pObject = pdef;
  this->PlayStatePriv = State_Playing;
  this->CurrentFrame = 0;
  this->pDrawingAPI.pObject = 0;
  this->pHitAreaHandle.pObject = 0;
  this->pHitAreaHolder = 0;
  this->Flags = 0;
  this->FocusEnabled.Value = 0;
  this->pASRoot = pr;
  this->MouseStatePriv = UP;
  this->pActiveSounds = 0;
  if ( (pdef->GetResourceTypeCode(pdef) & 0xFF00) == 0x8400 )
  {
    p_rect = (float *)pdef[2].Id.Id;
    if ( !p_rect )
    {
      p_rect = (float *)&rect;
      rect.x1 = 0.0;
      rect.y1 = 0.0;
      rect.x2 = 0.0;
      rect.y2 = 0.0;
    }
    v12 = p_rect[1];
    v13 = p_rect[2];
    v14 = p_rect[3];
    rect.x1 = *p_rect;
    rect.y1 = v12;
    rect.x2 = v13;
    rect.y2 = v14;
    Scaleform::GFx::DisplayObjContainer::SetScale9Grid(this, &rect);
    this->Flags |= 0x40u;
  }
  v9 = loadedSeparately;
  v10 = this->Flags & 0xDC | 1;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x400u;
  this->Flags = v10;
  if ( loadedSeparately )
    v11 = v10 | 0x10;
  else
    v11 = v10 & 0xEF;
  this->Flags = v11;
  if ( !pparent || loadedSeparately )
  {
LABEL_15:
    LOBYTE(v12) = 0;
    if ( !v9 )
      return;
    goto LABEL_16;
  }
  if ( pparent->GetResourceMovieDef(pparent) == pdefImpl )
  {
    v9 = loadedSeparately;
    goto LABEL_15;
  }
  LOBYTE(v12) = 1;
LABEL_16:
  Scaleform::GFx::DisplayObjContainer::AssignRootNode(this, 0, (int)pdef, SLODWORD(v12));
}
