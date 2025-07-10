void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::endianGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        Scaleform::GFx::ASString *result)
{
  char *v2; // esi
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  unsigned int RefCount; // ecx

  v2 = "bigEndian";
  if ( (*((_BYTE *)this + 48) & 0x18) != 0 )
    v2 = "littleEndian";
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      v2,
                      strlen(v2),
                      0);
  RefCount = ConstStringNode->RefCount;
  ConstStringNode->RefCount = RefCount;
  if ( !RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
