void __thiscall Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::VM::Error *e,
        Scaleform::GFx::ASStringNode *ti)
{
  char *pManager; // edx
  Scaleform::GFx::ASStringNode *pLower; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v9; // edi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::WeakProxy *v17; // eax
  Scaleform::GFx::AS3::Value obj; // [esp+10h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::Value argv[2]; // [esp+20h] [ebp-24h] BYREF
  int v20; // [esp+40h] [ebp-4h] BYREF

  pManager = (char *)ti->pManager;
  pLower = ti->pLower;
  pStringManager = this->StringManagerRef->pStringManager;
  CurrentDomain = this->CurrentDomain;
  ti = (Scaleform::GFx::ASStringNode *)(pManager + 1);
  ti = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, pManager, strlen(pManager), 0);
  ++ti->RefCount;
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(this, NS_Public, pLower);
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         this,
         (const Scaleform::GFx::ASString *)&ti,
         InternedNamespace,
         CurrentDomain);
  v10 = ti;
  --ti->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  obj.Flags = 0;
  obj.Bonus.pWeakProxy = 0;
  ((void (__stdcall *)(Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v9->ITraits.pObject->MakeObject)(
    &obj,
    v9->ITraits.pObject);
  pNode = e->Message.pNode;
  argv[0].Flags = 10;
  argv[0].Bonus.pWeakProxy = 0;
  argv[0].value.VS._1.VInt = (int)pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    argv[0].value.VS._1.VInt = 0;
    argv[0].value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)obj.Bonus.pWeakProxy;
    argv[0].Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  argv[1].value.VS._1.VInt = e->ID;
  argv[1].Flags = 2;
  argv[1].Bonus.pWeakProxy = 0;
  (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, int, Scaleform::GFx::AS3::Value *))(*(_DWORD *)obj.value.VS._1.VInt
                                                                                             + 32))(
    obj.value.VS._1,
    2,
    argv);
  this->HandleException = 1;
  Scaleform::GFx::AS3::Value::Assign(&this->ExceptionObj, &obj);
  v12 = (Scaleform::GFx::AS3::Value *)&v20;
  for ( i = 1; i >= 0; --i )
  {
    Flags = v12[-1].Flags;
    --v12;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        pWeakProxy = v12->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        v12->Flags &= 0xFFFFFDE0;
        v12->Bonus.pWeakProxy = 0;
        v12->value.VS._1.VInt = 0;
        v12->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v12);
      }
    }
  }
  if ( (obj.Flags & 0x1F) > 9 )
  {
    if ( (obj.Flags & 0x200) != 0 )
    {
      v17 = obj.Bonus.pWeakProxy;
      --obj.Bonus.pWeakProxy->RefCount;
      if ( !v17->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&obj);
    }
  }
}
