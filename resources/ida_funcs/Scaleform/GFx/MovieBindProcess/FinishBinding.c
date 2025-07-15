void __thiscall Scaleform::GFx::MovieBindProcess::FinishBinding(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // esi
  Scaleform::GFx::TempBindData *pTempBindData; // eax
  _RTL_CRITICAL_SECTION *p_cs; // ebx
  Scaleform::GFx::Resource *pDefImpl_Unsafe; // ecx
  Scaleform::GFx::Resource *v6; // esi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v7; // eax
  Scaleform::GFx::MovieBindProcess::FinishBinding::__l5::ImagePackVisitor visitor; // [esp+8h] [ebp-Ch] BYREF

  if ( this->pImagePacker.pObject )
  {
    pObject = this->pBindData.pObject;
    visitor.pImagePacker = this->pImagePacker.pObject;
    pTempBindData = this->pTempBindData;
    p_cs = &pObject->ImportSourceLock.cs;
    visitor.__vftable = (Scaleform::GFx::MovieBindProcess::FinishBinding::__l5::ImagePackVisitor_vtbl *)&`Scaleform::GFx::MovieBindProcess::FinishBinding'::`5'::ImagePackVisitor::`vftable';
    visitor.pTempBindData = pTempBindData;
    EnterCriticalSection(&pObject->ImportSourceLock.cs);
    pDefImpl_Unsafe = pObject->pDefImpl_Unsafe;
    if ( pDefImpl_Unsafe && Scaleform::GFx::Resource::AddRef_NotZero(pDefImpl_Unsafe) )
    {
      v6 = pObject->pDefImpl_Unsafe;
      LeaveCriticalSection(p_cs);
    }
    else
    {
      LeaveCriticalSection(&pObject->ImportSourceLock.cs);
      v6 = 0;
    }
    ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::MovieBindProcess::FinishBinding::__l5::ImagePackVisitor *, int))v6->__vftable[6].GetResourceTypeCode)(
      v6,
      &visitor,
      2);
    this->pImagePacker.pObject->Finish(this->pImagePacker.pObject);
    Scaleform::GFx::Resource::Release(v6);
    v7 = this->pBindData.pObject;
    visitor.__vftable = (Scaleform::GFx::MovieBindProcess::FinishBinding::__l5::ImagePackVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    v7->ResourceBinding.Frozen = 1;
  }
  else
  {
    this->pBindData.pObject->ResourceBinding.Frozen = 1;
  }
}
