void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>>::DestructArray(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *v2; // esi
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
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v2->pObject = (Scaleform::GFx::ASStringNode *)((char *)pObject - 1);
        }
        else if ( pObject->RefCount-- == 1 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
        }
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
