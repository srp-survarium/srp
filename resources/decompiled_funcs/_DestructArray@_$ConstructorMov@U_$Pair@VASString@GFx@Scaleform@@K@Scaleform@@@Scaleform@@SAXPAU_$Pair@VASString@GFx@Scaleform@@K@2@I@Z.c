void __cdecl Scaleform::ConstructorMov<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>>::DestructArray(
        Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *p,
        unsigned int count)
{
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pNode = v2->First.pNode;
      if ( v2->First.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
