void __thiscall Scaleform::GFx::XML::DOMBuilder::PrefixOwnership::PrefixOwnership(
        Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *this,
        Scaleform::Ptr<Scaleform::GFx::XML::Prefix> pprefix,
        Scaleform::Ptr<Scaleform::GFx::XML::ElementNode> pnode)
{
  Scaleform::GFx::XML::Prefix *pObject; // ecx
  Scaleform::GFx::XML::ElementNode *v5; // eax

  pObject = pprefix.pObject;
  if ( pprefix.pObject )
  {
    ++pprefix.pObject->RefCount;
    pObject = pprefix.pObject;
  }
  v5 = pnode.pObject;
  this->mPrefix.pObject = pObject;
  if ( pnode.pObject )
  {
    ++pnode.pObject->RefCount;
    v5 = pnode.pObject;
    pObject = pprefix.pObject;
  }
  this->Owner.pObject = v5;
  if ( pObject )
  {
    Scaleform::RefCountNTSImpl::Release(pObject);
    v5 = pnode.pObject;
  }
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
}
