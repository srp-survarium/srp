void __thiscall Scaleform::GFx::AS3::IMEManager::ASRootMovieCreated(
        Scaleform::GFx::AS3::IMEManager *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> spr)
{
  Scaleform::GFx::Movie *pMovie; // ecx
  Scaleform::GFx::ASIMEManager::IMEFuncHandler *pObject; // eax
  Scaleform::GFx::AS3::MovieRoot *v5; // esi
  Scaleform::GFx::AS3::VM *v6; // ebp
  Scaleform::GFx::Sprite_vtbl **v7; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::Sprite_vtbl *v9; // ecx
  Scaleform::GFx::Sprite_vtbl *v10; // eax
  char v11; // [esp+13h] [ebp-55h] BYREF
  Scaleform::GFx::ASString v; // [esp+14h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Value asFunc; // [esp+18h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::Value func; // [esp+38h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn1; // [esp+50h] [ebp-18h] BYREF

  pMovie = this->pMovie;
  pObject = this->CustomFuncLanguageBar.pObject;
  func.pObjectInterface = 0;
  func.Type = VT_Undefined;
  asFunc.Flags = 0;
  asFunc.Bonus.pWeakProxy = 0;
  v5 = (Scaleform::GFx::AS3::MovieRoot *)pMovie->pASMovieRoot.pObject;
  v6 = v5->pAVM.pObject;
  Scaleform::GFx::Movie::CreateFunction(pMovie, &func, pObject, 0);
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v5, (Scaleform::GFx::ASStringNode *)&func, &asFunc);
  v7 = &spr.pObject->__vftable + spr.pObject->AvmObjOffset;
  if ( v7 )
  {
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(v5->BuiltinsMgr.pStringManager, "SendLangBarMessage");
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&mn1, v5->pAVM.pObject->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v9 = v7[2];
    v10 = v9;
    if ( !v9 )
      v10 = v7[1];
    if ( ((unsigned __int8)v10 & 1) != 0 )
      v10 = (Scaleform::GFx::Sprite_vtbl *)((char *)v10 - 1);
    if ( v10 )
    {
      if ( !v9 )
        v9 = v7[1];
      if ( ((unsigned __int8)v9 & 1) != 0 )
        v9 = (Scaleform::GFx::Sprite_vtbl *)((char *)v9 - 1);
      if ( !*(_BYTE *)(*((int (__thiscall **)(Scaleform::GFx::Sprite_vtbl *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v9->~Scaleform::GFx::DisplayObjectBase
                       + 3))(
                        v9,
                        &v11,
                        &mn1,
                        &asFunc)
        && v6->HandleException )
      {
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v6);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn1);
  }
  if ( (asFunc.Flags & 0x1F) > 9 )
  {
    if ( (asFunc.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&asFunc);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&asFunc);
  }
  if ( (func.Type & 0x40) != 0 )
  {
    func.pObjectInterface->ObjectRelease(func.pObjectInterface, &func, (void *)func.mValue.IValue);
    func.pObjectInterface = 0;
  }
  func.Type = VT_Undefined;
  if ( spr.pObject )
    Scaleform::RefCountNTSImpl::Release(spr.pObject);
}
