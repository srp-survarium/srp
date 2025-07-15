void __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::flush(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        Scaleform::GFx::ASString *result,
        int minDiskSpace)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  int v5; // edi
  Scaleform::RefCountVImpl *v6; // ebp
  Scaleform::RefCountVImpl *v7; // edi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v13; // zf
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-4h] [ebp-24h]
  Scaleform::StringDataPtr v17; // [esp-4h] [ebp-24h]
  Scaleform::GFx::SharedObjectVisitor *pwriter; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+18h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v5 = (int)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 8;
  v6 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 12))(v5, 32);
  if ( v6 )
  {
    v7 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 12))(v5, 9);
    pwriter = (Scaleform::GFx::SharedObjectVisitor *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::RefCountVImpl *))v6->Release)(
                                                       v6,
                                                       &this->Name,
                                                       &this->LocalPath,
                                                       v7);
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
    if ( Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl(this, pwriter) )
    {
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          pVM->StringManagerRef->pStringManager,
                          "flushed",
                          7u,
                          0);
      ConstStringNode->RefCount += 2;
      pNode = result->pNode;
      v13 = result->pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->pNode = ConstStringNode;
      v13 = ConstStringNode->RefCount-- == 1;
      if ( !v13 )
        goto LABEL_12;
      v10 = ConstStringNode;
    }
    else
    {
      v16.pStr = "Unable to flush shared object data!";
      v16.Size = 35;
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eFileWriteError, pVM, v16);
      Scaleform::GFx::AS3::VM::ThrowError(pVM, v8);
      v9 = v19.Message.pNode;
      --v19.Message.pNode->RefCount;
      v10 = v9;
      if ( v9->RefCount )
      {
LABEL_12:
        if ( pwriter )
          Scaleform::RefCountNTSImpl::Release(pwriter);
        Scaleform::RefCountImpl::Release(v6);
        return;
      }
    }
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    goto LABEL_12;
  }
  v17.pStr = "SharedObjectManager state is not installed!";
  v17.Size = 43;
  Scaleform::GFx::AS3::VM::Error::Error(&v19, eFileWriteError, pVM, v17);
  Scaleform::GFx::AS3::VM::ThrowError(pVM, v14);
  v15 = v19.Message.pNode;
  --v19.Message.pNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}
