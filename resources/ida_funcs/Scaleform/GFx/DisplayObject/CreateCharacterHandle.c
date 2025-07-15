Scaleform::GFx::CharacterHandle *__thiscall Scaleform::GFx::DisplayObject::CreateCharacterHandle(
        Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::CharacterHandle *v1; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::GFx::CharacterHandle *v4; // edi
  int v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  int v7; // eax
  Scaleform::GFx::CharacterHandle *pObject; // ebp
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::CharacterHandle *v14; // eax
  Scaleform::GFx::CharacterHandle *v15; // eax
  Scaleform::GFx::CharacterHandle *v16; // esi
  Scaleform::GFx::ASStringNode *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // ecx
  Scaleform::GFx::ASStringNode *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // ecx
  unsigned int *p_RefCount; // eax
  char v22; // [esp+10h] [ebp-8h]
  Scaleform::GFx::ASString name; // [esp+14h] [ebp-4h] BYREF

  v1 = 0;
  v22 = 0;
  if ( !this->pNameHandle.pObject )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( (this->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    {
      v4 = (Scaleform::GFx::CharacterHandle *)pMovieImpl->pHeap->Alloc(pMovieImpl->pHeap, 20u, 0);
      if ( v4 )
      {
        v22 = 1;
        v5 = (int)pMovieImpl->pASMovieRoot.pObject->GetStringManager(pMovieImpl->pASMovieRoot.pObject);
        ++*(_DWORD *)(v5 + 44);
        pNode = (Scaleform::GFx::ASStringNode *)(v5 + 32);
        v4->Name.pNode = (Scaleform::GFx::ASStringNode *)(v5 + 32);
        ++*(_DWORD *)(v5 + 44);
        v7 = *(_DWORD *)(v5 + 36) + 32;
        v4->NamePath.pNode = (Scaleform::GFx::ASStringNode *)v7;
        ++*(_DWORD *)(v7 + 12);
        v4->OriginalName.pNode = pNode;
        ++pNode->RefCount;
        v4->RefCount = 1;
        v4->pCharacter = 0;
      }
      else
      {
        pNode = name.pNode;
        v4 = 0;
      }
      pObject = this->pNameHandle.pObject;
      if ( pObject )
      {
        if ( --pObject->RefCount <= 0 )
        {
          v9 = pObject->OriginalName.pNode;
          v10 = v9->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v9);
          v11 = pObject->NamePath.pNode;
          v10 = v11->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          v12 = pObject->Name.pNode;
          v10 = v12->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
        }
      }
      this->pNameHandle.pObject = v4;
      if ( (v22 & 1) != 0 )
      {
        v10 = pNode->RefCount-- == 1;
        if ( v10 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          return this->pNameHandle.pObject;
        }
      }
    }
    else
    {
      this->CreateNewInstanceName(this, &name);
      v14 = (Scaleform::GFx::CharacterHandle *)pMovieImpl->pHeap->Alloc(pMovieImpl->pHeap, 20u, 0);
      if ( v14 )
      {
        Scaleform::GFx::CharacterHandle::CharacterHandle(v14, (Scaleform::String)&name, this->pParent, this);
        v1 = v15;
      }
      v16 = this->pNameHandle.pObject;
      if ( v16 )
      {
        if ( --v16->RefCount <= 0 )
        {
          v17 = v16->OriginalName.pNode;
          v10 = v17->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v17);
          v18 = v16->NamePath.pNode;
          v10 = v18->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
          v19 = v16->Name.pNode;
          v10 = v19->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
        }
      }
      v20 = name.pNode;
      p_RefCount = &name.pNode->RefCount;
      this->pNameHandle.pObject = v1;
      if ( !--*p_RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
  }
  return this->pNameHandle.pObject;
}
