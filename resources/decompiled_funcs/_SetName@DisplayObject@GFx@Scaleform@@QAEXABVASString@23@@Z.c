void __thiscall Scaleform::GFx::DisplayObject::SetName(Scaleform::GFx::DisplayObject *this, int name)
{
  const Scaleform::GFx::ASString *v2; // esi
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::CharacterHandle *v5; // eax
  Scaleform::GFx::CharacterHandle *v6; // eax
  Scaleform::GFx::CharacterHandle *v7; // ebp
  Scaleform::GFx::CharacterHandle *v8; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // ecx

  v2 = (const Scaleform::GFx::ASString *)name;
  if ( *(_DWORD *)(*(_DWORD *)name + 20) )
    this->Flags &= ~2u;
  pObject = this->pNameHandle.pObject;
  if ( pObject )
  {
    Scaleform::GFx::CharacterHandle::ChangeName(pObject, (Scaleform::String)v2, this->pParent);
  }
  else
  {
    name = 322;
    v5 = (Scaleform::GFx::CharacterHandle *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              20,
                                              &name);
    if ( v5 )
    {
      Scaleform::GFx::CharacterHandle::CharacterHandle(v5, (Scaleform::String)v2, this->pParent, this);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    v8 = this->pNameHandle.pObject;
    if ( v8 )
    {
      if ( --v8->RefCount <= 0 )
      {
        pNode = v8->OriginalName.pNode;
        v10 = pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v11 = v8->NamePath.pNode;
        v10 = v11->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v12 = v8->Name.pNode;
        v10 = v12->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
    this->pNameHandle.pObject = v7;
  }
}
