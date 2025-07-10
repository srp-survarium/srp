void __thiscall Scaleform::GFx::AS3::MovieRoot::CreateFunction(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        Scaleform::GFx::Resource *pfc,
        void *puserData)
{
  Scaleform::GFx::AS3::Instances::FunctionBase *v5; // esi
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value asval; // [esp+8h] [ebp-10h] BYREF

  v5 = (Scaleform::GFx::AS3::Instances::FunctionBase *)this->pAVM.pObject->MHeap->Alloc(
                                                         this->pAVM.pObject->MHeap,
                                                         44,
                                                         0);
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(
      v5,
      this->pAVM.pObject->TraitsFunction.pObject->ITraits.pObject);
    v5->__vftable = (Scaleform::GFx::AS3::Instances::FunctionBase_vtbl *)&Scaleform::GFx::AS3::UserDefinedFunction::`vftable';
    v5[1].__vftable = 0;
    if ( pfc )
      Scaleform::RefCountImpl::AddRef(pfc);
    v6 = (Scaleform::RefCountVImpl *)v5[1].__vftable;
    if ( v6 )
      Scaleform::RefCountImpl::Release(v6);
    v5[1].__vftable = (Scaleform::GFx::AS3::Instances::FunctionBase_vtbl *)pfc;
    v5[1].pRCCRaw = (unsigned int)puserData;
  }
  else
  {
    v5 = 0;
  }
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::PickUnsafe(&asval, v5);
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &asval, (Scaleform::GFx::ASStringNode *)pvalue);
  if ( (asval.Flags & 0x1F) > 9 )
  {
    if ( (asval.Flags & 0x200) != 0 )
    {
      pWeakProxy = asval.Bonus.pWeakProxy;
      --asval.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
    }
  }
}
