void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ASString>::DestructArray(
        Scaleform::GFx::ASString *p,
        unsigned int count)
{
  Scaleform::GFx::ASString *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pNode = v2->pNode;
      if ( v2->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
