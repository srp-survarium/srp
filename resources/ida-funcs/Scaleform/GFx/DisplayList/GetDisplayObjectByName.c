Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::DisplayList::GetDisplayObjectByName(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::ASString *name,
        bool caseSensitive)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  int v5; // ebp
  int v6; // ebx
  Scaleform::GFx::DisplayObject *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // eax
  int i; // edi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // esi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::DisplayObject *pCachedChar; // ecx
  const Scaleform::GFx::ASString *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  int v16; // edi
  Scaleform::GFx::ASString *v17; // esi
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::DisplayList *v20; // [esp+10h] [ebp-10h]
  Scaleform::GFx::ASString result; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v22; // [esp+18h] [ebp-8h] BYREF
  unsigned int Size; // [esp+1Ch] [ebp-4h]
  char v24; // [esp+28h] [ebp+8h]
  char v25; // [esp+28h] [ebp+8h]
  char v26; // [esp+28h] [ebp+8h]
  char v27; // [esp+28h] [ebp+8h]

  pNode = name->pNode;
  v5 = 0;
  v6 = 0;
  v20 = this;
  Size = 0;
  if ( !pNode->Size )
    return 0;
  if ( !caseSensitive )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    pCachedChar = this->pCachedChar;
    if ( !pCachedChar
      || (v6 = 4,
          v14 = Scaleform::GFx::DisplayObject::GetName(pCachedChar, &v22),
          v26 = 1,
          !Scaleform::GFx::ASString::Compare_CaseInsensitive_Resolved(name, v14)) )
    {
      v26 = 0;
    }
    if ( (v6 & 4) != 0 )
    {
      v15 = v22.pNode;
      --v22.pNode->RefCount;
      v6 &= ~4u;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    if ( v26 )
      return this->pCachedChar;
    Size = this->DisplayObjectArray.Data.Size;
    result.pNode = 0;
    if ( !Size )
      goto LABEL_49;
    while ( 1 )
    {
      v16 = *(int *)((char *)&this->DisplayObjectArray.Data.Data->pCharacter + v5);
      if ( !v16 || (*(_BYTE *)(v16 + 63) & 1) == 0 )
        goto LABEL_38;
      v6 |= 8u;
      v17 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)v16, &v22);
      if ( !v17->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v17->pNode);
      v18 = v17->pNode;
      this = v20;
      v27 = 1;
      if ( name->pNode->pLower != v18->pLower )
LABEL_38:
        v27 = 0;
      if ( (v6 & 8) != 0 )
      {
        v19 = v22.pNode;
        --v22.pNode->RefCount;
        v6 &= ~8u;
        if ( !v19->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      }
      if ( v27 )
        break;
      v5 += 12;
      if ( (unsigned int)++result.pNode >= Size )
      {
        this->pCachedChar = 0;
        return this->pCachedChar;
      }
    }
    pCharacter = (Scaleform::GFx::DisplayObjectBase *)v16;
    goto LABEL_46;
  }
  v8 = this->pCachedChar;
  if ( !v8 || (v6 = 1, v24 = 1, Scaleform::GFx::DisplayObject::GetName(v8, &result)->pNode != name->pNode) )
    v24 = 0;
  if ( (v6 & 1) != 0 )
  {
    v9 = result.pNode;
    --result.pNode->RefCount;
    v6 &= ~1u;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( v24 )
    return this->pCachedChar;
  v22.pNode = (Scaleform::GFx::ASStringNode *)this->DisplayObjectArray.Data.Size;
  if ( v22.pNode )
  {
    for ( i = 0; ; ++i )
    {
      pCharacter = this->DisplayObjectArray.Data.Data[i].pCharacter;
      if ( !pCharacter
        || (pCharacter->Flags & 0x100) == 0
        || (v6 |= 2u,
            v25 = 1,
            Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)pCharacter, &result)->pNode != name->pNode) )
      {
        v25 = 0;
      }
      if ( (v6 & 2) != 0 )
      {
        v12 = result.pNode;
        --result.pNode->RefCount;
        v6 &= ~2u;
        if ( !v12->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      }
      if ( v25 )
        break;
      this = v20;
      if ( ++v5 >= (unsigned int)v22.pNode )
      {
        v20->pCachedChar = 0;
        return v20->pCachedChar;
      }
    }
LABEL_46:
    if ( pCharacter )
    {
      v20->pCachedChar = (Scaleform::GFx::DisplayObject *)pCharacter;
      return v20->pCachedChar;
    }
    this = v20;
  }
LABEL_49:
  this->pCachedChar = 0;
  return this->pCachedChar;
}
