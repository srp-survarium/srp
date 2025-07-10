void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pObject;
      if ( v2->pObject )
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
