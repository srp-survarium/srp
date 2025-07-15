void __thiscall Scaleform::GFx::AS2::Environment::SetTargetOnConstruct(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  int v3; // eax

  *((_BYTE *)this + 194) &= ~2u;
  this->Target = ptarget;
  this->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(ptarget);
  if ( ptarget )
  {
    v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + ptarget->AvmObjOffset)
                                       + 4))(
           (char *)&ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * ptarget->AvmObjOffset);
    this->StringContext.pContext = (Scaleform::GFx::AS2::GlobalContext *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 96))(v3);
  }
  else
  {
    this->StringContext.pContext = (Scaleform::GFx::AS2::GlobalContext *)(*(int (__thiscall **)(_DWORD))(MEMORY[0] + 96))(0);
  }
}
