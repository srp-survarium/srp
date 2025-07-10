void __cdecl Scaleform::GFx::AS3::Instances::fl::Object::setPropertyIsEnumerableProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // bl
  Scaleform::Hash<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > > *v10; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // ebp
  unsigned int *p_RefCount; // esi
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS3::CheckResult v20; // [esp+7h] [ebp-15h] BYREF
  Scaleform::GFx::ASString str_name; // [esp+8h] [ebp-14h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::ConstIterator it; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VM::Error v23; // [esp+14h] [ebp-8h] BYREF

  if ( argc )
  {
    if ( (_this->Flags & 0x1F) - 12 <= 3 && _this->value.VS._1.VInt )
    {
      v9 = 1;
      str_name.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
      ++str_name.pNode->RefCount;
      if ( Scaleform::GFx::AS3::Value::Convert2String(argv, &v20, &str_name)->Result )
      {
        if ( argc > 1 )
          v9 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 1);
        v10 = (Scaleform::Hash<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > > *)(_this->value.VS._1.VInt + 24);
        if ( _this->value.VS._1.VInt != -24 )
        {
          pNode = str_name.pNode;
          ++str_name.pNode->RefCount;
          v12 = pNode;
          p_RefCount = &pNode->RefCount;
          v23.ID = 0;
          v23.Message.pNode = pNode;
          Scaleform::Hash<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>>::Find(
            v10,
            &it,
            (const Scaleform::GFx::AS3::Object::DynAttrsKey *)&v23);
          if ( (*p_RefCount)-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::ConstIterator::IsEnd(&it) )
          {
            Scaleform::GFx::AS3::VM::Error::Error(&v23, eWriteSealedError, vm);
            Scaleform::GFx::AS3::VM::ThrowReferenceError(vm, v15);
            v16 = v23.Message.pNode;
            --v23.Message.pNode->RefCount;
            if ( !v16->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v16);
          }
          else
          {
            it.pHash->pTable[4 * it.Index + 2].EntryCount ^= (it.pHash->pTable[4 * it.Index + 2].EntryCount ^ -!v9) & 1;
          }
        }
      }
      v17 = str_name.pNode;
      --str_name.pNode->RefCount;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eConvertNullToObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v18);
      v19 = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      v8 = v19;
      if ( !v19->RefCount )
LABEL_20:
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(vm, v6);
    v7 = v23.Message.pNode;
    --v23.Message.pNode->RefCount;
    v8 = v7;
    if ( !v7->RefCount )
      goto LABEL_20;
  }
}
