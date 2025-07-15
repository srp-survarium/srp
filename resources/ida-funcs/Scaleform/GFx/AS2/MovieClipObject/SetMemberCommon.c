void __thiscall Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        float val)
{
  Scaleform::GFx::Sprite *pObject; // esi
  const char *pData; // eax
  bool (__thiscall *GetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // edx
  __int16 ButtonEventNameMask; // ax
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *v10; // ecx
  Scaleform::GFx::ASMovieRootBase *v11; // edx
  Scaleform::GFx::AS2::Environment *v12; // eax
  float v13; // edi
  Scaleform::GFx::AS2::Environment *v15; // eax
  const Scaleform::GFx::AS2::Environment *v16; // eax
  bool v17; // al
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+24h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v19; // [esp+28h] [ebp-10h] BYREF

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    &this->pSprite,
    &result);
  pObject = result.pObject;
  if ( !result.pObject
    || (++result.pObject->RefCount,
        Scaleform::RefCountNTSImpl::Release(pObject),
        pObject->GetTopParent(pObject, 0) != pObject) )
  {
    if ( name->pNode->Size > 2 )
    {
      pData = name->pNode->pData;
      if ( *pData == 111 && pData[1] == 110 )
      {
        GetMemberRaw = this->GetMemberRaw;
        v19.T.Type = 0;
        if ( !GetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, name, &v19) )
        {
          ButtonEventNameMask = Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(psc, name);
          if ( ButtonEventNameMask )
            this->ButtonEventMask |= ButtonEventNameMask;
        }
        if ( v19.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v19);
      }
    }
  }
  if ( pObject )
  {
    pNode = name->pNode;
    if ( (name->pNode->HashFlags & 0x80000000) != 0 )
    {
      v10 = (char *)(&pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                   + pObject->AvmObjOffset);
      v11 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( pNode == (Scaleform::GFx::ASStringNode *)v11[38].pMovieImpl )
      {
        v12 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v10 + 124))(v10);
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)LODWORD(val),
          (Scaleform::GFx::ASString *)&val,
          v12,
          -1,
          0);
        v13 = val;
        Scaleform::GFx::DisplayObjectBase::SetRendererString(pObject, *(const __m128i **)LODWORD(val));
        if ( (*(_DWORD *)(LODWORD(v13) + 12))-- == 1 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)LODWORD(v13));
          Scaleform::RefCountNTSImpl::Release(pObject);
          return;
        }
      }
      else
      {
        if ( pNode == (Scaleform::GFx::ASStringNode *)v11[38].pASSupport.pObject )
        {
          v15 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v10 + 124))(v10);
          val = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)LODWORD(val), v15);
          Scaleform::GFx::DisplayObjectBase::SetRendererFloat(pObject, (Scaleform::String::DataDesc *)LODWORD(val));
          Scaleform::RefCountNTSImpl::Release(pObject);
          return;
        }
        if ( pNode == *(Scaleform::GFx::ASStringNode **)&v11[38].AVMVersion )
        {
          v16 = (const Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v10 + 124))(v10);
          v17 = Scaleform::GFx::AS2::Value::ToBool((Scaleform::GFx::AS2::Value *)LODWORD(val), (int)this, v16);
          Scaleform::GFx::DisplayObjectBase::DisableBatching(pObject, v17);
        }
      }
    }
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
}
