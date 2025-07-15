void __thiscall Scaleform::GFx::AS3::Classes::fl::Array::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Array *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  Scaleform::GFx::AS3::Classes::Function *Constructor; // eax
  Scaleform::GFx::AS3::Traits *v5; // edx
  unsigned int i; // ebx
  Scaleform::GFx::AS3::Traits *v7; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // edi
  Scaleform::GFx::AS3::Instances::FunctionBase *v9; // eax
  _DWORD *v10; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v11; // eax
  Scaleform::GFx::AS3::Traits *v12; // eax
  char *v13; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString prop_name; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Classes::Function *v16; // [esp+14h] [ebp-1Ch]
  Scaleform::GFx::AS3::InstanceTraits::Traits *itr; // [esp+18h] [ebp-18h]
  unsigned int v18; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value v; // [esp+20h] [ebp-10h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTableCheckType(this, obj);
  Constructor = (Scaleform::GFx::AS3::Classes::Function *)Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject);
  v5 = this->pTraits.pObject;
  v16 = Constructor;
  itr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v5[1].__vftable;
  for ( i = 0; i < 10; i += 5 )
  {
    v7 = v16->pTraits.pObject;
    pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v7[1].pNext;
    v9 = (Scaleform::GFx::AS3::Instances::FunctionBase *)v7->pVM->MHeap->Alloc(v7->pVM->MHeap, 48u, 0);
    v10 = &v9->__vftable;
    if ( v9 )
    {
      Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v9, pNext);
      v10[9] = &Scaleform::GFx::AS3::Classes::fl::Array::ti[i / 5];
      v11 = itr;
      *v10 = &Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable';
      v10[10] = v11;
      if ( v11 )
        v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
      *v10 = &Scaleform::GFx::AS3::Instances::CheckTypeTF::`vftable';
      v10[11] = this;
    }
    else
    {
      v10 = 0;
    }
    v12 = this->pTraits.pObject;
    v13 = (&off_70C504)[i];
    v.Bonus.pWeakProxy = 0;
    v.Flags = 15;
    *(_QWORD *)&v.value.VNumber = __PAIR64__(v18, (unsigned int)v10);
    prop_name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        v12->pVM->StringManagerRef->pStringManager,
                        v13,
                        strlen(v13),
                        0);
    ++prop_name.pNode->RefCount;
    Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj, &prop_name, &v, aDontEnum);
    pNode = prop_name.pNode;
    --prop_name.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}
