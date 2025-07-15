Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseCursorEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const Scaleform::GFx::ASString *cursor,
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *controllerIdx)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v8; // edi
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v10; // ecx
  Scaleform::GFx::AS3::Value *v12; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::StringDataPtr gname; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+14h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0;
  Scaleform::GFx::AS3::Value::Value(
    params,
    (const Scaleform::GFx::ASString *)&pVM->pMovieRoot->BuiltinsMgr.Builtins[46]);
  pObject = this->pTraits.pObject;
  params[1].Flags = 1;
  params[2].Flags = 1;
  params[2].value.VS._1.VBool = 1;
  params[1].Bonus.pWeakProxy = 0;
  params[1].value.VS._1.VBool = 0;
  params[2].Bonus.pWeakProxy = 0;
  gname.pStr = "scaleform.gfx.MouseCursorEvent";
  gname.Size = 30;
  Class = Scaleform::GFx::AS3::VM::GetClass(pObject->pVM, &gname, pObject->pVM->CurrentDomain);
  if ( Class )
  {
    Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 3u, params);
    result->pObject[1].DynAttrs.mHash.pTable = controllerIdx;
    v8 = (Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *)result->pObject;
    pNode = cursor->pNode;
    ++cursor->pNode->RefCount;
    v10 = v8->cursor.pNode;
    if ( v10->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v8->cursor.pNode = pNode;
  }
  v12 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 2; i >= 0; --i )
  {
    Flags = v12[-1].Flags;
    --v12;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v12);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v12);
    }
  }
  return result;
}
