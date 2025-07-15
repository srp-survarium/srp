void __thiscall Scaleform::GFx::AS2::ActionBuffer::ProcessDeclDict(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int startPc,
        unsigned int stopPc,
        Scaleform::GFx::AS2::ActionLogger *log)
{
  Scaleform::GFx::AS2::ActionBufferData *pObject; // eax
  unsigned __int8 *pBuffer; // eax
  int DeclDictProcessedAt; // ecx
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *p_Dictionary; // ebp
  unsigned int v11; // edi
  unsigned int v12; // ebx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  int v14; // ebp
  Scaleform::GFx::ASStringNode *v15; // ecx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // esi
  int v18; // edi
  Scaleform::GFx::ASStringNode *v19; // ecx
  const unsigned __int8 *Buffer; // [esp+8h] [ebp-8h]
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *v21; // [esp+Ch] [ebp-4h]
  unsigned int count; // [esp+18h] [ebp+8h]

  pObject = this->pBufferData.pObject;
  if ( !pObject->BufferLen || (pBuffer = pObject->pBuffer, !*pBuffer) )
    pBuffer = 0;
  DeclDictProcessedAt = this->DeclDictProcessedAt;
  Buffer = pBuffer;
  if ( DeclDictProcessedAt != startPc )
  {
    if ( DeclDictProcessedAt == -1 )
    {
      this->DeclDictProcessedAt = startPc;
      p_Dictionary = &this->Dictionary;
      count = *(unsigned __int16 *)&pBuffer[startPc + 3];
      v11 = startPc + 2;
      v21 = p_Dictionary;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &p_Dictionary->Data,
        count);
      v12 = 0;
      if ( count )
      {
        while ( 1 )
        {
          StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                         (char *)&Buffer[v11 + 3]);
          ++StringNode->RefCount;
          v14 = (int)&p_Dictionary->Data.Data[v12];
          ++StringNode->RefCount;
          v15 = *(Scaleform::GFx::ASStringNode **)v14;
          v16 = (*(_DWORD *)(*(_DWORD *)v14 + 12))-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
          *(_DWORD *)v14 = StringNode;
          v16 = StringNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
          if ( Buffer[v11 + 3] )
            break;
LABEL_18:
          ++v12;
          ++v11;
          if ( v12 >= count )
            return;
          p_Dictionary = v21;
        }
        while ( v11 < stopPc )
        {
          if ( !Buffer[++v11 + 3] )
            goto LABEL_18;
        }
        if ( log->IsVerboseActionErrors(log) )
          Scaleform::GFx::AS2::ActionLogger::LogScriptError(log, "Action buffer dict length exceeded");
        for ( ; v12 < count; ++v12 )
        {
          v17 = Scaleform::GFx::ASStringManager::CreateStringNode(
                  (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  "<invalid>");
          ++v17->RefCount;
          v18 = (int)&v21->Data.Data[v12];
          ++v17->RefCount;
          v19 = *(Scaleform::GFx::ASStringNode **)v18;
          v16 = (*(_DWORD *)(*(_DWORD *)v18 + 12))-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          *(_DWORD *)v18 = v17;
          v16 = v17->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        }
      }
    }
    else if ( log->IsVerboseActionErrors(log) )
    {
      Scaleform::GFx::AS2::ActionLogger::LogScriptError(
        log,
        "ProcessDeclDict(%d, %d) - DeclDict was already processed at %d",
        startPc,
        stopPc,
        this->DeclDictProcessedAt);
    }
  }
}
