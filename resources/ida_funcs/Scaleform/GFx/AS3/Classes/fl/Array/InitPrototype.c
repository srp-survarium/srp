void __thiscall Scaleform::GFx::AS3::Classes::fl::Array::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Array *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  unsigned int i; // ebp
  Scaleform::GFx::AS3::Traits *v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // edi
  Scaleform::GFx::AS3::Instances::FunctionBase *v7; // eax
  _DWORD *v8; // esi
  Scaleform::GFx::AS3::Traits *v9; // eax
  char *v10; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString prop_name; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Classes::Function *Constructor; // [esp+14h] [ebp-18h]
  unsigned int v14; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::Value v; // [esp+1Ch] [ebp-10h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->InitPrototype(pObject, obj);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTableCheckType(this, obj);
  Constructor = (Scaleform::GFx::AS3::Classes::Function *)Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject);
  for ( i = 0; i < 10; i += 5 )
  {
    v5 = Constructor->pTraits.pObject;
    pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v5[1].pNext;
    v7 = (Scaleform::GFx::AS3::Instances::FunctionBase *)v5->pVM->MHeap->Alloc(v5->pVM->MHeap, 44u, 0);
    v8 = &v7->__vftable;
    if ( v7 )
    {
      Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v7, pNext);
      v8[9] = &Scaleform::GFx::AS3::Classes::fl::Array::ti[i / 5];
      *v8 = &Scaleform::GFx::AS3::Instances::CheckTypeTF::`vftable';
      v8[10] = this;
    }
    else
    {
      v8 = 0;
    }
    v9 = this->pTraits.pObject;
    v10 = (&off_874524)[i];
    v.Bonus.pWeakProxy = 0;
    v.Flags = 15;
    *(_QWORD *)&v.value.VNumber = __PAIR64__(v14, (unsigned int)v8);
    prop_name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        v9->pVM->StringManagerRef->pStringManager,
                        v10,
                        strlen(v10),
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
