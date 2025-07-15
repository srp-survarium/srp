void __thiscall Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASStringNode *cursorType)
{
  Scaleform::GFx::ASStringManager *v3; // eax
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASString *v6; // ebx
  Scaleform::GFx::ASStringNode *v7; // ecx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::GFx::ASStringManager *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::ASStringManager *v15; // eax
  Scaleform::GFx::ASString *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // ecx
  Scaleform::GFx::ASStringManager *v18; // eax
  Scaleform::GFx::ASString *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // ecx
  Scaleform::GFx::ASStringManager *v21; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *v23; // ecx
  Scaleform::GFx::ASString v24; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v25; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASString v26; // [esp+10h] [ebp-4h] BYREF

  switch ( (unsigned int)cursorType )
  {
    case 0u:
      v3 = this->GetStringManager(this);
      ConstString = Scaleform::GFx::ASStringManager::CreateConstString(
                      v3,
                      (Scaleform::GFx::ASString *)&cursorType,
                      "arrow");
      pNode = ConstString->pNode;
      ++ConstString->pNode->RefCount;
      v6 = result;
      v7 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      v9 = cursorType;
      goto LABEL_5;
    case 1u:
      v15 = this->GetStringManager(this);
      v16 = Scaleform::GFx::ASStringManager::CreateConstString(v15, &v25, "hand");
      pNode = v16->pNode;
      ++v16->pNode->RefCount;
      v6 = result;
      v17 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      v9 = v25.pNode;
      goto LABEL_5;
    case 2u:
      v18 = this->GetStringManager(this);
      v19 = Scaleform::GFx::ASStringManager::CreateConstString(v18, &v26, "ibeam");
      pNode = v19->pNode;
      ++v19->pNode->RefCount;
      v6 = result;
      v20 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      v9 = v26.pNode;
      goto LABEL_5;
    case 3u:
      v12 = this->GetStringManager(this);
      v13 = Scaleform::GFx::ASStringManager::CreateConstString(v12, &v24, "button");
      pNode = v13->pNode;
      ++v13->pNode->RefCount;
      v6 = result;
      v14 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v9 = v24.pNode;
LABEL_5:
      v10 = v9;
      p_RefCount = &v9->RefCount;
      v6->pNode = pNode;
      if ( !--*p_RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      break;
    default:
      v21 = this->GetStringManager(this);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v21, "auto", 4u, 0);
      ConstStringNode->RefCount += 2;
      v23 = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      result->pNode = ConstStringNode;
      v8 = ConstStringNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      break;
  }
}
