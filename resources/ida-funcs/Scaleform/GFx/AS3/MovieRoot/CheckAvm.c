BOOL __usercall Scaleform::GFx::AS3::MovieRoot::CheckAvm@<eax>(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<edi>)
{
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::RefCountVImpl *v4; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::AS3::ASVM *v6; // eax
  Scaleform::GFx::AS3::ASVM *v7; // eax
  Scaleform::GFx::AS3::ASVM *v8; // edi
  Scaleform::GFx::AS3::ASVM *pObject; // ecx
  Scaleform::GFx::AS3::MovieRoot::CheckAvm::__l10::Loader l; // [esp+Ch] [ebp-4h] BYREF
  int (__thiscall **retaddr)(void *, char); // [esp+10h] [ebp+0h]

  if ( !this->pAVM.pObject )
  {
    v3 = (Scaleform::RefCountVImpl *)((int (__thiscall *)(Scaleform::GFx::StateBag *, int, int))this->pMovieImpl->GetStateAddRef)(
                                       &this->pMovieImpl->Scaleform::GFx::StateBag,
                                       3,
                                       a2);
    v4 = v3;
    if ( v3 )
    {
      Scaleform::RefCountImpl::Release(v3);
      this->NeedToCheck = v4[1].RefCount & 1;
    }
    else
    {
      this->NeedToCheck = 0;
    }
    pMovieImpl = this->pMovieImpl;
    this->State = sStep;
    retaddr = &`Scaleform::GFx::AS3::MovieRoot::CheckAvm'::`10'::Loader::`vftable';
    v6 = (Scaleform::GFx::AS3::ASVM *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))pMovieImpl->pHeap->Alloc)(
                                        pMovieImpl->pHeap,
                                        528);
    if ( v6 )
    {
      Scaleform::GFx::AS3::ASVM::ASVM(
        v6,
        this,
        &this->Scaleform::GFx::AS3::FlashUI,
        &l,
        &this->BuiltinsMgr,
        this->MemContext.pObject->ASGC.pObject);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    pObject = this->pAVM.pObject;
    if ( pObject != v8 )
    {
      if ( pObject && this->pAVM.Owner )
      {
        this->pAVM.Owner = 0;
        ((void (__thiscall *)(Scaleform::GFx::AS3::ASVM *, int))pObject->~Scaleform::GFx::AS3::ASVM)(pObject, 1);
      }
      this->pAVM.pObject = v8;
    }
    this->pAVM.Owner = v8 != 0;
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pAVM.pObject, 1u);
  }
  return this->pAVM.pObject != 0;
}
