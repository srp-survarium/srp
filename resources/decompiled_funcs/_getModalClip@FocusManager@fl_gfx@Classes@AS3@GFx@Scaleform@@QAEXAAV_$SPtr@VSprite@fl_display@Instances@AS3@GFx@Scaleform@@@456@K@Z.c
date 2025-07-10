void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getModalClip(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite> *result,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::Sprite *ModalClip; // eax
  Scaleform::GFx::Sprite_vtbl **v5; // eax
  Scaleform::GFx::Sprite_vtbl *v6; // eax
  Scaleform::GFx::AS3::BuiltinTraitsType v7; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::Sprite *pObject; // ecx
  unsigned int RefCount; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
  {
    ModalClip = Scaleform::GFx::MovieImpl::GetModalClip(
                  (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
                  controllerIdx);
    if ( ModalClip )
    {
      v5 = &ModalClip->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + ModalClip->AvmObjOffset;
      if ( v5[2] )
        v6 = v5[2];
      else
        v6 = v5[1];
      if ( ((unsigned __int8)v6 & 1) != 0 )
        v6 = (Scaleform::GFx::Sprite_vtbl *)((char *)v6 - 1);
      if ( v6 && ((v7 = *((_DWORD *)v6->SetMatrix3D + 15), v7 == Traits_Sprite) || v7 == Traits_MovieClip) )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v6);
      }
      else
      {
        pObject = result->pObject;
        if ( result->pObject )
        {
          if ( ((unsigned __int8)pObject & 1) != 0 )
          {
            result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)((char *)pObject - 1);
            result->pObject = 0;
          }
          else
          {
            RefCount = pObject->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            }
            result->pObject = 0;
          }
        }
      }
    }
  }
}
