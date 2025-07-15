void __thiscall Scaleform::GFx::Button::Button(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::ButtonDef *def,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::Scale9Grid *pScale9Grid; // eax
  float y1; // [esp+14h] [ebp-1Ch]
  float x2; // [esp+18h] [ebp-18h]
  float y2; // [esp+1Ch] [ebp-14h]
  Scaleform::Render::Rect<float> rect; // [esp+20h] [ebp-10h] BYREF

  Scaleform::GFx::InteractiveObject::InteractiveObject(this, pbindingDefImpl, pasRoot, parent, id);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::Button_vtbl *)&Scaleform::GFx::Button::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::Button::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->pDef = def;
  this->States[0].pRenNode.pObject = 0;
  this->States[0].Characters.Data.Data = 0;
  this->States[0].Characters.Data.Size = 0;
  this->States[0].Characters.Data.Policy.Capacity = 0;
  this->States[1].pRenNode.pObject = 0;
  this->States[1].Characters.Data.Data = 0;
  this->States[1].Characters.Data.Size = 0;
  this->States[1].Characters.Data.Policy.Capacity = 0;
  this->States[2].pRenNode.pObject = 0;
  this->States[2].Characters.Data.Data = 0;
  this->States[2].Characters.Data.Size = 0;
  this->States[2].Characters.Data.Policy.Capacity = 0;
  this->States[3].pRenNode.pObject = 0;
  this->States[3].Characters.Data.Data = 0;
  this->States[3].Characters.Data.Size = 0;
  this->States[3].Characters.Data.Policy.Capacity = 0;
  this->LastMouseFlags = 0;
  this->mMouseFlags = 0;
  this->MouseState = Unknown;
  pScale9Grid = def->pScale9Grid;
  if ( !pScale9Grid )
  {
    pScale9Grid = (Scaleform::GFx::Scale9Grid *)&rect;
    rect.x1 = 0.0;
    rect.y1 = 0.0;
    rect.x2 = 0.0;
    rect.y2 = 0.0;
  }
  y1 = pScale9Grid->Rect.y1;
  x2 = pScale9Grid->Rect.x2;
  y2 = pScale9Grid->Rect.y2;
  rect.x1 = pScale9Grid->Rect.x1;
  rect.y1 = y1;
  rect.x2 = x2;
  rect.y2 = y2;
  Scaleform::GFx::DisplayObjContainer::SetScale9Grid((Scaleform::GFx::DisplayObjContainer *)this, &rect);
  if ( this->pDef->Menu )
    this->Scaleform::GFx::InteractiveObject::Flags |= 0x4000u;
  else
    this->Scaleform::GFx::InteractiveObject::Flags &= ~0x4000u;
}
