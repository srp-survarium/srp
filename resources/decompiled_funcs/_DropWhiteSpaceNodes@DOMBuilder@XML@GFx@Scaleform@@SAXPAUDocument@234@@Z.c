void __cdecl Scaleform::GFx::XML::DOMBuilder::DropWhiteSpaceNodes(Scaleform::GFx::XML::Document *document)
{
  Scaleform::GFx::XML::ElementNode *i; // esi

  for ( i = (Scaleform::GFx::XML::ElementNode *)document->FirstChild.pObject;
        i;
        i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
  {
    if ( i->Type == 1 )
      Scaleform::GFx::XML::DropWhiteSpaceNodesHelper(i);
  }
}
