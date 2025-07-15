void __thiscall Scaleform::GFx::AS3::VM::exec_newfunction(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Instances::FunctionBase *cf,
        unsigned int method_ind)
{
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pUserDataHolder; // ebx
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ebp
  Scaleform::GFx::AS3::Classes::Function **v6; // edi
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // eax
  Scaleform::GFx::AS3::Value *v8; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+10h] [ebp-10h] BYREF

  pUserDataHolder = (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)cf->pUserDataHolder;
  pObject = (Scaleform::GFx::AS3::VMAbcFile *)cf->pTraits.pObject;
  v6 = (Scaleform::GFx::AS3::Classes::Function **)this->TraitsFunction.pObject->ITraits.pObject;
  if ( !v6[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::Function **))(*v6)[1].RefCount)(v6);
  GlobalObject = Scaleform::GFx::AS3::VM::GetGlobalObject(this);
  Scaleform::GFx::AS3::Classes::Function::MakeInstance(
    v6[17],
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> *)&cf,
    pObject,
    method_ind,
    pUserDataHolder,
    GlobalObject);
  v10.Flags = 0;
  v10.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::PickUnsafe(&v10, cf);
  v8 = ++this->OpStack.pCurrent;
  if ( v8 )
  {
    *v8 = v10;
    if ( (v10.Flags & 0x1F) > 9 )
    {
      if ( (v10.Flags & 0x200) != 0 )
        ++v10.Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    }
  }
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags & 0x200) != 0 )
    {
      pWeakProxy = v10.Bonus.pWeakProxy;
      --v10.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
}
