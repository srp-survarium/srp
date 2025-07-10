void __thiscall Scaleform::GFx::AS3::VM::exec_newobject(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value::V2U v4; // edx
  Scaleform::GFx::ASStringNode *VStr; // esi
  unsigned int Flags; // ebp
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // ecx
  Scaleform::GFx::ASStringNode *v9; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::WeakProxy *v11; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *v12; // edi
  const Scaleform::GFx::AS3::Value *pSecond; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> o; // [esp+4h] [ebp-34h] BYREF
  int v15; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::ASStringNode *v16; // [esp+Ch] [ebp-2Ch]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+28h] [ebp-10h] BYREF

  Scaleform::GFx::AS3::VM::MakeObject(this, &o);
  if ( arg_count )
  {
    key.pFirst = (const Scaleform::GFx::AS3::Object::DynAttrsKey *)&v15;
    key.pSecond = &value;
    do
    {
      pCurrent = this->OpStack.pCurrent;
      value.Flags = pCurrent->Flags;
      value.Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
      value.value.VS._1.VInt = pCurrent->value.VS._1.VInt;
      v4.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
      this->OpStack.pCurrent = --pCurrent;
      value.value.VS._2 = v4;
      VStr = pCurrent->value.VS._1.VStr;
      Flags = pCurrent->Flags;
      pWeakProxy = pCurrent->Bonus.pWeakProxy;
      name.value.VS._2.VObj = pCurrent->value.VS._2.VObj;
      pV = o.pV;
      this->OpStack.pCurrent = pCurrent - 1;
      ++VStr->RefCount;
      v15 = 0;
      v16 = VStr;
      ++VStr->RefCount;
      name.Flags = Flags;
      name.Bonus.pWeakProxy = pWeakProxy;
      name.value.VS._1.VInt = (int)VStr;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
        &pV->DynAttrs.mHash,
        &pV->DynAttrs,
        &key);
      v9 = v16;
      --v16->RefCount;
      if ( !v9->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      v10 = VStr->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
        {
          v10 = pWeakProxy->RefCount-- == 1;
          if ( v10 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          memset(&name.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
        }
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v11 = value.Bonus.pWeakProxy;
          --value.Bonus.pWeakProxy->RefCount;
          if ( !v11->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
          value.Flags &= 0xFFFFFDE0;
          memset(&value.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      --arg_count;
    }
    while ( arg_count );
  }
  v12 = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *)++this->OpStack.pCurrent;
  pSecond = key.pSecond;
  name.Bonus.pWeakProxy = 0;
  name.Flags = 12;
  *(_QWORD *)&name.value.VNumber = __PAIR64__((unsigned int)key.pSecond, (unsigned int)o.pV);
  if ( v12 )
  {
    v12[2].pV = o.pV;
    v12->pV = (Scaleform::GFx::AS3::Instances::fl::Object *)12;
    v12[1].pV = 0;
    v12[3].pV = (Scaleform::GFx::AS3::Instances::fl::Object *)pSecond;
    Scaleform::GFx::AS3::Value::AddRefInternal(&name);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
}
