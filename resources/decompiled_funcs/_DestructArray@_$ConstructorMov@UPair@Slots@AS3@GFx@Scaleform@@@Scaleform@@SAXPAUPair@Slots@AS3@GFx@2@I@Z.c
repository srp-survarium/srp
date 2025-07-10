void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Slots::Pair>::DestructArray(
        Scaleform::GFx::AS3::Slots::Pair *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Slots::Pair *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v2->Value);
      pObject = v2->Key.pObject;
      if ( v2->Key.pObject )
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
