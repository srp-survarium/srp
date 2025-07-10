void __cdecl Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(Scaleform::GFx::XML::ElementNode *elemNode)
{
  Scaleform::GFx::XML::ElementNode *pObject; // esi
  unsigned __int8 Type; // al
  Scaleform::GFx::XML::ElementNode *v3; // edi

  pObject = (Scaleform::GFx::XML::ElementNode *)elemNode->FirstChild.pObject;
  if ( pObject )
  {
    do
    {
      Type = pObject->Type;
      v3 = (Scaleform::GFx::XML::ElementNode *)pObject->NextSibling.pObject;
      if ( Type == 1 )
      {
        Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(pObject);
      }
      else if ( Type == 3 )
      {
        if ( Scaleform::GFx::XML::CheckWhiteSpaceNode((Scaleform::GFx::XML::TextNode *)pObject) )
          Scaleform::GFx::XML::ElementNode::RemoveChild(elemNode, pObject);
      }
      pObject = v3;
    }
    while ( v3 );
  }
}
