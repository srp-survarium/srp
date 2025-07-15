void __thiscall Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Object *obj,
        Scaleform::GFx::AS3::Value *(__thiscall *__ptr64 f)(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *result, const Scaleform::GFx::AS3::Value *))
{
  Scaleform::GFx::AS3::Traits *v3; // ebx
  Scaleform::GFx::AS3::VTable *v4; // eax
  unsigned int FirstOwnSlotNum; // esi
  int v6; // ebp
  const Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  int v8; // edi
  Scaleform::GFx::ASStringNode *pObject; // esi
  int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  const Scaleform::GFx::AS3::VTable *vt; // [esp+Ch] [ebp-28h]
  int v16; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *v17; // [esp+18h] [ebp-1Ch]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [esp+1Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+24h] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS3::Traits *)this->pTraits.pObject[1].__vftable;
  v4 = Scaleform::GFx::AS3::Traits::GetVT(v3);
  FirstOwnSlotNum = v3->FirstOwnSlotNum;
  v6 = 0;
  for ( vt = v4; v6 < FirstOwnSlotNum + v3->VArray.Data.Size; FirstOwnSlotNum = v3->FirstOwnSlotNum )
  {
    if ( v6 >= 0 && v6 >= FirstOwnSlotNum )
      p_Value = &v3->VArray.Data.Data[v6 - FirstOwnSlotNum].Value;
    else
      p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(
                  (Scaleform::GFx::AS3::Slots *)v3->Parent,
                  (Scaleform::GFx::AS3::AbsoluteIndex)v6);
    v8 = *(_DWORD *)p_Value;
    if ( (*(_DWORD *)p_Value & 0x3E0) == 0x160 )
    {
      if ( v6 >= 0 && v6 >= FirstOwnSlotNum )
        pObject = v3->VArray.Data.Data[v6 - FirstOwnSlotNum].Key.pObject;
      else
        pObject = Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                    (Scaleform::GFx::AS3::Slots *)v3->Parent,
                    (Scaleform::GFx::AS3::AbsoluteIndex)v6);
      v10 = (int)&vt->VTMethods.Data.Data[(32 * v8) >> 15];
      ++pObject->RefCount;
      key.pSecond = (const Scaleform::GFx::AS3::Value *)((int (__thiscall *)(char *, Scaleform::GFx::AS3::Value *, int))f)(
                                                          (char *)this + HIDWORD(f),
                                                          &result,
                                                          v10);
      v16 = 1;
      v17 = pObject;
      ++pObject->RefCount;
      key.pFirst = (const Scaleform::GFx::AS3::Object::DynAttrsKey *)&v16;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
        &obj->DynAttrs.mHash,
        &obj->DynAttrs,
        &key);
      v11 = v17;
      --v17->RefCount;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      if ( pObject->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          pWeakProxy = result.Bonus.pWeakProxy;
          --result.Bonus.pWeakProxy->RefCount;
          if ( !pWeakProxy->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          result.Flags &= 0xFFFFFDE0;
          memset(&result.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
    }
    if ( v6 < 0 || v6 < v3->FirstOwnSlotNum + v3->VArray.Data.Size )
      ++v6;
  }
}
