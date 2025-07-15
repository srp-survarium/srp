void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::urlGet(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 result->pNode->pManager,
                 (char *)((this->SoundURL.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(this->SoundURL.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++StringNode->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
}
