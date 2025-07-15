void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        bool extCall)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // esi
  Scaleform::GFx::AS3::MovieRoot *AS3Root; // eax

  if ( !extCall )
  {
    Scaleform::GFx::AS3::Instances::fl_display::Sprite::CreateStageObject(this);
    pObject = (Scaleform::GFx::DisplayObjContainer *)this->pDispObj.pObject;
    AS3Root = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root((Scaleform::GFx::AS3::AvmDisplayObj *)(&pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                                  + pObject->AvmObjOffset));
    Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(AS3Root, pObject);
  }
  if ( this->IsMovieClip(this) )
    this->pDispObj.pObject->Flags |= 0x800u;
}
