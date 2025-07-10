void __thiscall Scaleform::GFx::AS2::XMLFileLoaderImpl::InitASXml(
        Scaleform::GFx::AS2::XMLFileLoaderImpl *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::AS2::XmlObject *pTarget)
{
  unsigned __int8 *pFileData; // ebp
  unsigned int FileLength; // esi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value v9; // [esp-10h] [ebp-20h]

  pFileData = this->pFileData;
  if ( pFileData )
  {
    FileLength = this->FileLength;
    StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager((Scaleform::GFx::AS2::GlobalContext *)penv[4].Size);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   StringManager->pStringManager,
                   (char *)pFileData,
                   FileLength);
    ++StringNode->RefCount;
    v9.T.Type = 5;
    v9.NV.Int32Value = (int)StringNode;
    ++StringNode->RefCount;
    Scaleform::GFx::AS2::XmlObject::NotifyOnData(pTarget, penv, v9);
    if ( StringNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pFileData);
    this->pFileData = 0;
  }
  else
  {
    v9.T.Type = 0;
    Scaleform::GFx::AS2::XmlObject::NotifyOnData(pTarget, penv, v9);
  }
}
