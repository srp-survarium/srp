void __thiscall Scaleform::GFx::AS3::Instances::fl_display::SimpleButton::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::AS3::AvmButton *v5; // ecx
  Scaleform::GFx::DisplayObject *v6; // eax
  Scaleform::GFx::AS3::AvmButton *v7; // ecx
  Scaleform::GFx::DisplayObject *v8; // eax
  Scaleform::GFx::AS3::AvmButton *v9; // ecx
  Scaleform::GFx::DisplayObject *v10; // esi
  Scaleform::GFx::DisplayObject *v11; // eax

  if ( argc
    && Scaleform::GFx::AS3::VM::IsOfType(
         this->pTraits.pObject->pVM,
         argv,
         "flash.display.DisplayObject",
         this->pTraits.pObject->pVM->CurrentDomain) )
  {
    pObject = this->pDispObj.pObject;
    if ( pObject )
      v5 = (Scaleform::GFx::AS3::AvmButton *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + pObject->AvmObjOffset);
    else
      v5 = 0;
    Scaleform::GFx::AS3::AvmButton::SetUpStateObject(
      v5,
      *(Scaleform::GFx::DisplayObject **)(argv->value.VS._1.VInt + 48));
  }
  if ( argc >= 2
    && Scaleform::GFx::AS3::VM::IsOfType(
         this->pTraits.pObject->pVM,
         argv + 1,
         "flash.display.DisplayObject",
         this->pTraits.pObject->pVM->CurrentDomain) )
  {
    v6 = this->pDispObj.pObject;
    if ( v6 )
      v7 = (Scaleform::GFx::AS3::AvmButton *)(&v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + v6->AvmObjOffset);
    else
      v7 = 0;
    Scaleform::GFx::AS3::AvmButton::SetOverStateObject(
      v7,
      *(Scaleform::GFx::DisplayObject **)(argv[1].value.VS._1.VInt + 48));
  }
  if ( argc >= 3
    && Scaleform::GFx::AS3::VM::IsOfType(
         this->pTraits.pObject->pVM,
         argv + 2,
         "flash.display.DisplayObject",
         this->pTraits.pObject->pVM->CurrentDomain) )
  {
    v8 = this->pDispObj.pObject;
    if ( v8 )
      v9 = (Scaleform::GFx::AS3::AvmButton *)(&v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + v8->AvmObjOffset);
    else
      v9 = 0;
    Scaleform::GFx::AS3::AvmButton::SetDownStateObject(
      v9,
      *(Scaleform::GFx::DisplayObject **)(argv[2].value.VS._1.VInt + 48));
  }
  if ( argc >= 4
    && Scaleform::GFx::AS3::VM::IsOfType(
         this->pTraits.pObject->pVM,
         argv + 3,
         "flash.display.DisplayObject",
         this->pTraits.pObject->pVM->CurrentDomain) )
  {
    v10 = this->pDispObj.pObject;
    v11 = *(Scaleform::GFx::DisplayObject **)(argv[3].value.VS._1.VInt + 48);
    if ( v10 )
      Scaleform::GFx::AS3::AvmButton::SetHitStateObject(
        (Scaleform::GFx::AS3::AvmButton *)(&v10->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v10->AvmObjOffset),
        v11);
    else
      Scaleform::GFx::AS3::AvmButton::SetHitStateObject(0, v11);
  }
}
